#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

typedef struct Node{
	BiTree date;
	struct Node *next;
} Queue;

typedef struct SNode {
	BiTree date;
	struct SNode *next;
} Stack;

int isNum(char c);                                   // check if a char is a number
Status Traverse(TElemType a);                        // visit the char
double cal(double a, double b, char c);              // cal the result
int make_num(char a);                                // let a char became a number
void error(void);                                    // make the exp_error became true
void menu(void); 

int IsEmpty(Queue *Q);                               // the queue
BiTree DeQueue(Queue *Q);
void EnQueue(Queue *Q, BiTree Element);

Stack *CreatStack(void);                             // the stack
void Pop(Stack *S);
void Push(Stack *S, BiTree Element);
BiTree Top(Stack *S);
int StackIsEmpty(Stack *S);

Status InOrderTraverse_cycle(BiTree T, Status (*visit)(TElemType e));    // the cycle traverse

int expression_error = 0;                            // if the exp is wrong

int main()
{
    menu();
    return 0;
}

void menu()
{
    char a[100]; double result;
    while (1)
    {
        puts("输入一个前缀表达式(输入 q 结束)(例子:+3*34)");
        gets(a);
        if (a[0] == 'q')
            break;
        BiTree T;
        InitBiTree(&T);		//初始化一棵树 
        reset();
        CreateBiTree(&T, a);
        result = Value(T);
        if (expression_error)
        {
            puts("表达式错误");
            return ;
        }
        else
            printf("结果为： %.2f\n\n", result);
        puts("先序遍历二叉树T结果为：");
        PreOrderTraverse(T, Traverse);
        puts("\n");
        puts("中序遍历二叉树T结果为：");
        InOrderTraverse(T, Traverse);
        puts("\n");
        puts("后序遍历二叉树T结果为：");
        PostOrderTraverse(T, Traverse);
        puts("\n");
        puts("层序遍历二叉树T结果为：");
        LevelOrderTraverse(T, Traverse);
        puts("\n");
        puts("\n");
        DestroyBiTree(T);			//销毁该二叉树 
    }
}

int isNum(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return 0;
    return 1;
 }

Status Traverse(TElemType a)
{
    printf("%c ", a);
    return SUCCESS;
}

double cal(double a, double b, char c)
{
    double result = 0;
    switch (c)
    {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': result = a / b; break;
        default: error();
    }

    return result;
}

int make_num(char a)
{
    int result = 0;
    switch (a)
    {
        case '9' : result++;
        case '8' : result++;
        case '7' : result++;
        case '6' : result++;
        case '5' : result++;
        case '4' : result++;
        case '3' : result++;
        case '2' : result++;
        case '1' : result++;
        case '0' : break;
        default  : error();
    }
    return result;
}

void error(void)
{
    expression_error = 1;
}

int IsEmpty(Queue *Q)
{
	return Q->next == 0;
}

BiTree DeQueue(Queue *Q)
{
	Queue *Top;
	BiTree T;

	if (IsEmpty(Q))
		printf("\n队列为空\n");
	else
	{
		Top = Q->next;
		T = Q->next->date;
		Q->next = Q->next->next;
		free(Top);
	}

	return T;
}

void EnQueue(Queue *Q, BiTree Element)
{
	Queue *Rear = (Queue *) malloc (sizeof(Queue));

	if(Rear == 0)
		printf("\n入队错误\n");
	else
	{
		for (;Q->next;Q=Q->next);
		Rear->next = 0;
		Rear->date = Element;
		Q->next = Rear;
	}

	return ;
}

int StackIsEmpty(Stack *S)
{
	return S->next == 0;
}

void Pop(Stack *S)
{
    if (StackIsEmpty(S))
    {
        puts("出栈错误");
        return ;
    }

	Stack *Top;
    Top = S->next;
    S->next = S->next->next;
    free(Top);
}

void Push(Stack *S, BiTree Element)
{
	Stack *Top=(Stack *)malloc(sizeof(Stack));
    Top->date=Element;
    Top->next=S->next;
    S->next=Top;
}

BiTree Top(Stack *S)
{
    if (StackIsEmpty(S))
    {
        puts("ERROR in pop");
        return 0;
    }

	return S->next->date;
}

Status InOrderTraverse_cycle(BiTree T, Status (*visit)(TElemType e))
{
    Stack S;
    S.next = 0;
    while (T || !StackIsEmpty(&S))
    {
        while (T)
        {
            Push(&S, T);
            T = T->lchild;
        }
        while (!StackIsEmpty(&S))
        {
            T = Top(&S);
            visit(T->data);
            Pop(&S);
            T = T->rchild;
        }
    }
}

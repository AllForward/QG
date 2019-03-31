#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(!s->top){
		printf("申请空间失败!\n");	 
        return ERROR;}
    s->top=NULL;
    s->count=0;
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
	if (s->count==0)
        return SUCCESS;
    else return ERROR;
}
Status getTopLStack(LinkStack *s,ElemType *e)  //得到栈顶元素
{
	if (s->top==NULL)
        return ERROR;
    else
        *e=s->top->data;
    return SUCCESS;
}
Status clearLStack(LinkStack *s)   //清空栈
{
	LinkStackPtr p,q;
    p=s->top;
    while(p)
    {  
        q=p;
        p=p->next;
        free(q);
    } 
    s->top=NULL;
    s->count=0;
    return SUCCESS;
}
Status destroyLStack(LinkStack *s)   //销毁栈
{
	clearLStack(s);
	free(s);
	return SUCCESS;
} 
Status LStackLength(LinkStack *s,int *length)    //检测栈长度
{
	*length=s->count;
	return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data)   //入栈
{
	LinkStackPtr k=(LinkStackPtr)malloc(sizeof(StackNode)); 
    k->data=data; 
    k->next=s->top;    /* 把当前的栈顶元素赋值给新结点的直接后继*/
    s->top=k;         /* 将新的结点s赋值给栈顶指针*/
    s->count++;
    return SUCCESS;
}
Status popLStack(LinkStack *s,ElemType *data)   //出栈
{
	LinkStackPtr p;
    if(isEmptyLStack(s))
       	return ERROR;
    *data=s->top->data;
    p=s->top;                    /* 将栈顶结点赋值给p*/
    s->top=s->top->next;    /* 使得栈顶指针下移一位，指向后一结点 */
    free(p);                    /* 释放结点p */        
    s->count--;
    return SUCCESS;
}
Status LStackPrint(LinkStack *s)  //打印栈中元素 
{
    LinkStackPtr p;
    p=s->top;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    return SUCCESS;
}

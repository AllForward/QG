#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"stack.h"

//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化栈
{
	s->elem = (ElemType*)malloc(sizes * sizeof(ElemType));
	if(s->elem == NULL){
		printf("申请空间失败!\n");	
		return ERROR;
	}
	s->size = sizes;
	s->top = -1;
	return SUCCESS;
}
Status isEmptyStack(SqStack *s)   //判断栈是否为空
{
	if(s->top == -1){
		printf("栈空!\n");
		return SUCCESS;
	}
	else return ERROR;
}
Status getTopStack(SqStack *s,ElemType *e)   //得到栈顶元素
{
	if( isEmptyStack(s) == 0 ){
		*e = s->elem[s->top];
		return SUCCESS;}
	else return ERROR;	
}
Status clearStack(SqStack *s)   //清空栈
{
	s->top = -1;
	return SUCCESS;
}
Status destroyStack(SqStack *s)  //销毁栈
{
	free(s->elem);
	return SUCCESS;
}
Status stackLength(SqStack *s,int *length)   //检测栈
{
	if(isEmptyStack(s) == SUCCESS)
		return ERROR;
	else {
		int i=0;
		while(i < s->top)i++;
		*length = i+1;
		printf("栈的长度为:%d\n",*length);	
		return SUCCESS;
	}	 
}
Status pushStack(SqStack *s,ElemType data)  //入栈
{
	if(s->top==s->size-1){
		printf("栈已满!\n");
		return ERROR;
	}
	else {
		s->elem[++s->top]=data;
		return SUCCESS;
	}
}
Status popStack(SqStack *s,ElemType *data)   //出栈
{
	*data=s->elem[(s->top)--];
	return SUCCESS;
}
Status StackPrint(SqStack *s)  //打印栈中元素 
{
	int p = s->top;
	printf("栈中元素依次为:\n");
    while(p >= 0)
    {
        printf("%d ",s->elem[p--]);
    }
    printf("\n");
    return SUCCESS;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"stack.h"

//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ��ջ
{
	s->elem = (ElemType*)malloc(sizes * sizeof(ElemType));
	if(s->elem == NULL){
		printf("����ռ�ʧ��!\n");	
		return ERROR;
	}
	s->size = sizes;
	s->top = -1;
	return SUCCESS;
}
Status isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
	if(s->top == -1){
		printf("ջ��!\n");
		return SUCCESS;
	}
	else return ERROR;
}
Status getTopStack(SqStack *s,ElemType *e)   //�õ�ջ��Ԫ��
{
	if( isEmptyStack(s) == 0 ){
		*e = s->elem[s->top];
		return SUCCESS;}
	else return ERROR;	
}
Status clearStack(SqStack *s)   //���ջ
{
	s->top = -1;
	return SUCCESS;
}
Status destroyStack(SqStack *s)  //����ջ
{
	free(s->elem);
	return SUCCESS;
}
Status stackLength(SqStack *s,int *length)   //���ջ
{
	if(isEmptyStack(s) == SUCCESS)
		return ERROR;
	else {
		int i=0;
		while(i < s->top)i++;
		*length = i+1;
		printf("ջ�ĳ���Ϊ:%d\n",*length);	
		return SUCCESS;
	}	 
}
Status pushStack(SqStack *s,ElemType data)  //��ջ
{
	if(s->top==s->size-1){
		printf("ջ����!\n");
		return ERROR;
	}
	else {
		s->elem[++s->top]=data;
		return SUCCESS;
	}
}
Status popStack(SqStack *s,ElemType *data)   //��ջ
{
	*data=s->elem[(s->top)--];
	return SUCCESS;
}
Status StackPrint(SqStack *s)  //��ӡջ��Ԫ�� 
{
	int p = s->top;
	printf("ջ��Ԫ������Ϊ:\n");
    while(p >= 0)
    {
        printf("%d ",s->elem[p--]);
    }
    printf("\n");
    return SUCCESS;
}

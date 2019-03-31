#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(!s->top){
		printf("����ռ�ʧ��!\n");	 
        return ERROR;}
    s->top=NULL;
    s->count=0;
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)  //�ж���ջ�Ƿ�Ϊ��
{
	if (s->count==0)
        return SUCCESS;
    else return ERROR;
}
Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�ջ��Ԫ��
{
	if (s->top==NULL)
        return ERROR;
    else
        *e=s->top->data;
    return SUCCESS;
}
Status clearLStack(LinkStack *s)   //���ջ
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
Status destroyLStack(LinkStack *s)   //����ջ
{
	clearLStack(s);
	free(s);
	return SUCCESS;
} 
Status LStackLength(LinkStack *s,int *length)    //���ջ����
{
	*length=s->count;
	return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data)   //��ջ
{
	LinkStackPtr k=(LinkStackPtr)malloc(sizeof(StackNode)); 
    k->data=data; 
    k->next=s->top;    /* �ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ��*/
    s->top=k;         /* ���µĽ��s��ֵ��ջ��ָ��*/
    s->count++;
    return SUCCESS;
}
Status popLStack(LinkStack *s,ElemType *data)   //��ջ
{
	LinkStackPtr p;
    if(isEmptyLStack(s))
       	return ERROR;
    *data=s->top->data;
    p=s->top;                    /* ��ջ����㸳ֵ��p*/
    s->top=s->top->next;    /* ʹ��ջ��ָ������һλ��ָ���һ��� */
    free(p);                    /* �ͷŽ��p */        
    s->count--;
    return SUCCESS;
}
Status LStackPrint(LinkStack *s)  //��ӡջ��Ԫ�� 
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

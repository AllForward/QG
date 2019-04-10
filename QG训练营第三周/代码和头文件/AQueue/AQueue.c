#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"AQueue.h"


extern int GetSize(char type);
extern char GetType(void);
int key;				//��ӡԪ��ʱ�� 

void InitAQueue(AQueue *Q)
{
	Q->length = 0;
	Q->front = 0;		//������ȫ����Ϊ0 
	Q->rear = 0;	
} 

void DestoryAQueue(AQueue *Q)
{
	int i = 0;
	for(; i < Q->length; i++)
		free(Q->data[i]);		
} 

Status IsFullAQueue(const AQueue *Q)
{
	if(Q->front == (Q->rear + 1) % MAXQUEUE){	//��ʱ˵���������� 
		return TRUE;
	}
	else return FALSE;
} 

Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q->length == 0){
		printf("����Ϊ�գ�\n"); 
		return FALSE;
	}
	else return TRUE;
}

Status GetHeadAQueue(AQueue *Q, void *e)
{
	if (!IsEmptyAQueue(Q)){
		return FALSE;	
	}
    if (datatype[Q->front] != 'S')
        memcpy(e, Q->data[Q->front], GetSize(datatype[Q->front]));
    // �����ַ�������� 
    else
    {
        char *s = (char *)e;
        int len = strlen(s) + 1;
        memcpy(e, Q->data[Q->front], len);
    }
    return TRUE;
}

int LengthAQueue(AQueue *Q)
{
	return Q->length;
}

void ClearAQueue(AQueue *Q)
{
	Q->length = 0;
	Q->front = 0;
	Q->rear = 0;
}

Status EnAQueue(AQueue *Q, void *data)	//���
{
	if(IsFullAQueue(Q) == TRUE){
		printf("��������!\n");
		return FALSE;
	}	
	else{
		Q->length++;
    	if (type != 'S')
   		{
        	Q->data[Q->rear] = malloc(GetSize(type));
        	memcpy(Q->data[Q->rear], data, GetSize(type));
    	}
    // ����Ϊ�ַ�������� 
    	else
    	{
        	char *s = (char *)data;
        	int len = strlen(s) + 1;
        	Q->data[Q->rear] = malloc(len);
        	memcpy(Q->data[Q->rear], data, len);
    	}
    	datatype[Q->rear] = type;
    	Q->rear = (Q->rear + 1) % MAXQUEUE;
    	return TRUE;
	}
} 

Status DeAQueue(AQueue *Q)		//���� 
{
	if(IsEmptyAQueue(Q) == TRUE){
		free(Q->data[Q->front]);
		Q->front = (Q->front + 1) % MAXQUEUE;//����+1 
		Q->length--;
		return TRUE;
	}	
	else return FALSE;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))	//�������� 
{
	if(Q->length == 0){
		printf("����Ϊ�գ�\n");
		return FALSE;
	}
	else {
		int i = Q->front;
		printf("�����е����ݷֱ�Ϊ��\n");
		for(; i < Q->length + Q->front; i++ ){
			key = i % MAXQUEUE;
			foo(Q->data[i % MAXQUEUE]);
		}	
		return TRUE;
	}
}

void APrint(void *q)					//��ӡ��������Ԫ�� 
{
	int *Icopy; float *Fcopy; char *Ccopy;
    switch (datatype[key])
    {
        case 'I':   Icopy = (int *)q;   printf("%d->", *Icopy); break;

        case 'F':   Fcopy = (float *)q; printf("%.2f->", *Fcopy);  break;

        case 'C':   Ccopy = (char *)q;  printf("%c->", *Ccopy); break;

        case 'S':   Ccopy = (char *)q;  printf("%s->", Ccopy); break;

        default:    printf("����\n");
    }
}







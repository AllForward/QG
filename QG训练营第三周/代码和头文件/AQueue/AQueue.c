#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"AQueue.h"


extern int GetSize(char type);
extern char GetType(void);
int key;				//打印元素时用 

void InitAQueue(AQueue *Q)
{
	Q->length = 0;
	Q->front = 0;		//将数据全都置为0 
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
	if(Q->front == (Q->rear + 1) % MAXQUEUE){	//此时说明队列已满 
		return TRUE;
	}
	else return FALSE;
} 

Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q->length == 0){
		printf("队列为空！\n"); 
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
    // 处理字符串的情况 
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

Status EnAQueue(AQueue *Q, void *data)	//入队
{
	if(IsFullAQueue(Q) == TRUE){
		printf("队列已满!\n");
		return FALSE;
	}	
	else{
		Q->length++;
    	if (type != 'S')
   		{
        	Q->data[Q->rear] = malloc(GetSize(type));
        	memcpy(Q->data[Q->rear], data, GetSize(type));
    	}
    // 以下为字符串的情况 
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

Status DeAQueue(AQueue *Q)		//出队 
{
	if(IsEmptyAQueue(Q) == TRUE){
		free(Q->data[Q->front]);
		Q->front = (Q->front + 1) % MAXQUEUE;//队首+1 
		Q->length--;
		return TRUE;
	}	
	else return FALSE;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))	//遍历队列 
{
	if(Q->length == 0){
		printf("队列为空！\n");
		return FALSE;
	}
	else {
		int i = Q->front;
		printf("队列中的数据分别为：\n");
		for(; i < Q->length + Q->front; i++ ){
			key = i % MAXQUEUE;
			foo(Q->data[i % MAXQUEUE]);
		}	
		return TRUE;
	}
}

void APrint(void *q)					//打印单个队列元素 
{
	int *Icopy; float *Fcopy; char *Ccopy;
    switch (datatype[key])
    {
        case 'I':   Icopy = (int *)q;   printf("%d->", *Icopy); break;

        case 'F':   Fcopy = (float *)q; printf("%.2f->", *Fcopy);  break;

        case 'C':   Ccopy = (char *)q;  printf("%c->", *Ccopy); break;

        case 'S':   Ccopy = (char *)q;  printf("%s->", Ccopy); break;

        default:    printf("错误！\n");
    }
}







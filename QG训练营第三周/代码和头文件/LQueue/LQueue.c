#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LQueue.h"

extern int GetSize(char type);
extern char GetType(void);
int loc;					//用于指定数组datatype中队首的位置 
void InitLQueue(LQueue *Q){
	
	Q->front = NULL;
	
	Q->rear = NULL;
	
	Q->length = 0;
}

void DestoryLQueue(LQueue *Q){
	if(Q->length != 0)
		ClearLQueue(Q);
}

Status IsEmptyLQueue(const LQueue *Q){
	if(Q->length == 0){
		printf("队列为空！\n"); 
		return FALSE;
	}
	else return TRUE;	
}

Status GetHeadLQueue(LQueue *Q, void *e){
	if (!IsEmptyLQueue(Q)){
		return FALSE;	
	}
	int i;
	for(i = 0;i < 20; i++)
		if(datatype[i] != '0')
			break;
    if (datatype[i] != 'S')
        memcpy(e, Q->front->data, GetSize(datatype[i]));
    // 处理字符串的情况 
    else
    {
        char *s = (char *)e;
        int len = strlen(s) + 1;
        memcpy(e, Q->front->data, len);
    }
    return TRUE;
}

int LengthLQueue(LQueue *Q){
	return Q->length;
}

Status EnLQueue(LQueue *Q, void *data){
	
	if( Q->rear == NULL){
		Q->front = Q->rear = (Node *)malloc( sizeof( Node));
	}
	else {
		Node *target;
		target = (Node *)malloc( sizeof(Node));
		Q->rear->next = target;
		Q->rear = target;
	}
	Q->rear->next = NULL;
	Q->length ++;
    if (type != 'S')
   	{
      	Q->rear->data = malloc(GetSize(type));
       	memcpy(Q->rear->data, data, GetSize(type));
   	}
    // 以下为字符串的情况 
   	else
   	{
       	char *s = (char *)data;
       	int len = strlen(s) + 1;
       	Q->rear->data = malloc(len);
       	memcpy(Q->rear->data, data, len);
   	}
   	return TRUE;
}

Status DeLQueue(LQueue *Q){
	if(IsEmptyLQueue(Q) == TRUE){
		Node *target = Q->front;
		Q->front = Q->front->next;			//队首指向后面结点 
		free(target->data);
		free(target);
		Q->length--;
		return TRUE;
	}	
	else return FALSE;
}

void ClearLQueue(LQueue *Q){

	Node *temp = Q->front->next;
	Node *pcup;
	while(temp != NULL){
		pcup = temp;
		temp = temp->next;
		free(pcup);
	}
	Q->front=Q->rear=NULL;
	Q->length = 0;
	int z = 29;
	while(z >= 0 ){
		datatype[z] = '0';
		z--;
	}
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	int i;
	for(i = 0;i < 20; i++)
		if(datatype[i] != '0')
			break;
	loc = i;		
	if(Q->length == 0){
		printf("队列为空！\n");
		return FALSE;
	}
	else {
		Node *p = Q->front;
		printf("队列中的数据分别为：\n");
		while(p) {
			foo(p->data);
			p = p->next;
			loc++;
		}	
		return TRUE;
	}
	loc = i;							//重新指向原来的队首 
}

void LPrint(void *q){
	int *Icopy; float *Fcopy; char *Ccopy;
    switch (datatype[loc])
    {
        case 'I':   Icopy = (int *)q;   printf("%d->", *Icopy); break;

        case 'F':   Fcopy = (float *)q; printf("%.2f->", *Fcopy);  break;

        case 'C':   Ccopy = (char *)q;  printf("%c->", *Ccopy); break;

        case 'S':   Ccopy = (char *)q;  printf("%s->", Ccopy); break;

        default:    printf("错误！\n");
    }
}





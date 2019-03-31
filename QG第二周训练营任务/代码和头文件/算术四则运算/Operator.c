#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#define Yes 1
#define error 0
/* stack structure */
typedef struct StackNode
{
        double data;
        char sign;
        struct StackNode *next;
}StackNode,*LinkStackPtr;
typedef struct
{
        LinkStackPtr top;
        int count;
}LinkStack;
int visit(double c)
{
        printf("%f ",c);
        return Yes;
}
void welcome()
{
	printf("-------------------------------------\n");
	printf("*************************************\n");
	printf("~~~~~~~~~~~~��ӭʹ�ü�����~~~~~~~~~~~\n");
	printf("\t    0.�˳�\n");
	printf("\t    1.��ʼ����\n");
	printf("*************************************\n");	
	printf("-------------------------------------\n");
} 
/* ����һ����ջ*/
int InitStack(LinkStack *S)
{ 
        S->top = (LinkStackPtr)malloc(sizeof(StackNode));
        if(!S->top)
                return error;
        S->top=NULL;
        S->count=0;
        return Yes;
}
/* ���ջ */
int ClearStack(LinkStack *S)
{ 
        LinkStackPtr p,q;
        p=S->top;
        while(p)
        {  
                q=p;
                p=p->next;
                free(q);
        } 
        S->count=0;
        return Yes;
}
/*����ջ*/
int ClearallStack(LinkStack *S)
{
	ClearStack(S);
	free(S);
	return Yes;
} 
/* ջ�գ�return Yes������ return error */
int StackEmpty(LinkStack *S)
{ 
        if (S->count==0)
            return Yes;
        else
            return error;
}
/* ����ջ�ĳ��� */
int StackLength(LinkStack *S)
{ 
    return S->count;
}
/* ջ����,return ջ��Ԫ�غ� return Yes������ return error */
int GetTopnum(LinkStack *S)
{
        if (S->top==NULL)
            return error;
        else
            return S->top->data;
}
int GetTopsign(LinkStack *S)
{
	if (S->top==NULL)
        return error;
    else
        return S->top->sign;
}
/*  ������Ԫ�ص�ջ�� */
int Pushnum(LinkStack *S,double e)	//�嵽�洢���ֵ�ջ 
{
        LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
        s->data=e; 
        s->next=S->top;    /* �ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ��*/
        S->top=s;         /* ���µĽ��s��ֵ��ջ��ָ��*/
        S->count++;
        return Yes;
}
int Pushsign(LinkStack *S,char e)	//�嵽�洢���ŵ�ջ 
{
		LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
        s->sign=e; 
        s->next=S->top;    /* �ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ��*/
        S->top=s;         /* ���µĽ��s��ֵ��ջ��ָ��*/
        S->count++;
        return Yes;
}
/* ջ����,ɾ��ջ������,returnջ��Ԫ�غ�return Yes������return error  */
double Popnum(LinkStack *S)	//�����洢���ֵ�ջ 
{ 
		double e;
        LinkStackPtr p;
        if(StackEmpty(S))
                return error;        
        p=S->top;            
		e=p->data;       
        S->top=S->top->next;   
        free(p);                    
        S->count--;
        return e;
}
char Popsign(LinkStack *S)	//�����洢���ŵ�ջ 
{
		char e;
        LinkStackPtr p;
        if(StackEmpty(S))
                return error;        
        p=S->top;            
		e=p->sign;       
        S->top=S->top->next;   
        free(p);                    
        S->count--;
        return e;
}
int StackPrint(LinkStack *S)
{
        LinkStackPtr p;
        p=S->top;
        while(p)
        {
            visit(p->data);
            p=p->next;
        }
        printf("\n");
        return Yes;
}
int Priority(char s)		//�ж�����������ȼ� 
{
	switch(s)
	{
		case '(':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;			
	}
}
int Judgecircle(int len,char *circle)		//�ж�������������ʽ�Ƿ���ȷ 
{
	int i;
    int t;
    int acc=0,bcc=0;
    if(circle[0]=='.'||circle[len-1]=='=')return 1;
    if((circle[0]<48||circle[0]>57)&&circle[0]!='-')
    		return 1;
    for(i=0;i<len-1;i++){ 
		if((circle[i]<48||circle[i]>57)&&(circle[i]!='+'&&circle[i]!='-'&&circle[i]!='*'&&circle[i]!='/'&&
			circle[i]!='('&&circle[i]!=')'&&circle[i]!='.'))
			return 1;      
		if(circle[i]=='+'||circle[i]=='-'||circle[i]=='*'||circle[i]=='/'){   
			if(circle[i+1]=='+'||circle[i+1]=='-'||circle[i+1]=='*'||circle[i+1]=='/')                
			return 1;}
		else if(circle[i]==')'){            
			if(circle[i+1]=='(')              
				return 1;}        
		else if(circle[i]=='('){            
			if(circle[i+1]==')')                
				return 1;}	
	}
	if(circle[len-1]=='+'||circle[len-1]=='-'||circle[len-1]=='*'||circle[len-1]=='/')  
		return 1;    
	for(i=len-1;i>=0;i--){        
		if(circle[i]==')')            
			bcc++;        
		else if(circle[i]=='(')  
			acc++;}
	if(acc!=bcc){
        return 1;
    }
	char pei[100];
    int toppei=-1;
    i=0;	
	while(i<len){
        if(circle[i]=='('){
            toppei++;
            pei[toppei]=circle[i];
            i++;
        }
		else if(circle[i]==')'&&toppei>=0){
            toppei--;
            i++;
        }	
		else if(circle[i]==')'&&toppei==-1)
            return 1;
         else i++;
    }    
    if(toppei!=-1)
        return 1;   
    return 0;
}	
int main()
{
	LinkStack num,sign;	
	char choice[50];
	int i = 0, k = 0, z = 0, n = 1,len,t = 1;		//n�����жϳ����Ƿ����ִ�У�k���ڼ�¼double������ 
	double j = 0, result, s1, s2;								//z���ڼ�¼change���飻 i���ڼ�¼circle���� 
	if( InitStack( &num ) != Yes || InitStack( &sign ) != Yes){
		printf("����ռ�ʧ��!\n");
		exit(0);
	}
	welcome();
	while(t){
	printf("����Ҫִ�е�ѡ��:");	
	scanf("%s",choice);
	if(strcmp(choice,"0")==0){
		printf("^_^��л����ʹ��!^_^\n");
		t = 0;		
	}
	else if(strcmp(choice,"1")==0){
		while(n)//�������� 
		{
			system("cls");
			char circle[100];
			char change[100];//change���ڽ�ȡ�ַ����е����� ,choice�����û�ѡ���Ƿ���м��� 
			double dig[100] = {0};             //���ڴ洢ת����ȡ���� 
			ClearStack(&sign);
			ClearStack(&num);
			printf("�������������ʽ:(��ʽ:(8+2*3)/2)\n");
			scanf("%s",circle);
			len=strlen(circle);
			if(Judgecircle(len,circle)==0){
				for(; circle[i] ; i++){					//���ַ����е�����ת����double�� 
			 			if(isdigit(circle[i]) || circle[i] == '.'){
						change[z++] = circle[i];
						if(!isdigit( circle[i+1]) && circle[i+1] != '.'){
							dig[k++] = atof(change);
							for(z = 0; z < 10; z++)
								change[z] = 0;
								z = 0;				
							}
						}
					}
				i = 0, k = 0;					
				while( circle[i] != '\0' || StackEmpty( &sign ) != Yes)
				{
					if( circle[i] >= 48 && circle[i] <= 57 && circle[i+1] == '\0'){
						Pushnum( &num,dig[k]);
						i++;
					}
					if( circle[i] >= 48 && circle[i] <= 57)
					{
						i++;
						if((circle[i]<48||circle[i]>57)&&circle[i]!='.')
						{
							Pushnum( &num, dig[k++] );
						}
					}
			
					else if( circle[i] == '.')	
						i++;
					
					else {
						 if((circle[i-1]=='('&&circle[i]=='-')||(i==0&&circle[i]=='-'))
						 	Pushnum(&num,0);
						 if(Priority(circle[i]) > Priority(GetTopsign(&sign))
						 ||StackEmpty(&sign)==Yes||(GetTopsign(&sign)=='('&&circle[i]!=')'))
						 {
							Pushsign(&sign,circle[i]);
							i++;
							continue;
						 } 
						if(GetTopsign(&sign)=='('&&circle[i]==')')
						{
							Popsign(&sign);
							i++;
							continue;
						}
						if(Priority(circle[i])<=Priority(GetTopsign(&sign))
						||(GetTopsign(&sign)!='('&&circle[i]==')')||(circle[i]=='\0'&&StackEmpty(&sign)!=Yes))
						{
							switch(Popsign(&sign))
							{
								case '+':
									Pushnum(&num,Popnum(&num)+Popnum(&num));
									break;
								case '-':
									j=Popnum(&num);
									Pushnum(&num,Popnum(&num)-j);
									break;
								case '*':
									Pushnum(&num,Popnum(&num)*Popnum(&num));
									break;
								case '/':
									j=Popnum(&num);
									Pushnum(&num,Popnum(&num)/j);	
							}
								continue;
						}
					}
				}
				result = Popnum(&num);
				printf("%s=%f\n",circle,result); 
				printf("\n");
			}
			else printf("������������ʽ����!\n");
			printf("�Ƿ��������:1 or 0\n");
			scanf("%s",choice);
				if(strcmp(choice,"0")==0){
					printf("^_^��л����ʹ��!^_^\n");
					ClearallStack(&num);
					ClearallStack(&sign);	
					n = 0;
				}
				else if(strcmp(choice,"1")==0){
					n = 1,z = i = k = 0;
				}
				else {
					int q = 1;		//�ж��Ƿ�������ȷ 
					while(q){
						printf("�������!����������!\n");
						scanf("%s",choice);
						if(strcmp(choice,"0")==0){
						printf("^_^��л����ʹ��!^_^\n");	
						q = 0,n = 0;
						}
						else if(strcmp(choice,"1")==0){
							n = 1,z = i = k = 0;
							break;	
						}
						else q = 1;	
					}
				}	
		}
		t = 0;
	}
	else{
		system("cls");
		printf("�������!����������ִ��ѡ��!\n");
		printf("\n");
		t = 1;
	}
}
	return 0;
}


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
	printf("~~~~~~~~~~~~欢迎使用计算器~~~~~~~~~~~\n");
	printf("\t    0.退出\n");
	printf("\t    1.开始计算\n");
	printf("*************************************\n");	
	printf("-------------------------------------\n");
} 
/* 创建一个空栈*/
int InitStack(LinkStack *S)
{ 
        S->top = (LinkStackPtr)malloc(sizeof(StackNode));
        if(!S->top)
                return error;
        S->top=NULL;
        S->count=0;
        return Yes;
}
/* 清除栈 */
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
/*销毁栈*/
int ClearallStack(LinkStack *S)
{
	ClearStack(S);
	free(S);
	return Yes;
} 
/* 栈空，return Yes，否则 return error */
int StackEmpty(LinkStack *S)
{ 
        if (S->count==0)
            return Yes;
        else
            return error;
}
/* 返回栈的长度 */
int StackLength(LinkStack *S)
{ 
    return S->count;
}
/* 栈不空,return 栈顶元素和 return Yes；否则 return error */
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
/*  插入新元素到栈顶 */
int Pushnum(LinkStack *S,double e)	//插到存储数字的栈 
{
        LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
        s->data=e; 
        s->next=S->top;    /* 把当前的栈顶元素赋值给新结点的直接后继*/
        S->top=s;         /* 将新的结点s赋值给栈顶指针*/
        S->count++;
        return Yes;
}
int Pushsign(LinkStack *S,char e)	//插到存储符号的栈 
{
		LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
        s->sign=e; 
        s->next=S->top;    /* 把当前的栈顶元素赋值给新结点的直接后继*/
        S->top=s;         /* 将新的结点s赋值给栈顶指针*/
        S->count++;
        return Yes;
}
/* 栈不空,删除栈顶数据,return栈顶元素和return Yes；否则return error  */
double Popnum(LinkStack *S)	//弹出存储数字的栈 
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
char Popsign(LinkStack *S)	//弹出存储符号的栈 
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
int Priority(char s)		//判断运算符的优先级 
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
int Judgecircle(int len,char *circle)		//判断输入的算术表达式是否正确 
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
	int i = 0, k = 0, z = 0, n = 1,len,t = 1;		//n用于判断程序是否继续执行；k用于记录double型数组 
	double j = 0, result, s1, s2;								//z用于记录change数组； i用于记录circle数组 
	if( InitStack( &num ) != Yes || InitStack( &sign ) != Yes){
		printf("申请空间失败!\n");
		exit(0);
	}
	welcome();
	while(t){
	printf("输入要执行的选项:");	
	scanf("%s",choice);
	if(strcmp(choice,"0")==0){
		printf("^_^感谢您的使用!^_^\n");
		t = 0;		
	}
	else if(strcmp(choice,"1")==0){
		while(n)//继续计算 
		{
			system("cls");
			char circle[100];
			char change[100];//change用于截取字符串中的数字 ,choice用于用户选择是否进行计算 
			double dig[100] = {0};             //用于存储转换截取数据 
			ClearStack(&sign);
			ClearStack(&num);
			printf("请输入算术表达式:(格式:(8+2*3)/2)\n");
			scanf("%s",circle);
			len=strlen(circle);
			if(Judgecircle(len,circle)==0){
				for(; circle[i] ; i++){					//将字符串中的数字转换成double型 
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
			else printf("输入的算术表达式错误!\n");
			printf("是否继续运算:1 or 0\n");
			scanf("%s",choice);
				if(strcmp(choice,"0")==0){
					printf("^_^感谢您的使用!^_^\n");
					ClearallStack(&num);
					ClearallStack(&sign);	
					n = 0;
				}
				else if(strcmp(choice,"1")==0){
					n = 1,z = i = k = 0;
				}
				else {
					int q = 1;		//判断是否输入正确 
					while(q){
						printf("输入错误!请重新输入!\n");
						scanf("%s",choice);
						if(strcmp(choice,"0")==0){
						printf("^_^感谢您的使用!^_^\n");	
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
		printf("输入错误!请重新输入执行选项!\n");
		printf("\n");
		t = 1;
	}
}
	return 0;
}


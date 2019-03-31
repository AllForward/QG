#include<stdio.h>    
#include<stdlib.h>
#include<stdlib.h>
#include"stack.h" 
#define Maxsize 20
int main()
{
	int j,n,d,e,k = 0,length,size = Maxsize;//k用于记录栈是否初始化 
    char flag[100];
    SqStack *s = (SqStack*)malloc(sizeof(SqStack));
    printf("\n");
    while(1){
    	printf("|=============栈的功能菜单==============|\n");
    	printf("|=============0.结束任务================|\n");
    	printf("|=============1.对栈进行初始============|\n");    
    	printf("|=============2.压栈====================|\n");
    	printf("|=============3.弹栈====================|\n");
   	 	printf("|=============4.获取栈顶元素============|\n");
    	printf("|=============5.获取栈的长度============|\n");
   	 	printf("|=============6.销毁栈==================|\n");
    	printf("|=============7.清空栈==================|\n");
    	printf("|=============8.打印栈中元素============|\n");
		printf("选择要执行的选项：");
		scanf("%s",&flag);	
		if(strcmp(flag,"0")==0)break;	
		else if(strcmp(flag,"1")==0){
			system("cls");
			if(k==0&&initStack(s,size)==SUCCESS){
				k=1;
				printf("栈初始化成功!\n");
			}
			else if(k==1){
				printf("您已经对栈初始化!\n");	
			}
			printf("\n");
		}
       	else if(strcmp(flag,"2")==0){
       		system("cls");
       		if(k==0) 
			   printf("请先对栈初始化!\n"); 
			else if(k==1)  
			{
				int z=0,l=0;
        		printf("要压栈的元素个数为：");
				z=scanf("%d",&n);
				if(z==1&&n>0){
					printf("输入压栈的元素：(格式:24 23)"); 
                		while(n--){
                			l=scanf("%d",&j);
                			if(l==1){
                				pushStack(s,j);
                				l=0;}
                			else {
                				printf("输入错误!\n");
                				break;
							}		
						}
        			StackPrint(s);	
              	}
              	else printf("输入错误!\n");
              	
            }
            printf("\n");
    	}
       	else if(strcmp(flag,"3")==0){
       		system("cls");
       		if(k==0) 
			   printf("请先对栈初始化!\n");
			else if(k==1){
				d=isEmptyStack(s);
        		if(d==ERROR){ 
        			popStack(s,&e);
        			printf("弹出数据成功,弹出的栈顶元素 e=%d\n",e);
				}
        	}
        	printf("\n");
		} 
		else if(strcmp(flag,"4")==0){
			system("cls");
			if(k==0) 
			   printf("请先对栈初始化!\n"); 
			else if(k==1){
				d=isEmptyStack(s);
				if(d==ERROR) {
					getTopStack(s,&e);
					printf("栈顶元素为：%d\n",e);
				}
			}
			printf("\n");
		}
		else if(strcmp(flag,"5")==0){
			system("cls");
			if(k==0) 
			   printf("请先对栈初始化!\n"); 
			else{
				d=isEmptyStack(s);
				if(d==ERROR){
					stackLength(s,&length);}
				}
			printf("\n");	
		}
		else if(strcmp(flag,"6")==0){
			system("cls");
			if(k==0) 
			   printf("栈不存在!\n"); 
			else if(k==1){
				destroyStack(s);
				printf("栈已销毁！\n");
				k=0;
			}
			printf("\n");
		}
		else if(strcmp(flag,"7")==0){
			system("cls");
			if(k==0) 
			   printf("请先对栈初始化!\n"); 
			else if(k==1){
			d=isEmptyStack(s);
			if(d==ERROR){
				clearStack(s);
				printf("栈已清空！\n");
				}
			}
			printf("\n");	
		}   
		else if(strcmp(flag,"8")==0){
			system("cls");
			if(k==0) 
			   printf("请先对栈初始化!\n");
			else if(k==1){
				if(isEmptyStack(s)==ERROR)
					StackPrint(s);
				}
			printf("\n");		
		}
		else {
			system("cls");
			printf("输入错误!\n");
			printf("\n");
		}
	}
        return 0;
}


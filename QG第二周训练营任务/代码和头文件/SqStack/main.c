#include<stdio.h>    
#include<stdlib.h>
#include<stdlib.h>
#include"stack.h" 
#define Maxsize 20
int main()
{
	int j,n,d,e,k = 0,length,size = Maxsize;//k���ڼ�¼ջ�Ƿ��ʼ�� 
    char flag[100];
    SqStack *s = (SqStack*)malloc(sizeof(SqStack));
    printf("\n");
    while(1){
    	printf("|=============ջ�Ĺ��ܲ˵�==============|\n");
    	printf("|=============0.��������================|\n");
    	printf("|=============1.��ջ���г�ʼ============|\n");    
    	printf("|=============2.ѹջ====================|\n");
    	printf("|=============3.��ջ====================|\n");
   	 	printf("|=============4.��ȡջ��Ԫ��============|\n");
    	printf("|=============5.��ȡջ�ĳ���============|\n");
   	 	printf("|=============6.����ջ==================|\n");
    	printf("|=============7.���ջ==================|\n");
    	printf("|=============8.��ӡջ��Ԫ��============|\n");
		printf("ѡ��Ҫִ�е�ѡ�");
		scanf("%s",&flag);	
		if(strcmp(flag,"0")==0)break;	
		else if(strcmp(flag,"1")==0){
			system("cls");
			if(k==0&&initStack(s,size)==SUCCESS){
				k=1;
				printf("ջ��ʼ���ɹ�!\n");
			}
			else if(k==1){
				printf("���Ѿ���ջ��ʼ��!\n");	
			}
			printf("\n");
		}
       	else if(strcmp(flag,"2")==0){
       		system("cls");
       		if(k==0) 
			   printf("���ȶ�ջ��ʼ��!\n"); 
			else if(k==1)  
			{
				int z=0,l=0;
        		printf("Ҫѹջ��Ԫ�ظ���Ϊ��");
				z=scanf("%d",&n);
				if(z==1&&n>0){
					printf("����ѹջ��Ԫ�أ�(��ʽ:24 23)"); 
                		while(n--){
                			l=scanf("%d",&j);
                			if(l==1){
                				pushStack(s,j);
                				l=0;}
                			else {
                				printf("�������!\n");
                				break;
							}		
						}
        			StackPrint(s);	
              	}
              	else printf("�������!\n");
              	
            }
            printf("\n");
    	}
       	else if(strcmp(flag,"3")==0){
       		system("cls");
       		if(k==0) 
			   printf("���ȶ�ջ��ʼ��!\n");
			else if(k==1){
				d=isEmptyStack(s);
        		if(d==ERROR){ 
        			popStack(s,&e);
        			printf("�������ݳɹ�,������ջ��Ԫ�� e=%d\n",e);
				}
        	}
        	printf("\n");
		} 
		else if(strcmp(flag,"4")==0){
			system("cls");
			if(k==0) 
			   printf("���ȶ�ջ��ʼ��!\n"); 
			else if(k==1){
				d=isEmptyStack(s);
				if(d==ERROR) {
					getTopStack(s,&e);
					printf("ջ��Ԫ��Ϊ��%d\n",e);
				}
			}
			printf("\n");
		}
		else if(strcmp(flag,"5")==0){
			system("cls");
			if(k==0) 
			   printf("���ȶ�ջ��ʼ��!\n"); 
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
			   printf("ջ������!\n"); 
			else if(k==1){
				destroyStack(s);
				printf("ջ�����٣�\n");
				k=0;
			}
			printf("\n");
		}
		else if(strcmp(flag,"7")==0){
			system("cls");
			if(k==0) 
			   printf("���ȶ�ջ��ʼ��!\n"); 
			else if(k==1){
			d=isEmptyStack(s);
			if(d==ERROR){
				clearStack(s);
				printf("ջ����գ�\n");
				}
			}
			printf("\n");	
		}   
		else if(strcmp(flag,"8")==0){
			system("cls");
			if(k==0) 
			   printf("���ȶ�ջ��ʼ��!\n");
			else if(k==1){
				if(isEmptyStack(s)==ERROR)
					StackPrint(s);
				}
			printf("\n");		
		}
		else {
			system("cls");
			printf("�������!\n");
			printf("\n");
		}
	}
        return 0;
}


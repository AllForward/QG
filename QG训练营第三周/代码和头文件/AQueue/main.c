#include<stdio.h>    
#include<stdlib.h>
#include<stdlib.h>
#include"AQueue.h"



char GetType(void)				//得到数据类型 
{
    int choice = 0;
    while(!choice)
    {
    	system("cls");
        char option[10];
        printf("请选择该节点的数据类型\n\n");
        puts("A. int");
        puts("B. float");
        puts("C. char");
        puts("D. string(不超过20个字节)");
		scanf("%s", option);
		if(strcmp(option, "A") != 0 && strcmp(option, "B") != 0 && strcmp(option, "C") != 0 && strcmp(option, "D") != 0)
		{
			printf("输入选项错误!\n");
			printf("按任意键继续.....");
			getchar();
			getchar();
		}
        else{
        	switch(option[0])
       		{
       			system("cls");
            	case 'A':   type = 'I';
            	            choice = 1; break;
	
    	        case 'B':   type = 'F';
        	                choice = 1; break;
	
    	        case 'C':   type = 'C';
        	                choice = 1; break;
	
    	        case 'D':   type = 'S';
        	                choice = 1; break;
        	                
        	    default:	puts("错误！\n");
    	    }
    	}
	}
	system("cls");
    return type;
}

int GetSize(char type)
{
    int size;
    switch (type)
    {
        case 'I':   size = sizeof(int); break;

        case 'F':   size = sizeof(float); break;

        case 'C':   size = sizeof(char); break;

        case 'S':   size = 0; break;

        default :   printf("输入错误!\n");
    }
    return size;
}

void *Inputdata(char type)								//让用户输入结点数据 
{
    void *key = NULL;
    int *Icopy = (int *)malloc(sizeof(int));
    float *Fcopy = (float *)malloc(sizeof(float));
    char *Scopy = (char *)malloc(sizeof(char) * 20);
    printf("请输入该节点的数据：\n");
    switch (type)
    {
        case 'I':       while (1)
                        {
                            if(scanf("%d", Icopy) == 1)
                                break;
                            else
                            {
                                printf("输入错误！请重新输入！\n");
                                while(getchar() != '\n');
                            }
                        };
                        key = (void *)Icopy; break;

        case 'F':       while (1)
                        {
                            printf("");
                            if(scanf("%f", Fcopy) == 1)
                                break;
                            else
                            {
                                printf("输入错误！请重新输入！\n");
                                while(getchar() != '\n');
                            }
                        };
                        key = (void *)Fcopy; break;

        case 'C':		

        case 'S':       while (1)
                        {
                            printf("");
                            if (scanf("%20s",Scopy) != 1)
                            {
                                printf("输入错误！请重新输入！\n");
                                continue;
                            }
                            else
                                break;
                        }
                        key = (void *)Scopy; break;

        default:    printf("错误！\n");
    }
    while(getchar() != '\n');
    if (type != 'I')
        free(Icopy);
    if (type != 'F')
        free(Fcopy);
    if (type != 'C' && type != 'S')
        free(Scopy);
    return key;
}

int main()
{
	int j,d,e,k = 0,length;	
	void *data;									//k用于记录栈是否初始化 
    int *I; float *F; char *C;
	char flag[100];								//用于判断用户输入的选项是否有错误 
	AQueue Q; 	
	while(1){
    	printf("|=============队列的功能菜单==============|\n");
    	printf("|=============0.结束任务================|\n");
    	printf("|=============1.队列的初始化============|\n");    
    	printf("|=============2.入队====================|\n");
    	printf("|=============3.出队====================|\n");
   	 	printf("|=============4.获取队首元素============|\n");
    	printf("|=============5.获取队列长度============|\n");
   	 	printf("|=============6.销毁队列================|\n");
    	printf("|=============7.清空队列================|\n");
    	printf("|=============8.打印队列元素============|\n");
		printf("选择要执行的选项：");
		scanf("%s",	flag);	
		if( strcmp(flag, "0") == 0)
			break;
		else if(strcmp(flag, "1") == 0){
			system("cls");
			if(k == 0 ){
				InitAQueue(&Q);
				k = 1;
				printf("队列初始化成功!\n");
			}
			else if(k == 1){
				printf("队列已初始化!\n");	
			}
		}
		else if(strcmp(flag, "2") == 0){
       		system("cls");
       		if(k == 0) 
			   printf("请先初始化队列!\n");
			else{
				type = GetType();
				data = Inputdata( type);
				if(EnAQueue(&Q, data) == TRUE)
					printf("入队成功！\n");	 					
			}   
		}
		else if(strcmp(flag, "3") == 0){
       		system("cls");
       		if(k == 0) 
			   printf("请先初始化队列!\n");	 
			else {
				if(DeAQueue(&Q) == TRUE)
					printf("出队成功!\n");
			}   
		} 	
		else if(strcmp(flag, "4") == 0){				//获取队首元素 
       		system("cls");
       		if(k == 0) 
			   printf("请先初始化队列!\n");
			else {
				if (GetHeadAQueue(&Q, data))
                {
                    switch (datatype[Q.front])
                    {
                        case 'I':   I = (int *)data;   printf("对首元素为 %d\n", *I); break;

                        case 'F':   F = (float *)data; printf("对首元素为 %f\n", *F);  break;

                        case 'C':   C = (char *)data;  printf("对首元素为 %c\n", *C); break;

                        case 'S':   C = (char *)data;  printf("对首元素为 %s\n", C); break;
                        
                        default :   printf("错误！\n");
                    }
				}
			}   	   
		} 	
		else if(strcmp(flag, "5") == 0){				//获取队列长度
       		system("cls");
       		if(k == 0) 
			   printf("请先初始化队列!\n");	   
			else{
				d = IsEmptyAQueue(&Q);
				if(d == TRUE)
					printf("队列的长度为：%d\n", LengthAQueue(&Q));
			}   
		} 	
		else if(strcmp(flag, "6") == 0){
       		system("cls");
       		if(k == 0) 
			   printf("队列不存在!\n");	 
			else{
				DestoryAQueue(&Q);
				printf("队列已销毁！\n");
				k = 0;
			}     
		} 	
		else if(strcmp(flag, "7") == 0){
       		system("cls");
       		if(k == 0) 
			   printf("请先初始化队列!\n");	
			else if(k == 1){
				d = IsEmptyAQueue(&Q);
				if( d == TRUE){							//判断队列是否为空 
					ClearAQueue(&Q);
					printf("队列已清空！\n");
				}
			}      
		} 	
		else if(strcmp(flag, "8") == 0){
       		system("cls");
       		if(k == 0) 
			   printf("请先初始化队列!\n");	 
			else if(k == 1){
				void *q;
				if(IsEmptyAQueue(&Q) == TRUE)
					TraverseAQueue(&Q, APrint);
			}     
		}
		else{
			system("cls");
			printf("输入错误!\n");
		} 	
		printf("\n");
	}
	DestoryAQueue(&Q); 
	return 0;	
}

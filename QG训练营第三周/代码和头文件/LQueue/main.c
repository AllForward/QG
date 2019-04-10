#include<stdio.h>    
#include<stdlib.h>
#include<string.h>
#include"LQueue.h"

char GetType(void)				//�õ��������� 
{
    int choice = 0;
    while(!choice)
    {
    	system("cls");
        char option[10];
        printf("��ѡ��ýڵ����������\n\n");
        puts("A. int");
        puts("B. float");
        puts("C. char");
        puts("D. string(������20���ֽ�)");
		scanf("%s", option);
		if(strcmp(option, "A") != 0 && strcmp(option, "B") != 0 && strcmp(option, "C") != 0 && strcmp(option, "D") != 0)
		{
			printf("����ѡ�����!\n");
			printf("�����������.....");
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
        	                
        	    default:	puts("����\n");
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

        default :   printf("�������!\n");
    }
    return size;
}

void *Inputdata(char type)								//���û����������� 
{
    void *k = NULL;
    int *Icopy = (int *)malloc(sizeof(int));
    float *Fcopy = (float *)malloc(sizeof(float));
    char *Scopy = (char *)malloc(sizeof(char) * 20);
    printf("������ýڵ�����ݣ�\n");
    switch (type)
    {
        case 'I':       while (1)
                        {
                            if(scanf("%d", Icopy) == 1)
                                break;
                            else
                            {
                                printf("����������������룡\n");
                                while(getchar() != '\n');
                            }
                        };
                        k = (void *)Icopy; break;

        case 'F':       while (1)
                        {
                            printf("");
                            if(scanf("%f", Fcopy) == 1)
                                break;
                            else
                            {
                                printf("����������������룡\n");
                                while(getchar() != '\n');
                            }
                        };
                        k = (void *)Fcopy; break;

        case 'C':		

        case 'S':       while (1)
                        {
                            printf("");
                            if (scanf("%20s",Scopy) != 1)
                            {
                                printf("����������������룡\n");
                                continue;
                            }
                            else
                                break;
                        }
                        k = (void *)Scopy; break;

        default:    printf("����\n");
    }
    while(getchar() != '\n');
    if (type != 'I')
        free(Icopy);
    if (type != 'F')
        free(Fcopy);
    if (type != 'C' && type != 'S')
        free(Scopy);
    return k;
}

void menu(){
	
	int j, d, e, k = 0,i = 0, length;	
	int place = 0;					//����ָ������datatype�ж��׵�λ�� 
	void *data;									//k���ڼ�¼ջ�Ƿ��ʼ�� 
    int *I; float *F; char *C;
	char flag[100];								//�����ж��û������ѡ���Ƿ��д��� 
	for(i = 0;i < 20; i++)
		datatype[i] = '0';
	i = 0;
	LQueue Q; 	
	while(1){
    	printf("|=============���еĹ��ܲ˵�============|\n");
    	printf("|=============0.��������================|\n");
    	printf("|=============1.���еĳ�ʼ��============|\n");    
    	printf("|=============2.���====================|\n");
    	printf("|=============3.����====================|\n");
   	 	printf("|=============4.��ȡ����Ԫ��============|\n");
    	printf("|=============5.��ȡ���г���============|\n");
   	 	printf("|=============6.���ٶ���================|\n");
    	printf("|=============7.��ն���================|\n");
    	printf("|=============8.��ӡ����Ԫ��============|\n");
		printf("ѡ��Ҫִ�е�ѡ�");
		scanf("%s",	flag);	
		if( strcmp(flag, "0") == 0)
			break;
		else if(strcmp(flag, "1") == 0){
			system("cls");
			if(k == 0 ){
				InitLQueue(&Q);
				k = 1;
				printf("���г�ʼ���ɹ�!\n");
			}
			else if(k == 1){
				printf("�����ѳ�ʼ��!\n");	
			}
		}
		else if(strcmp(flag, "2") == 0){
       		system("cls");
       		if(k == 0) 
			   printf("���ȳ�ʼ������!\n");
			else{
				type = GetType();
				data = Inputdata( type);
				datatype[i++] = type;				//��¼��ÿ���ڵ���������� 
				if(EnLQueue(&Q, data) == TRUE)
					printf("��ӳɹ���\n");	 					
			}   
		}
		else if(strcmp(flag, "3") == 0){
       		system("cls");
       		if(k == 0) 
			   printf("���ȳ�ʼ������!\n");	 
			else {
				if(DeLQueue(&Q) == TRUE)
					printf("���ӳɹ�!\n");
				datatype[place++] = '0';								//datatype����Ķ��ױ仯���Ӷ�ʹloc+1; 	
			}   
		} 	
		else if(strcmp(flag, "4") == 0){				//��ȡ����Ԫ�� 
       		system("cls");
       		if(k == 0) 
			   printf("���ȳ�ʼ������!\n");
			else {
				if (GetHeadLQueue(&Q, data))
                {
                    switch (datatype[place])
                    {
                        case 'I':   I = (int *)data;   printf("����Ԫ��Ϊ %d\n", *I); break;

                        case 'F':   F = (float *)data; printf("����Ԫ��Ϊ %f\n", *F);  break;

                        case 'C':   C = (char *)data;  printf("����Ԫ��Ϊ %c\n", *C); break;

                        case 'S':   C = (char *)data;  printf("����Ԫ��Ϊ %s\n", C); break;
                        
                        default :   printf("����\n");
                    }
				}
			}   	   
		} 	
		else if(strcmp(flag, "5") == 0){				//��ȡ���г���
       		system("cls");
       		if(k == 0) 
			   printf("���ȳ�ʼ������!\n");	   
			else{
				d = IsEmptyLQueue(&Q);
				if(d == TRUE)
					printf("���еĳ���Ϊ��%d\n", LengthLQueue(&Q));
			}   
		} 	
		else if(strcmp(flag, "6") == 0){
       		system("cls");
       		if(k == 0) 
			   printf("���в�����!\n");	 
			else{
				DestoryLQueue(&Q);
				printf("���������٣�\n");
				k = 0;
				i = 0;
			}     
		} 	
		else if(strcmp(flag, "7") == 0){
       		system("cls");
       		if(k == 0) 
			   printf("���ȳ�ʼ������!\n");	
			else if(k == 1){
				d = IsEmptyLQueue(&Q);
				if( d == TRUE){							//�ж϶����Ƿ�Ϊ��
					ClearLQueue(&Q);
					printf("��������գ�\n");
				}
				i = 0;
			}      
		} 	
		else if(strcmp(flag, "8") == 0){
       		system("cls");
       		if(k == 0) 
			   printf("���ȳ�ʼ������!\n");	 
			else if(k == 1){
				void *q;
				if(IsEmptyLQueue(&Q) == TRUE)
					TraverseLQueue(&Q, LPrint);
			}     
		}
		else{
			system("cls");
			printf("�������!\n");
		} 	
		printf("\n");
	}
	DestoryLQueue(&Q); 
}

int main()
{
	
	menu();
	
	return 0;
}






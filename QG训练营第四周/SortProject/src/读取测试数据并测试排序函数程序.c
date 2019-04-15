#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"qgsort.h"

void menu(void);

int main()
{
	menu();
	
	return 0;	
}

void menu()
{
	char flag[100];
	int a[10], temp[10], i = 0;
	FILE* fp;
	fp = fopen("data.txt","r");
	for(; i < 10; i++){
		fscanf(fp, "%d ", &a[i]); 	
	}
	while(1){
		system("cls");		
		printf("|=========��ӭʹ�������㷨С����========|\n");
		printf("|=============0.��������================|\n");
	    printf("|=============1.��������================|\n");    
   		printf("|=============2.�鲢����================|\n");
   		printf("|=============3.�������򣨵ݹ�棩======|\n");
  		printf("|=============4.�������򣨷ǵݹ�棩====|\n");
  		printf("|=============5.��������================|\n");
  	 	printf("|=============6.������������============|\n");
    	printf("|=============7.��ɫ����================|\n");
    	printf("|=============8.Ѱ�ҵ�K�����===========|\n");
		printf("ѡ��Ҫִ�е�ѡ�");
		scanf("%s",	flag);	
		if( strcmp(flag, "0") == 0)
			break;
		
		else if(strcmp(flag, "1") == 0){
			system("cls");
			printf("���������㷨ʾ����\n");
			printf("ԭ�ȵ�����Ϊ:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			insertSort(a, 10);
			printf("�����ĵ�����Ϊ:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			printf("�����������......");	
			getchar();
			getchar();					
		}
		
		else if(strcmp(flag, "2") == 0){
			system("cls");
			printf("�鲢�����㷨ʾ����\n");
			printf("ԭ�ȵ�����Ϊ:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			MergeSort(a, 0, 9, temp);
			printf("�����ĵ�����Ϊ:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			printf("�����������......");	
			getchar();
			getchar();	
		}
		
		else if(strcmp(flag, "3") == 0){
			system("cls");
			printf("�������򣨵ݹ�棩�㷨ʾ����\n");
			printf("ԭ�ȵ�����Ϊ:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			QuickSort_Recursion(a, 0, 9); 
			printf("�����ĵ�����Ϊ:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			printf("�����������......");	
			getchar();
			getchar();					
		}
		
		else if(strcmp(flag, "4") == 0){
			system("cls");
			printf("�������򣨷ǵݹ�棩�㷨ʾ����\n");
			printf("ԭ�ȵ�����Ϊ:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			QuickSort(a, 10);	
			printf("�����ĵ�����Ϊ:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			printf("�����������......");	
			getchar();
			getchar();					
		}
		
		else if(strcmp(flag, "5") == 0){
			system("cls");
			printf("���������㷨ʾ����\n");
			printf("ԭ�ȵ�����Ϊ:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");
			int max = a[0];
			for(i = 1; i < 10; i++){
				if(max < a[i])
					max = a[i];
			}
			CountSort(a, 10 , max);	
			printf("�����ĵ�����Ϊ:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			printf("�����������......");	
			getchar();
			getchar();					
		}
		
		else if(strcmp(flag, "6") == 0){
			system("cls");
			printf("�������������㷨ʾ����\n");
			printf("ԭ�ȵ�����Ϊ:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			RadixCountSort(a, 10);
			printf("�����ĵ�����Ϊ:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			printf("�����������......");	
			getchar();
			getchar();					
		}
		
		else if(strcmp(flag, "7") == 0){
			system("cls");
			printf("��ɫ�����㷨ʾ����\n");
			printf("���������Ԫ�ص�ֵ(Ԫ��ֵֻ��Ϊ:0 �� 1 �� 2,����������������Ч����ʽ��1 0)\n");
			for(i = 0; i < 10; i++)
				scanf("%d",&a[i]);
			printf("\n");	
			ColorSort(a, 10);		
			printf("�����ĵ�����Ϊ:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			printf("�����������......");	
			getchar();
			getchar();					
		}
		
		else if(strcmp(flag, "8") == 0){
			system("cls");
			printf("Ѱ�ҵ�K������㷨ʾ����\n");
			printf("ԭ�ȵ�����Ϊ:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");
			printf("��������ҵڣ��������\n");
			int k;
			scanf("%d",&k);	
			int data = Search_Kth_Largest(a, 0, 9, 11 - k);
			printf("\n");	
			printf("��%d�����Ϊ��%d\n", k, data);
			printf("\n");	
			printf("�����������......");	
			getchar();
			getchar();					
		}
		
		else{
			system("cls");
			printf("�������!\n");
		} 	
		printf("\n");
		
		for(i = 0; i < 10; i++){
			fscanf(fp, "%d ", &a[i]); 	
		}
		printf("\n");
	}
	
	fclose(fp);
}

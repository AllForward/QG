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
		printf("|=========欢迎使用排序算法小程序========|\n");
		printf("|=============0.结束任务================|\n");
	    printf("|=============1.插入排序================|\n");    
   		printf("|=============2.归并排序================|\n");
   		printf("|=============3.快速排序（递归版）======|\n");
  		printf("|=============4.快速排序（非递归版）====|\n");
  		printf("|=============5.计数排序================|\n");
  	 	printf("|=============6.基数计数排序============|\n");
    	printf("|=============7.颜色排序================|\n");
    	printf("|=============8.寻找第K大的数===========|\n");
		printf("选择要执行的选项：");
		scanf("%s",	flag);	
		if( strcmp(flag, "0") == 0)
			break;
		
		else if(strcmp(flag, "1") == 0){
			system("cls");
			printf("插入排序算法示例：\n");
			printf("原先的数据为:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			insertSort(a, 10);
			printf("排序后的的数据为:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			printf("按任意键继续......");	
			getchar();
			getchar();					
		}
		
		else if(strcmp(flag, "2") == 0){
			system("cls");
			printf("归并排序算法示例：\n");
			printf("原先的数据为:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			MergeSort(a, 0, 9, temp);
			printf("排序后的的数据为:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			printf("按任意键继续......");	
			getchar();
			getchar();	
		}
		
		else if(strcmp(flag, "3") == 0){
			system("cls");
			printf("快速排序（递归版）算法示例：\n");
			printf("原先的数据为:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			QuickSort_Recursion(a, 0, 9); 
			printf("排序后的的数据为:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			printf("按任意键继续......");	
			getchar();
			getchar();					
		}
		
		else if(strcmp(flag, "4") == 0){
			system("cls");
			printf("快速排序（非递归版）算法示例：\n");
			printf("原先的数据为:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			QuickSort(a, 10);	
			printf("排序后的的数据为:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			printf("按任意键继续......");	
			getchar();
			getchar();					
		}
		
		else if(strcmp(flag, "5") == 0){
			system("cls");
			printf("计数排序算法示例：\n");
			printf("原先的数据为:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");
			int max = a[0];
			for(i = 1; i < 10; i++){
				if(max < a[i])
					max = a[i];
			}
			CountSort(a, 10 , max);	
			printf("排序后的的数据为:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			printf("按任意键继续......");	
			getchar();
			getchar();					
		}
		
		else if(strcmp(flag, "6") == 0){
			system("cls");
			printf("基数计数排序算法示例：\n");
			printf("原先的数据为:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			RadixCountSort(a, 10);
			printf("排序后的的数据为:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			printf("按任意键继续......");	
			getchar();
			getchar();					
		}
		
		else if(strcmp(flag, "7") == 0){
			system("cls");
			printf("颜色排序算法示例：\n");
			printf("请输入各个元素的值(元素值只能为:0 或 1 或 2,否则排序后的序列无效！格式：1 0)\n");
			for(i = 0; i < 10; i++)
				scanf("%d",&a[i]);
			printf("\n");	
			ColorSort(a, 10);		
			printf("排序后的的数据为:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");	
			printf("按任意键继续......");	
			getchar();
			getchar();					
		}
		
		else if(strcmp(flag, "8") == 0){
			system("cls");
			printf("寻找第K大的数算法示例：\n");
			printf("原先的数据为:\n");
			for(i = 0; i < 10; i++)
				printf("%d->",a[i]);
			printf("\n");
			printf("输入想查找第？大的数：\n");
			int k;
			scanf("%d",&k);	
			int data = Search_Kth_Largest(a, 0, 9, 11 - k);
			printf("\n");	
			printf("第%d大的数为：%d\n", k, data);
			printf("\n");	
			printf("按任意键继续......");	
			getchar();
			getchar();					
		}
		
		else{
			system("cls");
			printf("输入错误!\n");
		} 	
		printf("\n");
		
		for(i = 0; i < 10; i++){
			fscanf(fp, "%d ", &a[i]); 	
		}
		printf("\n");
	}
	
	fclose(fp);
}

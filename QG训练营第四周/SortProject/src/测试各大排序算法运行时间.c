#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include"qgsort.h"
#include"qgsort.c"
#define N 10000
#define M 50000
#define Max 200000
int test[Max];
void menu(void);
void test_insertSort(int *a, int n);
void test_MergeSort(int *a, int n);
void test_QuickSort_Recursion(int *a, int n);
void test_QuickSort(int *a, int n);
void test_CountSort(int *a, int n);
void test_RadixCountSort(int *a, int n);
	
int main()
{
	FILE* fp;
	int i = 0, n, time = 0, j = 0;
	int test[Max] = {0};
	int temp[100] = {0};
	printf("下面是100*10k的排序时间：\n");
	printf("请耐心等待......\n");
	
	printf("Insert Sort:\n");
	for(i = 1; i <= 100*1000; i++){
		j = 0;
		while(j < 100)
			test[j++] = rand();
		clock_t start_time=clock();
    	insertSort(test, 100);
   		clock_t end_time=clock();
   		time += end_time - start_time;
	}
	printf("The running time of 100*1000 data is: %lfms\n\n",(double)time/CLOCKS_PER_SEC);
	time = 0;
	printf("MergeSort:\n");
	for(i = 1; i <= 100*1000; i++){
		j = 0;
		while(j < 100)
			test[j++] = rand();
		clock_t start_time=clock();
    	MergeSort(test, 0, 99, temp);
   		clock_t end_time=clock();	
   		time += end_time - start_time;
	}
	printf("The running time of 100*1000 data is: %lfms\n\n",(double)time/CLOCKS_PER_SEC);
	time = 0;
	printf("QuickSort Recursion:\n");
	for(i = 1; i <= 100*1000; i++){
		j = 0;
		while(j < 100)
			test[j++] = rand();
		clock_t start_time=clock();
    	QuickSort_Recursion(test, 0, 100 - 1);
   		clock_t end_time=clock();	
   		time += end_time - start_time;
	}
	printf("The running time of 100*1000 data is: %lfms\n\n",(double)time/CLOCKS_PER_SEC);
	time = 0;
	printf("QuickSort:\n");
	for(i = 1; i <= 100*1000; i++){
		j = 0;
		while(j < 100)
			test[j++] = rand();
		clock_t start_time=clock();
    	QuickSort(test, 100);
   		clock_t end_time=clock();	
   		time += end_time - start_time;
	}
	printf("The running time of 100*1000 data is: %lfms\n\n",(double)time/CLOCKS_PER_SEC);
	time = 0;
	printf("Count Sort:\n");
	for(i = 1; i <= 100*1000; i++){
		j = 0;
		while(j < 100)
			test[j++] = rand();
		int max = test[0];
		for(j = 0; j < max; j++){
			if(max < test[j])
				max = test[j];
		}
		clock_t start_time=clock();
    	CountSort(test, 100, max);
   		clock_t end_time=clock();	
   		time += end_time - start_time;
	}
	printf("The running time of 100*1000 data is: %lfms\n\n",(double)time/CLOCKS_PER_SEC);
	time = 0;
	printf("Radix Count Sort:\n");
	for(i = 1; i <= 100*1000; i++){
		j = 0;
		while(j < 100)
			test[j++] = rand();
		clock_t start_time=clock();
    	RadixCountSort(test, 100);
   		clock_t end_time=clock();	
   		time += end_time - start_time;
	}
	printf("The running time of 100*1000 data is: %lfms\n\n",(double)time/CLOCKS_PER_SEC);
	time = 0;
	printf("下面是数据量为10000的排序时间:\n");
	printf("请耐心等待......\n");
	test_QuickSort_Recursion(test, N);
	test_RadixCountSort(test, N);	
	test_insertSort(test, N);	
	test_MergeSort(test, N);
	test_QuickSort(test, N);
	test_CountSort(test, N);
	printf("\n\n");		
	printf("下面是数据量为50000的排序时间:\n");
	printf("请耐心等待......\n");
	test_QuickSort_Recursion(test, M);
	test_RadixCountSort(test, M);	
	test_insertSort(test, M);	
	test_MergeSort(test, M);
	test_QuickSort(test, M);
	test_CountSort(test, M);
	printf("\n\n");	
	printf("下面是数据量为200000的排序时间:\n");
	printf("请耐心等待......\n");
	test_QuickSort_Recursion(test, Max);
	test_RadixCountSort(test, Max);	
	test_insertSort(test, Max);	
	test_MergeSort(test, Max);
	test_QuickSort(test, Max);
	test_CountSort(test, Max);		
	return 0;		
} 

void test_insertSort(int *a, int n)
{
	int j = 0;
	while(j < n)
		a[j++] = rand();
	printf("Insert Sort:\n");
	clock_t start_time=clock();
    insertSort(a, n);
   	clock_t end_time=clock();
	printf("The running time of %d data is: %lfms\n",n,(double)(end_time-start_time)/CLOCKS_PER_SEC);
	printf("\n");
}

void test_MergeSort(int *a, int n)
{
	int j = 0;
	while(j < n)
		a[j++] = rand();
	printf("Merge Sort:\n");
	int temp[n];
	clock_t start_time=clock();
    MergeSort(a, 0, n - 1, temp);
   	clock_t end_time=clock();
	printf("The running time of %d data is: %lfms\n",n,(double)(end_time-start_time)/CLOCKS_PER_SEC);
	printf("\n");
}

void test_QuickSort_Recursion(int *a, int n)
{
	int j = 0;
	while(j < n)
		a[j++] = rand();
	printf("QuickSort Recursion:\n");
	clock_t start_time=clock();
    QuickSort_Recursion(a, 0, n - 1);
   	clock_t end_time=clock();
	printf("The running time of %d data is: %lfms\n",n,(double)(end_time-start_time)/CLOCKS_PER_SEC);
	printf("\n");
}

void test_QuickSort(int *a, int n)
{
	int j = 0;
	while(j < n)
		a[j++] = rand();
	printf("QuickSort:\n");
	clock_t start_time=clock();
    QuickSort(a, n);
   	clock_t end_time=clock();
	printf("The running time of %d data is: %lfms\n",n,(double)(end_time-start_time)/CLOCKS_PER_SEC);
	printf("\n");
}

void test_CountSort(int *a, int n)
{
	int j = 0;
	while(j < n)
		a[j++] = rand();
	int max = a[0];
	for(j = 0; j < max; j++){
		if(max < a[j])
			max = a[j];
	}
	printf("Count Sort:\n");
	int temp[n];
	clock_t start_time=clock();
    CountSort(a, n, max);
   	clock_t end_time=clock();
	printf("The running time of %d data is: %lfms\n",n,(double)(end_time-start_time)/CLOCKS_PER_SEC);
	printf("\n");
}

void test_RadixCountSort(int *a, int n)
{
	int j = 0;
	while(j < n)
		a[j++] = rand();
	printf("Radix Count Sort:\n");
	clock_t start_time=clock();
    RadixCountSort(a, n);
   	clock_t end_time=clock();
	printf("The running time of %d data is: %lfms\n",n,(double)(end_time-start_time)/CLOCKS_PER_SEC);
	printf("\n");
}








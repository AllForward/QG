#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
int main()
{
	srand(time(NULL));
	char choice[20];
	int i, k = 0;
	FILE* fp;
	fp = fopen( "data.txt", "w" ); /*w is right or not*/
	if(fp == NULL){
		puts("�����ļ�ʧ��!\n");
		exit(0);
	}
	while(1){
		system("cls");
		if(k == 0){
			printf("��ѡ��Ҫ���Ե�����������Ӧ��ѡ�\n");
			printf("1.10000\n");
			printf("2.50000\n");
			printf("3.200000\n");
			scanf("%s",choice);
		}
		if(strcmp(choice, "1") == 0){
			for (i = 0; i < 10000; i++)
				fprintf(fp,"%d ",rand()%11);
    		k = 1;
			fclose(fp);	
		}
		
		if(strcmp(choice, "2") == 0){
			for (i = 0; i < 50000; i++)
				fprintf(fp,"%d ",rand()%11);
    		k = 1;
			fclose(fp);	
		}
		
		if(strcmp(choice, "3") == 0){
			for (i = 0; i < 200000; i++)
				fprintf(fp,"%d ",rand()%11);
    		k = 1;
			fclose(fp);		
		}

		if(k == 1){
			printf("�������ɳɹ������������ļ�data.txt�в鿴��\n");
			break;
		}
		else {
			printf("������󣡰����������......\n");
			getchar();
			getchar();
		}
	}
	return 0;
}

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
		puts("创建文件失败!\n");
		exit(0);
	}
	while(1){
		system("cls");
		if(k == 0){
			printf("请选择要测试的数据量所对应的选项：\n");
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
			printf("数据生成成功！请从桌面的文件data.txt中查看！\n");
			break;
		}
		else {
			printf("输入错误！按任意键继续......\n");
			getchar();
			getchar();
		}
	}
	return 0;
}

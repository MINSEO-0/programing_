#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
void main(void){
	FILE *fp = NULL;
	char c;
	fp = fopen("sample.txt", "r");
	if (fp == NULL)
	 printf("������ �� ����\n");
	 
	//�ѱ��� ���� ���� ������ �������� �ƴϸ�
	while((c=fgetc(fp))!= EOF)
	putchar(c); //ȭ�鿡 �ѱ��� ��� 
	
	fclose(fp);
}
*/


void main(void){
	FILE *fp = NULL;
	char str[100];
	fp =fopen("sample.txt", "r");
	if(fp == NULL)
	 printf("������ �� ����\n");
	
	while(fgets(str, 15, fp) != NULL) 
	printf("%s", str);
}

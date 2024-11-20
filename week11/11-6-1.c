#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
void main(void){
	FILE *fp = NULL;
	char c;
	fp = fopen("sample.txt", "r");
	if (fp == NULL)
	 printf("파일을 못 열음\n");
	 
	//한글자 읽은 것이 파일의 마지막이 아니면
	while((c=fgetc(fp))!= EOF)
	putchar(c); //화면에 한글자 출력 
	
	fclose(fp);
}
*/


void main(void){
	FILE *fp = NULL;
	char str[100];
	fp =fopen("sample.txt", "r");
	if(fp == NULL)
	 printf("파일을 못 열음\n");
	
	while(fgets(str, 15, fp) != NULL) 
	printf("%s", str);
}

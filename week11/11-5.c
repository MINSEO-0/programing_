#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void){
	FILE *fp = NULL;
	
	fp = fopen("sample.txt", "w");
   
   char word1[50], word2[50], word3[50];
   
    printf("input a word: ");
    scanf("%s", &word1);
 
    
    printf("input a word: ");
    scanf("%s", &word2);

    
    printf("input a word: ");
    scanf("%s", &word3);


    fprintf(fp, "%s\n%s\n%s\n", word1, word2, word3);

    fclose(fp);

    return 0;
	 
}

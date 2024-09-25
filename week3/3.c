#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void){
	int i;
	char c;
	
	printf("enter a charter : ");
	scanf("%c", &c);
	
	i = c;
	
	printf("the next character of %c(%i) is %c(%i)", c, i, c+1, i+1);

	
	return 0;
	
}


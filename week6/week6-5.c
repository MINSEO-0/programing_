#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a, b;
	char c;
	printf("Enter the caculations: ");
	scanf("%i %c %i", &a, &c, &b);
	
	switch(c){
		
		case '+':
			printf("=%i", a+b);
			break;
			
		case '-':
			printf("=%i", a-b);
			break;
			
		case '*':
			printf("=%i", a*b);
			break;
			
		case '/':
			printf("=%i", a/b);
			break;
	}
	return 0;
}

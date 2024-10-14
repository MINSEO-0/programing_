#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i;
	int num;
	int sum=0;
	printf("Enter a number: ");
	scanf("%i", &num);
	
	for(i=1; i<=num ; i++)
	
	 sum=sum+i;
	 
	printf("The result is %i\n", sum); 
	return 0;
}

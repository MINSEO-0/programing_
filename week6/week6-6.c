#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num;
	int answer=50;
	int sum=0;
		
	
	do{
	   printf("Guess a number: ");
	   scanf("%i", &num);
	
		if(num>answer)
		 printf ("High!\n");
		
		else if(num<answer)
		 printf("Low!\n");
		 
		sum+=1;
		
			}while(num<answer || num>answer);
			
	printf("Congratulations! Trials: %i", sum);
	return 0;
}

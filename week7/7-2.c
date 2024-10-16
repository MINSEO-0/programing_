#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int sumTwo(int a, int b){
	int output;
	output= a+b;
	return output;
}

int square(int n){
	return(n*n);
}

int get_max(int x, int y){
	if(x>y)
	 return (x);
	else return (y);
}


int main(int argc, char *argv[]) {
	
	int Sum, Square, Max;
	int num1, num2;
	printf("Enter the integers: ");
	scanf("%i %i", &num1, &num2);
	
	Sum= sumTwo(num1, num2);
	Square=square(num1);
	Max=get_max(num1, num2);
	
	printf("Result - Sum: %i, Square: %i, Max: %i", Sum, Square, Max);
	return 0;
}

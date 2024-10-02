#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int a;
	printf("Input the year: ");
	scanf("%d", &a);
	
	int leap_year = (a%400==0 || (a%4==0 && a%100 != 0));
	
	printf("Is the year %d the leap year? %d", a, leap_year);
	
	
	return 0;
}

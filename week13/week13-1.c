#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct student{
	int ID;
	char name[15];
	double grade;
};


int main(void) {
	struct student s1= {24, "eunju", 4.3};
	s1.ID=2412614;
	strcpy(s1.name, "Minseo");
	s1.grade= 4.3;
	
	printf("ID: %d\n", s1.ID);
	printf("name: %s\n", s1.name);
	printf("grade: %f\n", s1.grade);
	
	return 0;
}

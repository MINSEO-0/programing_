#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	
	int i;
	int a[SIZE] = {1, 2, 3, 4, 5};
	int b[SIZE] = {1, 2, 3, 7, 10};
	int flag_same =1;
	
	for(i=0; i<SIZE; i++){
		
		if (a[i] != b[i])
		{
			printf("베열은 다른 값을 가집니다. 배열의 %d 인덱스가 다릅니다. \n", i);
			flag_same=0;
}
		
}
	return 0;
}

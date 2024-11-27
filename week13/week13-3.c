#include <stdio.h>
#include <stdlib.h>
#define STUDENTNUM 4
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct student{
	int ID;
	int score;
};

int main(void) {
	
	struct student s[STUDENTNUM];
	int i;
	int sum=0;
	float average=0;
	int highestscore = 0;
	int highestID=0;
	
	for(i=0; i<STUDENTNUM; i++){
		printf("Input the ID: ");
		scanf("%d", &s[i].ID);
		
		printf("Input the score: ");
		scanf("%d", &s[i].score);
		
		sum+=s[i].score;
		
		if(s[i].score>highestscore){
			highestscore=s[i].score;
			highestID=s[i].ID;
		}
			
	}
	
	average=sum/STUDENTNUM;
	printf("The average of the score: %f\n", average);
	printf("The highest score - ID: %d, score: %d", highestID, highestscore);
	return 0;
}

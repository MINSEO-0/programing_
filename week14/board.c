//
//  board.c
//  sharkGame
//

#include "board.h"
#include <stdlib.h>
#include <time.h>

// ----- EX. 3 : board ------------

#define N_COINPOS       12
#define MAX_COIN        4
// ----- EX. 3 : board ------------
// ----- EX. 5 : shark ------------
#define MAX_SHARKSTEP   6
#define SHARK_INITPOS   -4
#define MAX_SHARK_POSITION 18
// ----- EX. 5 : shark ------------
// ----- EX. 3 : board ------------
static int board_coin[N_BOARD];
static int board_status[N_BOARD]; //0 - OK, 1 - destroyed
// ----- EX. 3 : board ------------


static int shark_position;

// ----- EX. 3 : board ------------
void board_printBoardStatus(void)
{
    int i;
    
    printf("----------------------- BOARD STATUS -----------------------\n");
    for (i=0;i<N_BOARD;i++)
    
    {
        printf("|");
        if (board_status[i] == BOARDSTATUS_NOK)
            printf("X");
        else
            printf("O");
    }
    printf("|\n");
    printf("------------------------------------------------------------\n");
}

int board_initBoard(void)
{
    int i;
    
    //variable initialization
    for (i=0; i<N_BOARD; i++)
    {
        board_status[i] = BOARDSTATUS_OK;
        board_coin[i] = 0; }
        
        for(i=0; i<N_COINPOS< i++; ){
        	while(board_coin[i] ==0){
			board_coin[i]= rand() % N_BOARD; 
			
			
			if(board_coin[i] !=0 ){
			board_coin[i] = rand()%MAX_COIN +1;
			
			
		      	}      		
			}
		}
    
// ----- EX. 5 : shark ------------

    shark_position = SHARK_INITPOS;
// ----- EX. 5 : shark ------------

    //coin allocation
   
    
    return N_COINPOS;
}
// ----- EX. 3 : board ------------


// ----- EX. 5 : shark ------------
int board_stepShark(void)
{
	int step = (rand() % MAX_SHARKSTEP) +1;
	shark_position += step;
	
	if(shark_position > MAX_SHARK_POSITION){
		shark_position = MAX_SHARK_POSITION;
	}
	
	
	printf("Shark moves %d steps. Current position: %d\n", step, shark_position);
	
	int i; 
	for(i=0 ; i < N_BOARD -1; i++){
		if( i <= shark_position && shark_position >= 0) {
			board_status[i] = BOARDSTATUS_NOK;
		}
	}
	

	return shark_position;

}
// ----- EX. 5 : shark ------------


// ----- EX. 3 : board ------------
int board_getBoardStatus(int pos)
{
    return board_status[pos];
}

int board_getBoardCoin(int pos)
{
    int coin = board_coin[pos];
    board_coin[pos] = 0;
    return coin;
}
// ----- EX. 3 : board ------------

//
//  main.c
//  sharkGame
//

#include <stdio.h>
// ----- EX. 1 : Preparation------------
#include <stdlib.h>
#include <time.h>
// ----- EX. 1 : Preparation------------
#include "board.h"

// ----- EX. 4 : player ------------
#define N_PLAYER            3
// ----- EX. 4 : player ------------

#define MAX_CHARNAME        200

// ----- EX. 3 : board ------------
#define MAX_DIE             6
#define MAX_COIN            4
#define MAX_SHARK_POSITION  19

// ----- EX. 4 : player ------------
#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2

int player_position[N_PLAYER];
char player_name[N_PLAYER][MAX_CHARNAME];
int player_coin[N_PLAYER];
int player_status[N_PLAYER]; //0 - live, 1 - die, 2 - end
char player_statusString[3][MAX_CHARNAME] = {"LIVE", "DIE", "END"};
// ----- EX. 4 : player ------------

// ----- EX. 3 : board ------------
int rolldie(void)
{
    return rand()%MAX_DIE+1;
}
// ----- EX. 3 : board ------------

// ----- EX. 1 : Preparation------------
void opening(void)
{
    printf("==============================================================\n");
    printf("==============================================================\n");
    printf("==========                SHARK GAME!!!                =======\n");
    printf("==============================================================\n");
    printf("==============================================================\n");
}
// ----- EX. 1 : Preparation------------

// ----- EX. 6 : game end ------------
int game_end(void)
{
    int i;
    int alive_count=0;
    int end_count=0;
    
    //if all the players are died?
    for (i=0;i<N_PLAYER;i++)
    {
        if (player_status[i] == PLAYERSTATUS_LIVE){
         alive_count++;
         if(player_position[i] == N_BOARD - 1)
         {end_count++;
		 }
	}
        else if (player_status[i] == PLAYERSTATUS_END){
		end_count++;
	        	} 
		 
		   }
    
    return (end_count == N_PLAYER || alive_count == 0);
		
	}
// ----- EX. 6 : game end ------------

// ----- EX. 4 : player ------------
void printPlayerPosition(int player)
{
    int i;
    
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (player_position[player] == i)
            printf("%c", player_name[player][0]);
        else
        {
            if (board_getBoardStatus(i) == BOARDSTATUS_NOK)
                printf("X");
            else
                printf(" ");
        }
    }
    printf("|\n");
}

void printPlayerStatus(void)
{
    int i;
    printf("player status ---\n");
    for (i=0;i<N_PLAYER;i++)
    {
        printf("%s : pos %i, coin %i, status %s\n", player_name[i], player_position[i], player_coin[i], player_statusString[player_status[i]]);
        printPlayerPosition(i);
    }
    printf("-----------------\n");
}
// ----- EX. 4 : player ------------

// ----- EX. 5 : shark ------------
void checkDie(void)
{
    int i;
    for (i=0; i<N_PLAYER; i++)
    {
        if (player_status[i] == PLAYERSTATUS_LIVE && board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK)
        {
            printf("%s in pos %i has died!! (coin %i)\n", player_name[i], player_position[i], player_coin[i]);
            player_status[i] = PLAYERSTATUS_DIE;
        }
    }
}

// ----- EX. 5 : shark ------------

// ----- EX. 6 : game end ------------
int getAlivePlayer(void)
{
   int i;
   int cnt=0;
   for(i=0; i<N_PLAYER; i++){
   	if(player_status[i] == PLAYERSTATUS_LIVE)
   	     cnt++;
   }
   
   return cnt;
}

int getWinner(void)
{
    int i;
    int winner=-1;
    int max_coin=-1;
    int earliest_end = N_BOARD;
    
    for(i=0; i<N_PLAYER; i++){
    	if(player_status[i] == PLAYERSTATUS_END || (player_status[i] == PLAYERSTATUS_LIVE && player_position[i] == N_BOARD)){
    		if(player_coin[i] > max_coin || (player_coin[i] == max_coin && player_position[i] < earliest_end)){
			max_coin = player_coin[i];
			earliest_end = player_position[i];
			winner = i;
			}
		}
	}
    
    return winner;
    
}
	
// ----- EX. 6 : game end ------------


int main(int argc, const char * argv[]) {
	
	srand((time(NULL)));
    int i;
    int turn=0;
    int roundCount=0;

// ----- EX. 1 : Preparation------------
    srand(time(NULL));
    opening();
// ----- EX. 1 : Preparation------------

// ----- EX. 2 : structuring ------------
    //step1 : initialization
    //step1-1 : board initialization
    board_initBoard();

// ----- EX. 4 : player ------------
    //step1-2 : initialize player
    for (i=0;i<N_PLAYER;i++)
    {
        player_position[i] = 0;
        player_coin[i] = 0;
        player_status[i] = PLAYERSTATUS_LIVE;
        printf("Player %i's name: ", i);
        scanf("%s", player_name[i]);
        while(getchar() != '\n');
    }
// ----- EX. 4 : player ------------
    
    //step 2. : game start, turn loop
    do {
    	
    	roundCount++;
    	
// ----- EX. 3 : board ------------
       	board_printBoardStatus();
// ----- EX. 3 : board ------------
    
    
// ----- EX. 4 : player ------------
        printPlayerStatus();
// ----- EX. 4 : player ------------


        for(turn =0; turn<N_PLAYER; turn ++){
        	if(player_status[turn] != PLAYERSTATUS_LIVE){
        		continue;
			}
		
 
// ----- EX. 4 : player ------------
    
// ----- EX. 4 : player ------------
        
        //step 2-1. status printing
        

        //step 2-2. rolling die
// ----- EX. 4 : player ------------
        printf("%s turn!! ", player_name[turn]);
        printf("Press any key to roll a die!\n");
        
// ----- EX. 4 : player ------------
        while(getchar() != '\n');
        
        int dieResult = rolldie();
        printf("Rolled a %d\n", dieResult);
        
        //step 2-3. moving
        int newPosition = player_position[turn] + dieResult;
        
        if (newPosition >= N_BOARD -1) 
		{
        	player_position[turn] = N_BOARD -1;
        	player_status[turn] = PLAYERSTATUS_END;
		}
		else{
				player_position[turn] = newPosition;
		}
	
        //step 2-4. coin
        if(board_getBoardStatus(player_position[turn]) == BOARDSTATUS_OK) 
		{
			int coinResult = rand() % MAX_COIN + 1;
        	player_coin[turn] += coinResult;
        	board_getBoardCoin(player_position[turn]);
		}
		
        
        //step 2-5. end process
		
		board_printBoardStatus();
		printPlayerStatus();
}

		
			board_stepShark();
			board_printBoardStatus();
			checkDie();
			printPlayerStatus();		
		
// ----- EX. 6 : game end ------------
    }while(!game_end());
    
    //step 3. game end process
  printf("GAME END!!\n");
  int winnerIndex = getWinner();
  if (winnerIndex != -1) 
  {
  	printf("Winner is %s with %d coins!\n", player_name[winnerIndex], player_coin[winnerIndex]);
  }
  else{
  	printf("No players survived.\n");
  }
// ----- EX. 6 : game end ------------
    
// ----- EX. 2 : structuring ------------

    return 0;
} 

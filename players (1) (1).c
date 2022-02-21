#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"


struct player{
    char name [100];
    char score [100];
};
    
int main(void)
{
    struct player Player1; /* Declare Player1  of type player */
    struct player Player2; /* Declare Player2  of type player */
    struct player Player3; /* Declare Player3  of type player */
    struct player Player4; /* Declare Player4  of type player */
    
    /* player 1 specification */
    strcpy( Player1.name, "x");
    strcpy( Player1.score, "10"); 
    
    /* player 2 specification */
    strcpy( Player1.name, "w");
    strcpy( Player1.score, "20"); 
    
    /* player 3 specification */
    strcpy( Player1.name, "m");
    strcpy( Player1.score, "30"); 
    
    /* player 4 specification */
    strcpy( Player1.name, "p");
    strcpy( Player1.score, "40"); 
    
    /* print Player1 info */
   printf( "Player 1 name : %s\n", Player1.name);
   printf( "Player 1 score : %s\n", Player1.score);
   
   /* print Player2 info */
   printf( "Player 2 name : %s\n", Player2.name);
   printf( "Player 2 score : %s\n", Player2.score);
   
   /* print Player3 info */
   printf( "Player 3 name : %s\n", Player3.name);
   printf( "Player 3 score : %s\n", Player3.score);
   
   /* print Player4 info */
   printf( "Player 4 name : %s\n", Player4.name);
   printf( "Player 4 score: %s\n", Player4.score);
    
    return 0;
}

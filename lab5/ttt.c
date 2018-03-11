#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 3
int columns,rows;
void printBoard (int board[][SIZE]);
int getWinner(int board[][SIZE]);
int main(void){
	//initalising and allocating memory for the tic tac toe board.
   int *board[SIZE][SIZE];
   int outcome;
   memset(board,0,SIZE*SIZE*sizeof(int));

   int count = 0;
   printf("Please enter the board:\n");
   for(rows=0;rows<SIZE;rows++){
   	 for(columns=0;columns<SIZE;columns++){
   	    board[rows][columns]=getchar();
   	    getchar();
   	    count++;
     }
     if(count>(SIZE*SIZE)){
     	break;
     }
   } 
   printBoard(board);
   outcome = getWinner(board);
   if(outcome==SIZE){
      printf("Crosses Win");
   }
   if(outcome==(-SIZE)){
      printf("Noughts Win");
   }
   if(outcome!=SIZE&&outcome!=-SIZE){
      printf("No Winner");
   }
return EXIT_SUCCESS;
}

void printBoard(int board[][SIZE]){
    int count=0;
    printf("Here is the board: \n");
   for(rows=0;rows<SIZE;rows++){
      for(columns=0;columns<SIZE;columns++){
         if(board[rows][columns]==49){
            printf("X ");
         }
         else if(board[rows][columns]==48){
            printf("O ");
         }
         else{
            printf(". ");
         }
      }
      printf("\n");
   }
return;
}

int getWinner(int board[][SIZE]){
   int outcome;

   //check all rows
   for(rows=0;rows<SIZE;rows++){
   	  outcome = 0; //resets the counter each row
      for(columns=0;columns<SIZE;columns++){
         if(board[rows][columns]==49){
            outcome++;
         }
         if(board[rows][columns]==48){
            outcome--;
         } 

      }
      if(outcome==SIZE||outcome==-SIZE){
         return outcome;
      }
   }
   //checks all columns
   for(columns=0;columns<SIZE;columns++){
   	  outcome = 0; //resets the counter each row
      for(rows=0;rows<SIZE;rows++){
         if(board[rows][columns]==49){
         	outcome++;
         }
         if(board[rows][columns]==48){
         	outcome--;
         }

      }
      if(outcome==SIZE||outcome==-SIZE){
         return outcome;
      }      
   }
   //checking the diagonal going from legt to right  
   outcome = 0;
   for(columns=0;columns<SIZE;columns++){
      if(board[columns][columns]==49){
         outcome++;
      }
      if(board[columns][columns]==48){
         outcome--;
      }
      if(outcome==SIZE||outcome==-SIZE){
         return outcome;
      }
   }
   
   //checking the diagonal going from right to left
   outcome = 0;
   for(rows=0;rows<SIZE;rows++){
      if(board[rows][(SIZE)-rows]==49){
         outcome--;
      }
      if(board[rows][(SIZE)-rows]==48){
         outcome++;
      }
      if(outcome==SIZE||outcome==-SIZE){
         return outcome; 
      }
   }
  

 return EXIT_SUCCESS;
}

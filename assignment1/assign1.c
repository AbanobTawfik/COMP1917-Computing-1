#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define CHOICE_MAX 51
#define CHOICE_MIN 49
#define CONVERSION 48
#define MIN_DICE_VALUE 49
#define MAX_DICE_VALUE 54
#define SPACE 32
#define MAX_NUMBER_INPUT 57
#define MIN_NUMBER_INPUT 48
#define MAX_REROLL_INPUT 53
#define MIN_REROLL_INPUT 49
#define START 0
//warning the compiler for the functions that are being used for the code START
//the pointer functions are a pointer to the array they are returning hence why selection and reroll are pointer functions they return pointers to the array
int *selection(int max_input);
int decision(void);
int *reroll(int dice[]);
int yahtzee(int dice[]);
//end of function "initilaising"
int main(int argc, char *argv[]) {
   //initialising arrays (pointers to the array) and values
   int choice;
   int *dicevalues;
   int score;
   int *newdicevalues;
   //setting return values = to function return values
   dicevalues=selection(5);
   choice=decision();
   //if the return value is 1 user picked option 1 and run function again overiding past definition of dice values
   //and give user 1 last choice
   //user has option to pick all 3 options again and once done it will go to final choice, so user only gets 2 choice screens
   //option 2 allows user to reroll a select few of dice he choses, reroll some
   //there is another array called newdicevalues as when user choses to reroll all dice, it is essentially like starting with a new array
   //prevents buffer overflow/memory corruption to use a new array.
   //the return from the yahtzee function is their score and the program will print their score and exit once chosen
   //a choice is given, and inside that choice is all 3 choices for user, after that despite what he tries it will automatically go to the end
   //this is the case for option 1 and 2, if he choses option 3 he has chosen to keep dice -> go to end
   if(choice=='1') {
      dicevalues=reroll(dicevalues);
      choice=decision();
      if(choice=='2') {
         newdicevalues=selection(5);
         score = yahtzee(newdicevalues);
         printf("Your score is: %d points\n",score);
         return EXIT_SUCCESS;
      }
      if(choice=='1') {
         dicevalues=reroll(dicevalues);
         score = yahtzee(dicevalues);
         printf("Your score is: %d points\n",score);
         return EXIT_SUCCESS;
      }
      if(choice=='3') {
         score = yahtzee(dicevalues);
         printf("Your score is: %d points\n",score);
         return EXIT_SUCCESS;
      }
   }
   if(choice=='2') {
      newdicevalues=selection(5);
      choice=decision();
      if(choice=='2') {
         newdicevalues=selection(5);
         score = yahtzee(newdicevalues);
         printf("Your score is: %d points\n",score);
         return EXIT_SUCCESS;
      }
      if(choice=='1') {
         newdicevalues=reroll(newdicevalues);
         score = yahtzee(newdicevalues);
         printf("Your score is: %d points\n",score);
         return EXIT_SUCCESS;
      }
      if(choice=='3') {
         score = yahtzee(newdicevalues);
         printf("Your score is: %d points\n",score);
         return EXIT_SUCCESS;
      }
   }
   if(choice=='3') {
      score = yahtzee(dicevalues);
      printf("Your score is: %d points\n",score);
      return EXIT_SUCCESS;
   }
   return EXIT_SUCCESS;
}
int *selection(int max_input) {
   printf("Please enter dice values:\n");
   int *dice = malloc(100*sizeof(*dice));
   //allocating memory for the dice value array and pointer value as it will be used in multiple functions
   int count = 0;
   int i;
   int ch;
   int maxvalue=0;
   while((ch=getchar())!='\n') {
      //until user inputs enter on their keyboard (new line) place all the values entered into an array
      dice[count] = ch;
      count++;
      if(ch!=SPACE) {
         maxvalue++;
      }
   }
   //if user enters a doule digit, i.e there is no space between digits
   //turn on switch for format error (format = 1)
   for (i=0;i<count-1;i++) {
      if(dice[i]!=SPACE) {
         if(dice[i+1]!=SPACE) {
            printf("Incorrect Input Format.\n");
            exit(EXIT_FAILURE);
         }
      }
   }
   //error checks not all constants are in reference to ASCII table values since getchar() works with ascii table values
   for (i=0;i<count;i++) {
      if(dice[i]<MIN_NUMBER_INPUT||dice[i]>MAX_NUMBER_INPUT) {
         //if the input is less than 0 or greater than 9, it is not a number hence incorrect input format
         if(dice[i]!=SPACE) {
            printf("Incorrect Input Format.\n");
            exit(EXIT_FAILURE);
         }
      }
      if(dice[i]<MIN_DICE_VALUE||dice[i]>MAX_DICE_VALUE) {
         //if the input is less than 1 or greater than 6, it is not a dice value hence value out of range.
         //turn on switch for out of range error (range = 1), if the format is fine then print this as next error
         if(dice[i]!=SPACE) {
            printf("Value Out of Range.\n");
            exit(EXIT_FAILURE);
         }
      }
   }
   if(maxvalue!=max_input) {
      //if user does not enter 5 values seperated by a space( can enter as many spaces as they want) print error message
      //if range and format are both off this is last error or else selection is fine
      printf("Incorrect Number of Values.\n");
      exit(EXIT_FAILURE);
   }
   printf("\nYour dice values are: ");
   for (i=0;i<count;i++) {
      if(dice[i]!=SPACE) {
         printf("%d ",dice[i]-CONVERSION);
         //-CONVERSION because dice values are stored with ASCII so need to subtract 48 which makes them correct integers (48=0 in ASCII)
      }
   }
   printf("\n");
   //storing the very last memory space of array as length of array to easily allow sorting later on in yahtzee function
   dice[count+1]=(sizeof(dice)/sizeof(dice[0]));
   return dice;
   //return the dice array (the function is a pointer to the dice array)
}
int decision(void) {
   //allocating memory to an array
   int *choicearray = malloc(100*sizeof(int));
   int newcount = 0;
   int choice;
   int spacecounter = 0;
   printf("\nPlease choose:\n 1 -> Reroll some dice\n 2 -> Reroll all dice\n 3 -> Keep dice\n");
   newcount = 0;
   while((choice=getchar())!='\n') {
      //store all input user choses into an array
      choicearray[newcount] = choice;
      newcount++;
   }
   //adds 1 to counter each time a space at start is deteced
   while(choicearray[spacecounter]==SPACE) {
      spacecounter++;
      if(choicearray[spacecounter]!=SPACE) {
         break;
      }
   }
   //the return value of function is equal to the first non space value
   choice=choicearray[spacecounter];
   //the user can enter as many values as he wants but only first is taken rest is ignored
   //if the first value is invalid then print error message and exit
   if((choice<CHOICE_MIN||choice>CHOICE_MAX)) {
      printf("Invalid Choice.\n");
      exit(EXIT_FAILURE);
   }
   return choice;
}
int *reroll(int dice[]) {
   //initialising variables and allocating memory to arrays
   int rerolls,n,counter,counters,i,valuecheck;
   int selectcounter;
   int*reroll=malloc(sizeof(int)*10);
   int*rerolled=malloc(sizeof(int)*10);
   printf("Please enter dice to reroll (1-5): \n");
   counter = 0;
   selectcounter = 0;
   //inputs all data to array using getchar
   while((rerolls=getchar())!='\n') {
      reroll[counter]=rerolls;
      counter++;
      //counts how many non space values are input to the array
      if(rerolls!=SPACE) {
         selectcounter++;
      }
   }
   //if the input is not a number i.e ,;/\ will print an error message
   for (i=0;i<counter;i++) {
      if(reroll[i]<MIN_NUMBER_INPUT||reroll[i]>MAX_NUMBER_INPUT) {
         if(reroll[i]!=SPACE) {
            printf("Incorrect Input Format.\n");
            exit(EXIT_FAILURE);
         }
      }
      //if the dice values selected to reroll is not between 1-5 print error message
      if(reroll[i]<MIN_REROLL_INPUT||reroll[i]>MAX_REROLL_INPUT) {
         if(reroll[i]!=SPACE) {
            printf("Dice Number Out of Range.\n");
            exit(EXIT_FAILURE);
         }
      }
   }
   //if only 1 value is put into array then only 1 value to reroll print
   if(counter==1) {
      printf("Please enter 1 value:\n");
   } else {
      //if there are multiple values input print to user please enter the number of values of inputs they entered
      printf("Please enter %d values:\n",selectcounter);
   }
   counters = 0;
   valuecheck= 0;
   while((rerolls=getchar())!='\n') {
      rerolled[counters]=rerolls;
      counters++;
   }
   //count how many inputs user puts for reroll values
   for (i=0;i<counters;i++) {
      if(rerolled[i]!=SPACE) {
         valuecheck++;
      }
   }
   //error checks
   for (i=0;i<counters;i++) {
      if(rerolled[i]<MIN_NUMBER_INPUT||rerolled[i]>MAX_NUMBER_INPUT) {
         //if the input is less than 0 or greater than 9, it is not a number hence incorrect input format
         if(rerolled[i]!=SPACE) {
            printf("Incorrect Input Format.\n");
            exit(EXIT_FAILURE);
         }
      }
   }
   for (i=0;i<counters;i++) {
      if(rerolled[i]<MIN_DICE_VALUE||rerolled[i]>MAX_DICE_VALUE) {
         //if the input is less than 1 or greater than 6, it is not a dice value hence value out of range.
         //turn on switch for out of range error (range = 1), if the format is fine then print this as next error
         if(rerolled[i]!=SPACE) {
            printf("Value Out of Range.\n");
            exit(EXIT_FAILURE);
         }
      }
   }
   //if there are different number of values for the dice chosen to reroll and dice reroll inputs print error message
   if(valuecheck!=selectcounter) {
      printf("Incorrect Number of Values\n");
      exit(EXIT_FAILURE);
   }
   for (i=0;i<=counters;i++) {
      //converting array values, so if its not a space and satisfies the conditions
      if(rerolled[i]!=SPACE&&dice[i]>=MIN_DICE_VALUE&&dice[i]<=MAX_DICE_VALUE) {
         //convert the first array input to index of the 2nd array
         n=2*(reroll[i]-49);
         //change the selected index to the dice value chosen for the original array
         dice[n]=rerolled[i];
      }
   }
   printf("Your dice values are: ");
   for (i=0;i<9 ;i++) {
      if(dice[i]!=SPACE) {
         printf("%d ",dice[i]-CONVERSION);
      }
   }
   printf("\n");
   return dice;
}
int yahtzee(int dice[]) {
   //initialising values and arrays no need for pointers as the return value is not an array
   int score,i,threeofakind,fourofakind,straight,smallstraight,yahtzee,fullhouse,counter,input,n,spacecounter;
   int scorecount=0;
   int yahtzeee[100];
   int chancecounter = 1;
   printf("Your score options are:\n" );
   //this is to find the last element of the array which was the length of the array stored in previous selection function
   n=0;
   //while dice array is not equal to null (after the last value of array it goes null), add 1 to counter
   while(dice[n]!='\0') {
      n++;
   }
   //this is the function using in quicksort function
   //takes 2 inputs a and b, subtracts b from a
   //if bb-aa is positive will put b as first value (sorting in descending order)
   int comparefunction(const void *a, const void *b) {
      int aa,bb;
      aa=*(int*)a;
      bb=*(int*)b;
      return (bb-aa);
   }
   //for the length of the array (i<=n) sort out the dice values in ascending order using quicksort
   //quicksort takes in dice array, the number of time to sort, the type of integer and the way to be sorted (quicksort function)
   for (i=0;i<=n;i++) {
      if(dice[i]!=n) {
         qsort(dice,i,sizeof(*dice), comparefunction);
      }
   }
   //since dice is sorted into descending order equal values will be put side by side
   //since there are multiple situations where position of equal dice values are different each case is tested with logical or if statement
   //if three values of dice side by side are equal at the different possible positions, 0-2,1-3,2-4
   //the score = sum of the dice values and turn on the switch for three of a kind, and add 1 to chance counter
   //chance counter is used to print the option number for chance since it differs based on how many options user has
   //each of these conditions will add 1 to chance counter
   //each of these conditions will turn on their respective switches
   if((dice[0]==dice[1]&&dice[1]==dice[2])||(dice[1]==dice[2]&&dice[2]==dice[3])||(dice[2]==dice[3]&&dice[2]==dice[4])) {
      score = 0;
      for (i=0;i<5;i++) {
         score = score + (dice[i]-CONVERSION);
      }
      threeofakind=1;
      chancecounter++;
   }
   if(threeofakind==1) {
      printf("1 -> Three of a Kind (%d points)\n",score);
   }
   //full house tests double triple, which has 2 different cases 2 higher values and 3 lower eg. 6 6 3 3 3 and 3 lower 2 higher eg, 3 3 6 6 6
   //uses a longer logical or expression.
   //if the first 3 values are equal  dice index 0-2, AND (the 4th and 5th dice values are equal BUT the 5th and 1st are not equal)
   //and 2nd if does the same thing in reverse
   if((dice[0]==dice[1]&&dice[1]==dice[2]&&(dice[3]==dice[4]&&dice[4]!=dice[0]))||((dice[0]==dice[1]&&dice[0]!=dice[4])&&(dice[2]==dice[3]&&dice[3]==dice[4]))) {
      fullhouse=1;
      chancecounter++;
      score = 25;
      printf("2 -> Full House (%d points)\n",score);
   }
   //four of a kind is very similair to three of a kind but with only 2 conditions, 4 higher 1 lower and 4 lower 1 higher
   //uses logical or if statement to check if first 4 dice values are equal or the dice valeus for 2-5 are equal
   if((dice[0]==dice[1]&&dice[1]==dice[2]&&dice[2]==dice[3])||(dice[1]==dice[2]&&dice[2]==dice[3]&&dice[3]==dice[4])) {
      score = 0;
      for (i=0;i<5;i++) {
         score = score + (dice[i]-CONVERSION);
      }
      fourofakind=1;
      chancecounter++;
      if(fourofakind==1) {
         printf("2 -> Four of a Kind (%d points)\n",score);
      }
   }
   //this checks the array and if a value is the previous value +1, eg 2 and 3, will add 1 to count
   //since the array is sorted will always work despite which numbers/order put in
   scorecount=0;
   for (i=0;i<5;i++) {
      if(dice[i]-1==dice[i+1]) {
         scorecount++;
      }
   }
   //if the count is greater or = 3, and dice value 2 = dice value 3 +1 and dice value 3 = dice value 4+1
   //that means 4 values are in consecutive order eg 1 2 3 4, -> small straight
   if(scorecount>=3&&((dice[1]==dice[2]+1)&&(dice[2]==dice[3]+1))) {
      smallstraight=1;
      score=30;
      chancecounter++;
      printf("1 -> Small Straight (%d points)\n",score);
   }
   //if the count is = 4 that means 5 values are in consecutrive order -> straight
   if(scorecount==4) {
      straight=1;
      score=40;
      chancecounter++;
      printf("2 -> Straight (%d points)\n",score);
   }
   //if all the dice values are equal tro each other ->yahtzee
   if(dice[0]==dice[1]&&dice[1]==dice[2]&&dice[2]==dice[3]&&dice[3]==dice[4]) {
      chancecounter++;
      yahtzee=1;
   }
   if(yahtzee==1) {
      score = 50;
      printf("3 -> Yahtzee (%d points)\n",score);
   }
   //sets score equal to sum of all dice always an option so no if statement for chance
   score = 0;
   for (i=0;i<5;i++) {
      score = score + (dice[i]-CONVERSION);
   }
   printf("%d -> chance (%d points)\n",chancecounter,score);
   counter = 0;
   while((input=getchar())!='\n') {
      yahtzeee[counter]=input;  //gets user choice of score
      counter++;
   }
   //user can enter as many spaces as he wants before his first valid number
   //first valid number is in index spacecounter
   //adds 1 to spacecounter each time the first input is not a space
   spacecounter=0;
   while(yahtzeee[spacecounter]==SPACE) {
      spacecounter++;
      if(yahtzeee[spacecounter]!=SPACE) {
         break;
      }
   }
   //if the first valid input from user is not a number or in range print error messages
   if(yahtzeee[spacecounter]<MIN_NUMBER_INPUT||yahtzeee[spacecounter]>MAX_NUMBER_INPUT) {
      if(yahtzeee[spacecounter]!=SPACE) {
         printf("Invalid Choice.\n");
         exit(EXIT_FAILURE);
      }
   }
   if(yahtzeee[spacecounter]<'1'||yahtzeee[spacecounter]>chancecounter+CONVERSION) {
      if(yahtzeee[spacecounter]!=SPACE) {
         printf("Invalid Choice.\n");
         exit(EXIT_FAILURE);
      }
   }
   //resets score for user option when he picks
   score=0;
   //if switch for three of a kind is on and the user input 1, give score three of a kind which is sum of all dice values
   if(yahtzeee[spacecounter]=='1'&&threeofakind==1) {
      for (i=0;i<5;i++) {
         score = score + (dice[i]-CONVERSION);
      }
   }
   //if switch for fourofakind is on and the user input is 2, give score four a kind which is sum of all dice values
   if(yahtzeee[spacecounter]=='2'&&fourofakind==1) {
      for (i=0;i<5;i++) {
         score = score + (dice[i]-CONVERSION);
      }
   }
   //if switch for smallstraight is on and the user input 1, give score small straight -> 30
   if(yahtzeee[spacecounter]=='1'&&smallstraight==1) {
      score = 30;
   }
   //if switch for straight is on and the user input 2, give score straight -> 40
   if(yahtzeee[spacecounter]=='2'&& straight==1) {
      score=40;
   }
   //if switch for fullhouse is on and the user input 2, give score full hosue -> 25
   if(yahtzeee[spacecounter]=='2'&&fullhouse==1) {
      score=25;
   }
   //if switch for yahtzee is on and the user input 1, give score yahtzee -> 50
   if(yahtzeee[spacecounter]=='3'&&yahtzee==1) {
      score = 50;
   }
   //if user input is the same as the count for chance, give score chance which is the sum of all dice values
   if(yahtzeee[spacecounter]==chancecounter +'0') {
      score = 0;
      for (i=0;i<5;i++) {
         score = score + (dice[i]-CONVERSION);
      }
   }
   return score;
}
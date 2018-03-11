#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//these values defined are intended to be the boundaries for the alphabet in upper and lower case in ASCII conversion
#define MAX1 65
#define MIN1 57
#define MAX2 97
#define MIN2 90
#define MAX3 127
#define MIN3 122
int encode(int ch, int shift); //warns compiler that there is a function called encode so it doesn't panic
int rotate_right(int ch, int shift); //warns compiler that there is a function called rotate_right so it doesn't panic
int rotate_left(int ch, int shift); //warns compiler that there is a function called rotate_left so it doesn't panic
int main(void){
   printf("Enter shift: "); //ask user to enter how many letters across does he want to shift
   int shift;
   int ch;
   scanf("%d",&shift); //asks user for how much they want to shift the input across
   if(shift>26){
      shift = shift%26; //since the alphabet repeats every 26 characters i.e shift 27 is the same as shift 1 , this is so a user can enter any shift they want and it will reduce it to the simplest form
   }
   printf("Enter Text:\n");
   //the getchar below is intended so that it consumes the first enter for the while loop (so the loop actually runs)
   getchar();
   while((ch=getchar())!='\n'){
      //until user presses enter gather input from user and then use the shift and input to call the function encode
      encode(ch,shift);
}
return 0;
}
//function written to shift the input if positive

int rotate_right(int ch, int shift){
   //this way system knows to only shift text using ascii table(for getchar() to integer conversion
//if the user enters a character between the uppercase letter of the alphabet petform the shifting
 if(ch<=MIN2&&ch>=MAX1){
      ch=ch+shift; //add the shift entered by user
      if(ch>=MIN2){ //for ascii if the user goes over the letter Z it will reset at the letter A with this
         ch=MAX1-5+(ch-MIN2); //this turns the value over the alphabet (usually special character) in a way that it can be looped between A-Z
         ch=ch+shift;
      }
      putchar(ch); //print the character shifted
   }
//similair case as above but with lower case alphabet
   if(ch<=MIN3&&ch>=MAX2){
      ch=ch+shift;
      if(ch>MIN3){
         ch=MAX2-5+(ch-MIN3);
         ch=ch+shift;
      }
      putchar(ch);
      }
//this makes sure that if the input is not a letter strictly, then it will stay the same as requested
   if(ch<MAX1&&ch>0){
      putchar(ch);
   }
   if(ch<MAX2&&ch>MIN2+1){
      putchar(ch);
   }
   if(ch<MAX3&&ch>MIN3){
      putchar(ch);
   }
return 0;
}
//this is the same function as rotate_right however it performs the opposite action and only runs when a negative shift is called

int rotate_left(int ch, int shift){
   //this way system knows to only shift text using ascii table(for getchar() to integer conversion)
   if(ch<=MIN2&&ch>=MAX1){
      ch=ch+shift;
      if(ch<MAX1){
         ch=MIN2+5+(ch-MAX1);
         ch=ch+shift;
      }
      putchar(ch);
   }

   if(ch<=MIN3&&ch>=MAX2){
      ch=ch+shift;
      if(ch<MAX2){
         ch=MIN3+5+(ch-MAX2);
         ch=ch+shift;
      }
      putchar(ch);
   }
   if(ch<MAX1&&ch>0){
      putchar(ch);
   }
   if(ch<MAX2&&ch>MIN2+1){
      putchar(ch);
   }
   if(ch<MAX3&&ch>MIN3){
      putchar(ch);
   }
return 0;
}
//this function calls on either rotate_left or rotate_right depending on what shift is entered by the user, and if the shift is = 0 then it will return original input
int encode(int ch, int shift){
   if(shift<0){
      rotate_left(ch, shift);
   }
   else if(shift>0){
      rotate_right(ch, shift);
   }
   if(shift==0){
      putchar(ch);
   }
return 0;
}

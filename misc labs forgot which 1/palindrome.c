#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ispalindrome(char array[]);
int main(void){
   int check;
   char character[500];
   memset(character,0,500);
   int i;
   printf("Enter string:\n");
   fgets(character,500,stdin);
   check = ispalindrome(character);
   if(check){
      printf("Yes, is a palindrome.\n");
   }else{
      printf("No, not a palindrome.\n");
   }
   return 0;
}
int ispalindrome(char array[]){
   int i;
   int count = 0;
   int newcount = 0;
   for(i=0;i<500;i++){
      if(array[i]>='A'&&array[i]<='Z'){
         array[i]=array[i]+('a'-'A');
      }
   }
   for(i=0;i<500;i++){
      if(array[i]>='a'&&array[i]<='z'){
         array[count]=array[i];
         count++;
         
      }
   }
   //since array index start 0 not 1
   count--;
   for(i=0;i<count;i++){
      if(array[i]>='a'&&array[i]<='z'){
         if(array[(count)-i]==array[i]){
            newcount++;
         }
      }
   }
   return (newcount==count);

}

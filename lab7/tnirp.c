#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 128

char* reverse_string(char array[]);
int main(void){
   int check;
   char character[MAXLEN];
   memset(character,0,MAXLEN);
   int i;
   printf("Enter string: \n");
   fgets(character,MAXLEN,stdin);
   reverse_string(character);
   return 0;
}

char* reverse_string(char array[]){
   int i;
   int j;
   int count = 0;
   while(array[count]!=0&&array[count]!=10){
      count++;
   }
   count--;
   for(i=count;i>=0;i--){
      printf("%c",array[i]);
   }
   return array;
}
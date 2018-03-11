#include <stdio.h>
#include <stdlib.h>
#include "Pkmn.h"

void printMenu();
void selectOption(PkmnList list);
//chose to make a function which calls the menu and performs all functions instead of putting it all in main which pollutes the main function
int main(int argc, char * argv[]) {
   PkmnList list = createPkmnList();
   selectOption(list);
   return EXIT_SUCCESS;
}
void printMenu() {

   printf("a - Add a Pokemon to the list\n");
   printf("p - Print list\n");
   printf("d - Display details of the current Pokemon\n");
   printf("> - Move to the next Pokemon\n");
   printf("< - Move to the previous Pokemon\n");
   printf("j - Jump to a specific Pokemon\n"); 
   printf("r - Remove the current Pokemon\n");
   printf("f - Find Pokemon\n");    
   printf("c - Count the number of Pokemon which have been found\n");  
   printf("e - Add an evolution to a Pokemon\n");   
   printf("s - Show the evolutions of the current Pokemon\n");
   printf("q - Quit\n");
}
void selectOption(PkmnList list){
   int id,type1,type2,idcompare,count,seed,factor,howmany,evolution,evolutionid;
   char name[PKMN_NAME_LENGTH];
   double height, weight; 
   printMenu();
   char selection;
   while((selection=getchar()) != 'q') {
      if(selection == 'a') {
         printf("Id: ");
         scanf("%d",&id);
         printf("Name: ");
         scanf("%s",name);
         printf("Height: ");
         scanf("%lf",&height);
         printf("Weight: ");
         scanf("%lf",&weight);
         printf("Type: ");
         scanf("%d",&type1);
         printf("Type: ");
         scanf("%d",&type2); 
         Pkmn pokemon = createPkmn(id,name,height,weight,type1,type2);
         addPkmnToList(list,pokemon);
      } else if (selection == 'p') {
         printPkmnList(list);
      } else if (selection == 'd') {
         printCurrentPkmn(list);
      } else if (selection == '>') {
         nextPkmn(list);
      } else if (selection == '<') {
         prevPkmn(list);
      } else if (selection == 'j') {
        printf("Id:");
        scanf("%d",&idcompare);
        jumpToPkmn(list,idcompare);   
      } else if (selection == 'r') {
        removePkmn(list);
      } else if (selection == 'f') {
        printf("Seed: ");
        scanf("%d",&seed);
        printf("Factor: ");
        scanf("%d",&factor);
        printf("Number to find: ");
        scanf("%d",&howmany);
        findPkmn(seed,factor,howmany,list);
      } else if (selection == 'c') {
        count = 0;
        count = totalFound(list);
        printf("%d Pokemon in list.\n",count);
      } else if (selection == 'e') {
        printf("Id of original pokemon: ");
        scanf("%d",&evolution);
        printf("Id of evolution: ");
        scanf("%d",&evolutionid);       
        addEvolution(list,evolution,evolutionid);
      } else if (selection == 's') {
        showEvolutions(list);
      }
      printMenu();
      selection = getchar();
   }
   freePkmnList(list);   
}
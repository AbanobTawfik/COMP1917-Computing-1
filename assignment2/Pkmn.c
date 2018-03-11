#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Pkmn.h"
#include <stdio.h> 
#include <ctype.h>
const char * const TYPES[] = {
	  "Bug",
	  "Dark",
	  "Dragon",
	  "Electric",
	  "Fairy",
	  "Fighting",
	  "Fire",
	  "Flying",
	  "Ghost",
	  "Grass",
	  "Ground",
	  "Ice",
	  "Normal",
	  "Poison",
	  "Psychic",
	  "Rock",
	  "Steel",
	  "Water"
}
;
// ADD YOUR CODE HERE - any extra typedefs and #defines you'd like to use
struct _list {
	Pkmn head;
	int size;
};
struct _pkmn {
	int id;
	char name[PKMN_NAME_LENGTH];
	double height;
	double weight;
	int type1;
	int type2;
	int found;
	int current;
	int evolution;
	Pkmn next;
};

const char * getTypeString(int i) {
	return TYPES[i];
}

Pkmn createPkmn(int id, char * name, double height, double weight, int type1, int type2) {
	//allocated memory for the whole pkmn node and stores all inputs
	Pkmn newPkmn = malloc(sizeof(struct _pkmn));
	assert(newPkmn!=NULL);
	newPkmn->id = id;
	strncpy(newPkmn->name,name,strlen(name));
	newPkmn->height = height;
	newPkmn->weight = weight;
	newPkmn->type1 = type1;
	newPkmn->type2 = type2;
	newPkmn->next = malloc(sizeof(Pkmn));
	newPkmn->next = NULL;
	//switches for future functions
	newPkmn->found = 0;
	newPkmn->current = 0;
	newPkmn->evolution = 0;
	//return the created pokemon
	return newPkmn;
}
void printCurrentPkmn(PkmnList list) {
	//if no pokemon in list print message and return
	if(list->size==0) {
		printf("No Pokemon in list.\n");
		return;
	}
	int i;
	//when printing the current pokemon find the current pokemon
	Pkmn curr = list->head;
	//to find the current pokemon find the one with the switch curr->current turned on (curr->current ==1)
	while(curr->current==0&&curr->next!=NULL) {
		curr = curr->next;
	}
	//create a array to print asteriks for name incase pokemon is not found
	char temp[PKMN_NAME_LENGTH] = {0};
	//if pokemon is not found 
	if(curr->found==0) {
		//print the id
		printf("id: %03d\n",curr->id);
		//store an asterisk for every letter in the name to a temp array
		for (i=0;curr->name[i]!='\0';i++) {
			temp[i]='*';
		}
		//print the details as hidden
		printf("Name: %s\n",temp);
		printf("Height: --\n");
		printf("Weight: --\n");
		printf("Type: --\n");
	}
	if(curr->found==1) {
		//if the pokemon is found print all of its details
		printf("id: %03d\n",curr->id);
		printf("Name: %s\n",curr->name);
		printf("Height: %.2fm\n",curr->height);
		printf("Weight: %.2fkg\n",curr->weight);
		if(curr->type2==-1) {
			printf("Type: %s\n",getTypeString(curr->type1));
		} else {
			printf("Type: %s/%s\n",getTypeString(curr->type1),getTypeString(curr->type2));
		}
	}
}
PkmnList createPkmnList(void) {
	//allocate space for list and initalise all values with 0 and null;
	PkmnList list = malloc(sizeof(struct _list));
	list->head = NULL;
	list->size=0;
	//returnt he list;
	return list;
}
void freePkmnList(PkmnList list) {
	Pkmn curr = list->head;
	Pkmn prev = NULL;
	//if there is no pokemon in list just return
	if(curr==NULL) {
		return;
	} else {
		//else set the value of the node to NULL and free the node
		while(curr!=NULL) {
			prev=curr;
			curr=prev->next;
			free(prev);
		}
	}
}
void addPkmnToList(PkmnList list, Pkmn pkmn) {
	Pkmn curr = list->head;
	//if the list is empty make the pokemon the head;
	if(curr==NULL) {
		list->head = pkmn;
		pkmn->current=1;
	} else {
		//else add the pokemon to the end of the list
		while(curr->next!=NULL&&list->size>1) {
			//if the pokemon already exists in the list return;
			if(curr->id==pkmn->id) {
				return;
			}
			curr = curr->next;
		}
		curr->next=pkmn;
	}
	//add 1 to the list size
	list->size=list->size+1;
}
void printPkmnList(PkmnList list) {
	Pkmn curr = list->head;
	int i;
	char temp[PKMN_NAME_LENGTH]= {0};
	//if there are no pokemon in list print message and return
	if(list->size==0) {
		printf("No Pokemon in list.\n");
		return;
	} else {
		while(curr!=NULL) {
			//if a pokemon is hidden store the name into a different array temp and change all letters to asterisk 
			//if the pokemon is the current pokemon print the arrow/id/name
			//if the pokemon is not found print the temp array of asterisks but always print id
			if(curr->current==1) {
				printf("-->");
				printf(" #%03d: ", curr->id);
				if(curr->found==0) {
					for (i=0;curr->name[i]!='\0';i++) {
						temp[i]='*';
					}
					printf("%s\n",temp);
				} else {
					printf("%s\n",curr->name);
				}
			} else {
				printf("    #%03d: ",curr->id);
				if(curr->found==0) {
					for (i=0;curr->name[i]!='\0';i++) {
						temp[i]='*';
					}
					printf("%s\n",temp);
				} else {
					printf("%s\n",curr->name);
				}
			}
			//make sure the temp array is being reinitalised to 0 for when a new pokemon is being printed.
			for (i=0;i<PKMN_NAME_LENGTH;i++) {
				temp[i]=0;
			}
			curr=curr->next;
		}
	}
}
void nextPkmn(PkmnList list) {
	Pkmn curr = list->head;
	//if the pokemon is at the end of the list do nothing;
	if(curr->next==NULL) {
		return;
	}
	//find the current pokemon
	while(curr->current==0&&curr->next!=NULL) {
		curr=curr->next;
	}
	//if the current pokemon is at the end of the list do nothing
	if(curr->next==NULL) {
		return;
	} else {
		//else turn off switch for current pokemon
		//and turn on switch for the next pokemon
		curr->current = 0;
		curr->next->current = 1;
	}
}
void prevPkmn(PkmnList list) {
	Pkmn curr = list->head;
	//if the pokemon is at the start of the list do nothing
	if(list->head->next==NULL) {
		return;
	}
	//if the head is the current pokemon do nothing
	if(list->head->current==1) {
		return;
	}
	//else traverse to the pokemon before the current pokemon
	while(curr->next->current==0&&curr->next!=NULL) {
		curr=curr->next;
	}
	//turn the current switch on for the pokemon 
	//and turn the current switch on for the next pokemon
	curr->current = 1;
	curr->next->current = 0;
}
void jumpToPkmn(PkmnList list, int id) {
	Pkmn curr = list->head;
	Pkmn temp = list->head;
	//find the current pokemon
	while(temp->current!=1&&temp->next!=NULL) {
		temp = temp->next;
	}
	//find the pokemon in the list corresponding to the id given
	while(curr->id!=id) {
		//if the pokemon doesnt exist then keep the current pokemon the same and return
		if(curr->next==NULL) {
			temp->current = 1;
			return;
		}
		//else change every pokemon's current switch to 0 until you find the pokemon with the id given
		curr->current = 0;
		curr = curr->next;
	}
	//when found turn the current switch on for the pokemon with the id
	curr->current = 1;
	while(curr->next!=NULL) {
		//and go back and turn off any current switch for every pokemon before the current pokemon
		curr = curr->next;
		curr->current = 0;
	}
}
void removePkmn(PkmnList list) {
	//if the list is empty do nothing
	if(list->size==0) {
		return;
	}
	//if the list has only 1 pokemon delete the pokemon and decrement 1 from the list size
	if(list->size==1) {
		list->head = NULL;
		list->size--;
		return;
	}
	Pkmn curr = list->head;
	Pkmn temp = list->head;
	//this removes the current pokemon
	//if the current pokemon is the head
	//set the next node as the head and make it the current pokemon.. decrement 1 from list size
	if(list->head->current==1) {
		list->head = list->head->next;
		list->head->current = 1;
		list->size--;
	} else {
		//else find the current pokemon by traversing the list
		while(curr->next->current!=1) {
			curr = curr->next;
			temp = temp->next;
		}
		//if the current pokemon is the last pokemon in the list
		//set the pokemon before it as the current and remove the last pokemon
		//subtract 1 from list size
		if(curr->next->next==NULL) {
			curr->next = NULL;
			curr->current = 1;
			list->size--;
		} else {
			//else set the pokemon after the current pokemon as the current
			//subtract 1 from list size
			curr->next = curr->next->next;
			curr->next->current = 1;
			list->size--;
		}
	}
}
// Stage 3 Functions
void findPkmn(int seed, int factor, int numberOfNewPkmn, PkmnList list) {
	Pkmn curr = list->head;
	//an error check, if the user tries to find more pokemon then there are in the list change it to the list size (max pokemon)
	if(numberOfNewPkmn>list->size) {
		numberOfNewPkmn=list->size;
	}
	//start a random number generator and a counter
	int i = 0;
	srandom(seed);
	int random;
	//while the counter is less than the number of pokemon being searched for
	while(i<numberOfNewPkmn) {
		//generate a random number
		random = rand()%factor;
		curr = list->head;
		//traverse the list
		while(curr!=NULL) {
			//if the random number corresponds to an id of a pokemon which has not been found, turn the found switch on and break;
			if(curr->id==random&&curr->found==0) {
				curr->found =1;
				i++;
				break;
			}
			curr = curr->next;
		}
	}
}
int totalFound(PkmnList list) {
	//starting a counter
	int i = 0;
	Pkmn curr = list->head;
	while(curr!=NULL) {
		//traverses whole list, if a pokemon is found add 1 to counter
		if(curr->found==1) {
			i++;
		}
		curr = curr->next;
	}
	//return the counter
	return i;
}
// Stage 4 Functions
void addEvolution(PkmnList list, int pkmnId, int evolutionId) {
	Pkmn curr = list->head;
	while(curr->id!=pkmnId) {
		//if the pokemon with the id doesnt exit return;
		//else find the pokemon with the id corresponding to the id input
		if(curr->next==NULL) {
			return;
		}
		curr = curr->next;
	}
	//a pokemon has an evolution to a correspodning pokemon id with curr->evolution = id of evolution
	//if the curr->Evolution = 0 means no evolution
	//if it already has an evolution return;
	if(curr->evolution!=0) {
		return;
	}
	//else set its evolution to the id of evolution given
	curr->evolution = evolutionId;
}
void showEvolutions(PkmnList list) {
	Pkmn curr = list->head;
	Pkmn temp = list->head;
	char hold[PKMN_NAME_LENGTH] = {0};
	int i;
	//if there is no pokemon in the list return;
	if(curr==NULL) {
		return;
	}
	//find the current pokemon
	while(curr->current==0) {
		curr = curr->next;
	}
	//print the current pokemon similair to print list always prints the current pokemon in all situations
	if(curr->found==0) {
		for (i=0;curr->name[i]!='\0';i++) {
			hold[i]='*';
		}
		printf("#%03d %s",curr->id,hold);
	} else {
		printf("#%03d %s",curr->id,curr->name);
	}
	//if it has no evolutions return;
	if(curr->evolution==0) {
		printf("\n");
		return;
	} else {
		//until the evolution chain stops i.e till u arrive to a pokemon with curr->evolution = 0 (no evolution)
		while(curr->evolution!=0) {
			//traverse the list till you find the pokemon id with the curr->evolution of the current pokemon
			while(temp->id!=curr->evolution) {
				//if the pokemon is not yet in the list print 5 question marks, the id of the evolution and return;
				//else keep going till you find the pokemon with the id corresponding to the evoltion (this is the return of this loop)
				if(temp->next==NULL) {
					printf(" --> #%03d ????? \n",curr->evolution);
					return;
				}
				temp = temp->next;
			}
			//if the pokemon evolution is not found print the chain (-->) and the name with asterisks similair to the way it was done beforehand 
			if(temp->found==0) {
				for (i=0;temp->name[i]!='\0';i++) {
					hold[i]='*';
				}
				printf(" --> #%03d %s",temp->id,hold);
			} else {
				//else print the name and chain
				printf(" --> #%03d %s",temp->id,temp->name);
			}
			//set the current evolution to the evolution of the pokemon which was found to be the evolution
			//restart the process by setting temp to list->head
			//and restarting the asterisk array
			curr->evolution = temp->evolution;
			temp = list->head;
			for (i=0;i<PKMN_NAME_LENGTH;i++) {
				hold[i]=0;
			}
		}
	}
	//print a new line at the end
	printf("\n");
}
// Stage 5 Functions
PkmnList getPkmnOfType(PkmnList list, int type) {
	Pkmn curr = list->head;
	//create a new list
	PkmnList new = createPkmnList();
	//traverse the list
	while(curr!=NULL) {
		//if a pokemon's type1 or type2 corresponds to the input type
		//append it to the new list
		if(curr->type1==type||curr->type2==type) {
			addPkmnToList(new,curr);
		}
		curr = curr->next;
	}
	//return the new list
	return new;
}
PkmnList getFoundPkmn(PkmnList list) {
	Pkmn curr = list->head;
	//create a new list;
	PkmnList new = createPkmnList();
	Pkmn curr2 = new->head;
	//to store in id ascending order, using similair style to lab 10, sorted_insert
	while(curr!=NULL) {
		//traverse the list
		//if the pokemon is found begin the sorted insert
		if(curr->found==1) {
			//if the new list has no pokemon make the found pokemon the head of the list
			if(curr2==NULL) {
				addPkmnToList(new,curr);
			} else if(new->head->id>curr->id) {
				//if the new pokemon has a lower id value than the head, make the new pokemon the head of the list and shift the old head across
				curr->next = new->head;
				new->head = curr;
			} else {
				//else go through new list till either you find a pokemon with a greater id value than the pokemon being entered or if it arrives at the end of the list
				while(curr2->next!=NULL&&curr2->next->id<curr->id) {
					curr2 = curr2->next;
				}
				//set the newpokemon before the pokemon with greater id (sorted insert) and shift across 1
				curr->next=curr2->next;
				curr2->next = curr;
			}
		}
		//moving across the original list
		curr = curr->next;
	}
	//return new list;
	return new;
}
PkmnList searchByName(PkmnList list, char text[]) {
	Pkmn curr = list->head;
	PkmnList new = createPkmnList();
	int i,j,check,count1,count2;
	//traversing the list
	while(curr!=NULL) {
		//checking if text is a substring of pkmn curr->name
		//counts characters of both name of pokemon and the text entered
		count1 = 0;
		count2 = 0;
		while(curr->name[count2]!='\0') {
			//changes everything to lowercase (so case sensitivity is not a problem)
			curr->name[count2]=tolower(curr->name[count2]);
			count1++;
		}
		while(text[count2]!='\0') {
			//changes everything to lowercase (so case sensitivity is not a problem)
			curr->name[count2]=tolower(curr->name[count2]);
			count2++;
		}
		for (i=0;i<=count1-count2;i++) {
			for (j=i;j<i+count2;j++) {
				//set the substring check to 1
				check = 1;
				//if the entered string stops becoming a substring of the pokemon name set the check = 0 and break
				if(curr->name[j]!=text[j-i]) {
					check = 0;
					break;
				}
			}
			if(check == 1) {
				//if the substring check was successful break;
				break;
			}
		}
		//if the text is a substring of the pokemon name add it to the list
		if(check==1) {
			addPkmnToList(new,curr);
		}
		curr = curr->next;
	}
	return new;
}
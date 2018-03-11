#include "Stack.h"
#include "Pancake.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct stack {
	int numPancakes;
	char *Pancake_array[MAX_PANCAKES+1];
	int stacksize[MAX_PANCAKES];
}
;
Stack createStack(void) {
	Stack s = malloc(sizeof(struct stack));
	 memset(s->Pancake_array,0,MAX_PANCAKES-1);
	 memset(s->stacksize,0,MAX_PANCAKES-1);
	 s->numPancakes=0;
	return s;
}
// if stack is already full, do nothing
void addPancake(Stack s, char *topping, int size) {
	int i = 0;
	while(s->Pancake_array[i]!=0){
		i++;	
	}
	if(i>MAX_PANCAKES-1) {
		return;
	}
	s->Pancake_array[i]=topping;
	s->stacksize[i]=size;
}
// if stack is already empty, do nothing
void eatPancake(Stack s) {
	int i = 0;
	while(s->Pancake_array[i]!=0){
		i++;
	}
    if(i<0){
    	return;
    }
	 else {
		s->Pancake_array[i]=0;
		s->stacksize[i]=0;
	}
}
int numPancakes(Stack s) {
	int i;
	while(s->Pancake_array[s->numPancakes]!=0) {
		s->numPancakes++;
	}
	i=s->numPancakes;
	//since array index starts 0!
	return i;
}
int totalSize(Stack s) {
	int i;
	int length = 0;
	int size = 0;
    while(s->Pancake_array[length]!=0){
		length++;
	}
	for (i=0;i<length;i++) {
		size = size + s->stacksize[i];
	}
	return size;
}
void printToppings(Stack s) {
	int i = 0;
	while(s->Pancake_array[i]!=0) {
		printf("%s\n",s->Pancake_array[i]);
		i++;
	}
}
void consumeStack(Stack s) {
	int i;
	int length = numPancakes(s);
	for (i=0;i<length;i++) {
		s->Pancake_array[i]=0;
	}
	free(s);
}

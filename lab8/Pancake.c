#include "Pancake.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct pancake {
    char *topping;
    int size;
};

Pancake bake(char *topping, int size) {
    if(topping == NULL){
        printf("I have never heard of that topping\n");
        exit(1);
    }
    // Allocate enough space for a pancake
    Pancake p = malloc(sizeof(struct pancake));
    // Copy the string pointed to be topping to a new
    // piece of memory and point p->topping to it
    p->topping = strdup(topping);
    p->size = size;
    return p;
}

void eat(Pancake p) {
    // Free the string pointed to by topping
    if(p == NULL){
        printf("Can't eat no pancake\n");
        exit(1);
    }
    free(p->topping);
    // Free the pancake struct
    free(p);
}

int getSize(Pancake p) {
     if(p == NULL){
        printf("No pancake given\n");
        exit(1);
    }
    return p->size;
}

char *getTopping(Pancake p) {
     if(p == NULL){
        printf("No pancake given\n");
        exit(1);
    }
    return p->topping;
}
#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"
#include <assert.h>

void testEmpty(void);
void testOne(void);
void testManyPancakes(void);
void testTooManyPancakes(void);

int main(void) {

      
    testEmpty();
    testOne();
    testManyPancakes();
    testTooManyPancakes();
    return 0;
}


void testEmpty(){
    printf("Testing empty stack\n");
    
    Stack s = NULL;
    s = createStack();
    assert(s != NULL);  
    
    printf("%d\n", numPancakes(s));
    assert(numPancakes(s) == 0);

    assert(totalSize(s) == 0);
    printf("%d\n",totalSize(s));

    eatPancake(s);
    
    printToppings(s);
    printf("\n");
    consumeStack(s);
}

void testOne(void){
    printf("Testing one pancake\n");
    Stack s = NULL;
    s = createStack();
    assert(s != NULL); 
    

    addPancake(s, "blueberry",10);
    
    printf("%d\n", numPancakes(s));
    assert(numPancakes(s) == 1);

    assert(totalSize(s) == 10);
    printf("%d\n",totalSize(s));

    printToppings(s);
    printf("\n");
    eatPancake(s);

    consumeStack(s);
}

void testManyPancakes(void){
    printf("Testing a lot of blueberry pancakes\n");
    Stack s = NULL;
    s = createStack();
    assert(s != NULL); 

    int i;
    for(i = 0; i < MAX_PANCAKES; i++){
        addPancake(s, "blueberry",10);
    }

    printf("%d\n", numPancakes(s));
    assert(numPancakes(s) == 40);

    assert(totalSize(s) == 400);
    printf("%d\n",totalSize(s));

    printToppings(s);
    printf("\n");
    consumeStack(s);

}

void testTooManyPancakes(void){
    printf("Testing too many blueberry pancakes\n");
    Stack s = NULL;
    s = createStack();
    assert(s != NULL); 

    int i;
    for(i = 0; i < MAX_PANCAKES+3; i++){
        addPancake(s, "blueberry",10);
    }

    printf("%d\n", numPancakes(s));
    assert(numPancakes(s) == 40);

    assert(totalSize(s) == 400);
    printf("%d\n",totalSize(s));

    printToppings(s);
    printf("\n");
    consumeStack(s);

}




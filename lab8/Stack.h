typedef struct stack* Stack;

#define MAX_PANCAKES 40

// Creates an empty stack with zero pancakes
Stack createStack(void);

// Adds a pancake to top the stack
void addPancake(Stack s, char *topping, int size);

// Removes the most recently added pancake from the stack
void eatPancake(Stack s);

// Returns the number of pancakes in the stack
int numPancakes(Stack s);

// Returns the cumulative size of all the pancakes in the stack
int totalSize(Stack s);

// Prints the toppings of all the pancakes in the stack
// From top to bottom (most to least recently added)
void printToppings(Stack s);

// Removes all pancakes then destroys the stack
void consumeStack(Stack s);

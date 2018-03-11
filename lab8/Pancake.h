// Forward declaration of Pancake so compiler
// knows how to handle in function declarations
typedef struct pancake * Pancake;

// Returns a new pancake
Pancake bake(char *topping, int size);

// Frees a pancake?
void eat(Pancake p);

// Returns the pancake topping as a string
char *getTopping(Pancake p);

// Returns the size of the pancake
int getSize(Pancake p);
#ifndef HEADER_FILENAME
#define HEADER_FILENAME

# define STEPS 4

// colors

# define RESET "\e[0m"
# define YEL "\e[1;33m"
# define BLU "\e[1;34m"
# define RED "\e[1;31m"
# define GRN "\e[0;32m"

void sceneOne(int *hp, int *money, FILE *f);
void sceneTwo(int *hp, FILE *f);
void sceneThree(int *hp, int *money, Inventory *inv, FILE *f);
void sceneFour(int *hp, Inventory *inv, FILE *f);

void playRandomScene(int *hp, int *money, Inventory *inv, FILE *f);
void umbrellaRoute(int *hp, int *money, Inventory *inv);


#endif

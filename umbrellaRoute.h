#ifndef HEADER_FILENAME
#define HEADER_FILENAME

# define STEPS 4

// colors

# define RESET "\e[0m"
# define YEL "\e[1;33m"
# define BLU "\e[1;34m"
# define RED "\e[1;31m"
# define GRN "\e[0;32m"

void sceneOne(int *hp, int *money);
void sceneTwo(int *hp);
void sceneThree(int *hp, int *money, Inventory *inv);
void sceneFour(int *hp, Inventory *inv);

void playScenes (int * hp, Inventory * inv)
int umbrellaRoute(int *hp, int *money, Inventory *inv);

#endif

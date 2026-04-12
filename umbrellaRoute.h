#ifndef HEADER_FILENAME
#define HEADER_FILENAME

void sceneOne(int *hp, int *money, FILE *f);
void sceneTwo(int *hp, FILE *f);
void sceneThree(int *hp, int *money, Inventory *inv, FILE *f);
void sceneFour(int *hp, Inventory *inv, FILE *f);

void playRandomScene(int *hp, int *money, Inventory *inv, FILE *f);
void umbrellaRoute(int *hp, int *money, Inventory *inv);


#endif

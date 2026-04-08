#ifndef HEADER_FILENAME
#define HEADER_FILENAME

// player struct

typedef struct 
{ 
	int hp; 
	int money; 
}Player;

// secret inventory struct

typedef struct
{
  char items[MAX_SPECIAL][SIZE];
  int count;
  
  int EB;
  int GC;
  int UM;
  int RC;
  
} SpecialInventory;

// quit function

char quit();

// routes

void grilledRoute (int *health, int *money, Inventory *inv);
void umbrellaRoute (int *health, int *money, Inventory *inv);

// other

void routeReset (int list[], int size);
int routeCheck (int list[], int size);

#endif

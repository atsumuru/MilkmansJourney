/*****************************************************
*
*File: creamCrop
*Author: Esra P & Payton P
*Purpose: One piece of a milky adventure (Final Project
*Version: 1.1 Apr 11, 2026
*
******************************************************/
#ifndef HEADER_FILENAME
#define HEADER_FILENAME 

#include "grilledRoute.h"
#include "umbrellaRoute.h" 
#include "chickenRoute.h"
#include "bottleRoute.h"


// player struct

typedef struct 
{ 
	int hp; 
	int money; 
}Player;

// secret inventory struct

# define MAX_SPECIAL 5
# define SIZE 50

typedef struct
{
  char items[MAX_SPECIAL][SIZE];
  int count;
  
  int EB;
  int GC;
  int UM;
  int RC;
  
} Inventory;

// inventory functions

void initSpecial (Inventory * inv);
void addSpecial (Inventory * inv, char itemName[]);
void displaySpecial (Inventory * inv);
void menuChoice (Inventory * inv);

// quit function

char quit(void);

#endif
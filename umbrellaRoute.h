/*******************************************************
*File:	   umbrellaRoute.h
*Author:   Payton Phillips
*Purpose:  This program is the header file for the umbrellaRoute. It contains all functions and defined variables.
*Version:  1.0 April 9, 2026  
*
********************************************************/

# ifndef HEADER_FILENAME
# define HEADER_FILENAME

# define STEPS 4

// colors

# define RESET "\e[0m"
# define YEL "\e[1;33m"
# define BLU "\e[1;34m"
# define RED "\e[1;31m"
# define GRN "\e[0;32m"

void sceneOne(int *hp, int *money);
void sceneTwo(int *hp, int *money);
void sceneThree(int *hp, int *money, Inventory *inv);
void sceneFour(int *hp, int *money, Inventory *inv);

void playRandomScene(int *hp, int *money, Inventory *inv);
int umbrellaRoute(int *hp, int *money, Inventory *inv);

# endif

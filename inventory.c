/*******************************************************
*File:	  inventory.c
*Author:  Payton Phillips
*Purpose: This program allows the player to access the inventory.
*Version: 1.0 April 1, 2026
*         1.1 April 6, 2026
*         1.2 April 9, 2026
*
********************************************************/

# include <stdio.h>
# include <string.h>

# include "creamCrop.h"

# define MAX_SPECIAL 5
# define SIZE 50

// struct for special inv

typedef struct
{
  char items[MAX_SPECIAL][SIZE];
  int count;
  
  int EB;
  int GC;
  int UM;
  int RC;
  
} Inventory;

// initialize special inv

void initSpecial(Inventory * inv)
{
  int i;

  inv -> count = 0;
  for (i = 0; i < MAX_SPECIAL; i++)
  {
    strcpy(inv -> items[i], ".....");
  }
  
  inv -> EB = 0;
  inv -> GC = 0;
  inv -> UM = 0;
  inv -> RC = 0;
}

// add special items

void addSpecial(Inventory * inv, char itemName[])
{
  if (inv -> count < MAX_SPECIAL)
  {
    strcpy(inv -> items [inv->count], itemName);
    inv -> count++;
    
    printf("You found Special Item: %s\n", itemName);
    
    if (strcmp(itemName, "Empty Bottle") == 0)
    {
      inv -> EB = 1;
    }
      
    else if (strcmp(itemName, "Grilled Cheese") == 0)
    {
      inv -> GC = 1;
    }
      
    else if (strcmp(itemName, "Umbrella") == 0)
    {
      inv -> UM = 1;
    }
    else if (strcmp(itemName, "Rubber Chicken of Doom") == 0)
    {
      inv -> RC = 1;
    }
    
  }
  else
  {
    printf("Inventory full!\n");
  }
}

// display special inv

void displaySpecial(Inventory * inv)
{
  int i;

  printf("\n --- INVENTORY --- \n");
  for (i = 0; i < MAX_SPECIAL; i++)
  {
    printf("Slot %d: %s\n", i + 1, inv -> items[i]);
  }
}

void menuChoice (Inventory * inv)
{
  int choice = 0;
  
  while (choice != 2)
  {
    printf("\n --- MENU --- \n");
    printf("1. View Inventory\n");
    printf("2. Continue On\n");
    printf("\n");
    
    printf("Choose option: ");
    scanf("%d", &choice);
    
    switch (choice)
    {
      case 1:
        displaySpecial(inv);
        break;
      
      case 2:
        // back to game
        break;
        
      default:
        printf ("Invalid option.\n");
        break;
    }
  }
}

/*******************************************************
*File:	  inventory.c
*Author:  Payton Phillips
*Purpose: This program allows the player to access the inventory.
*Version: 1.0 April 1, 2026
*         1.1 April 6, 2026
*
********************************************************/

# include <stdio.h>
# include <string.h>

# include "creamCrop.h"

# define MAX_SPECIAL 5
# define MAX_SECRET 4
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
  
} SpecialInventory;

// initialize player stats

void initPlayer(Player * p)
{
  p -> hp = 100;
  p -> money = 20;
}

// display player stats

void displayStats(Player * p)
{
  printf("\n --- [PLAYER STATS] --- \n");
  printf("HP: %d\n", p -> hp);
  printf("Money: %d\n", p -> money);
}

// initialize special inv

void initSpecial(SpecialInventory * inv)
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

void addSpecial(SpecialInventory * inv, char itemName[])
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

void displaySpecial(SpecialInventory * inv)
{
  int i;

  printf("\n --- INVENTORY --- \n");
  for (i = 0; i < MAX_SPECIAL; i++)
  {
    printf("Slot %d: %s\n", i + 1, inv -> items[i]);
  }
}

// main

int main () {
  Player player;
  SpecialInventory special;
  
  int choice = 0;
  
  initPlayer(&player);
  initSpecial(&special);
  
  while (choice != 4)
  {
    printf("\n --- MENU --- \n");
    printf("1. View [PLAYER STATS]\n");
    printf("2. View Inventory\n");
    printf("3. Back to Game\n");
    printf("\n");
    
    printf("Choose option: ");
    scanf("%d", &choice);
    
    switch (choice)
    {
      case 1:
        displayStats(&player);
        break;
      
      case 2:
        displaySpecial(&special);
        break;
      
      case 3:
        // back to game
        break;
        
      default:
        printf ("Invalid option.\n");
        break;
    }
  }

  return 0;
}

# include <stdio.h>
# include <string.h>

# define MAX_SPECIAL 5
# define MAX_SECRET 4
# define SIZE 50

// struct for player

typedef struct
{
  int health;
  int money;
} Player;

// struct for special inv

typedef struct
{
  char items[MAX_SPECIAL][SIZE];
  int count;
  
  int emptyBottle;
  int grilledCheese;
  int umbrella;
  int rubberChicken;
  
} SpecialInventory;

// struct for secret inv

typedef struct
{
  char items[MAX_SECRET][SIZE];
  int count;
  
  int butter;
  int yogurt;
  int iceCream;
  int cheese;
  
} SecretInventory;

// initialize player stats

void initPlayer(Player * p)
{
  p -> health = 100;
  p -> money = 0;
}

// display player stats

void displayStats(Player * p)
{
  printf("\n --- [PLAYER STATS] --- \n");
  printf("Health: %d\n", p -> health);
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
  
  inv -> emptyBottle = 0;
  inv -> grilledCheese = 0;
  inv -> umbrella = 0;
  inv -> rubberChicken = 0;;
}

// initialize secret inv

void initSecret(SecretInventory * inv)
{
  int i;

  inv -> count = 0;
  for (i = 0; i < MAX_SECRET; i++)
  {
    strcpy(inv -> items[i], ".....");
  }
  
  inv -> butter = 0;
  inv -> yogurt = 0;
  inv -> iceCream = 0;
  inv -> cheese = 0;
}

// add special items

void addSpecial(SpecialInventory * inv, char itemName[])
{
  if (inv -> count < MAX_SPECIAL)
  {
    strcpy(inv -> items [inv->count], itemName);
    inv -> count++;
    
    printf("You found [SPECIAL ITEM]: %s\n", itemName);
    
    if (strcmp(itemName, "Empty Bottle") == 0)
    {
      inv -> emptyBottle = 1;
    }
      
    else if (strcmp(itemName, "Grilled Cheese") == 0)
    {
      inv -> grilledCheese = 1;
    }
      
    else if (strcmp(itemName, "Umbrella") == 0)
    {
      inv -> umbrella = 1;
    }
    else if (strcmp(itemName, "Rubber Chicken of Doom") == 0)
    {
      inv -> rubberChicken = 1;
    }
    
  }
  else
  {
    printf("[SPECIAL ITEM] Inventory full!\n");
  }
}

// add secret items

void addSecret(SecretInventory * inv, char itemName[])
{
  if (inv -> count < MAX_SECRET)
  {
    strcpy(inv -> items [inv -> count], itemName);
    inv -> count++;
    printf("You found [SECRET ITEM]: %s\n", itemName);
    
    if (strcmp(itemName, "Butter") == 0)
    {
      inv -> butter = 1;
    }
      
    else if (strcmp(itemName, "Yogurt") == 0)
    {
      inv -> yogurt = 1;
    }
      
    else if (strcmp(itemName, "Ice Cream") == 0)
    {
      inv -> iceCream = 1;
    }
    else if (strcmp(itemName, "Cheese") == 0)
    {
      inv -> cheese = 1;
  }
  else
  {
    printf("[SECRET ITEM] Inventory full!\n");
  }
}

// display special inv

void displaySpecial(SpecialInventory * inv)
{
  int i;

  printf("\n --- [SPECIAL ITEMS] --- \n");
  for (i = 0; i < MAX_SPECIAL; i++)
  {
    printf("Slot %d: %s\n", i + 1, inv -> items[i]);
  }
}

// display secret inv

void displaySecret(SecretInventory * inv)
{
  int i;

  printf("\n --- [SECRET ITEMS] --- \n");
  for (i = 0; i < MAX_SECRET; i++)
  {
    printf("Slot %d: %s\n", i + 1, inv -> items[i]);
  }
}

// main

int main () {
  Player player;
  SpecialInventory special;
  SecretInventory secret;
  
  int choice = 0;
  
  initPlayer(&player);
  initSpecial(&special);
  initSecret(&secret);
  
  while (choice != 4)
  {
    printf("\n --- [MENU] --- \n");
    printf("1. View [PLAYER STATS]\n");
    printf("2. View [SPECIAL ITEM] Inventory\n");
    printf("3. View [SECRET ITEM] Inventory\n");
    printf("4. Back to Game\n");
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
        displaySecret(&secret);
        break;
        
      case 4:
        // back to game
        break;
        
      default:
        printf ("Invalid option.\n");
        break;
    }
  }

  return 0;
}

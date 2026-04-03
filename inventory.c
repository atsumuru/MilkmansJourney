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
} SpecialInventory;

// struct for secret inv

typedef struct
{
  char items[MAX_SECRET][SIZE];
  int count;
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
}

// add special items

void addSpecial(SpecialInventory * inv, char itemName[])
{
  if (inv -> count < MAX_SPECIAL)
  {
    strcpy(inv -> items [inv->count], itemName);
    inv -> count++;
    
    printf("You found [SPECIAL ITEM]: %s\n", itemName);
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
  
  
  // addSpecial (&special, "enter name");
  // for adding special items from route
  
  // addSecret (&secret, "enter name");
  // for adding secret items from route
  
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

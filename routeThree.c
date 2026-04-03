# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "creamCrop.h"

# define SIZE 6

int routeThree (int * health, int * money)
{
  int scenario;
  
  printf ("\n --- [ROUTE THREE] --\n"); // just for seperation rn

  scenario = rand() % 4;
  
  if (scenario == 0)
  {
    int i;
    int success = 0;
    
    int correctPath[SIZE] = {1,3,2,2,3,1};
    int playerPath[SIZE];
    
    printf ("\nYou stumble forward from the darkness, following the light.\n");
    printf ("What awaits you isn't what you expected. You find yourself in a room full of mirrors.\n");
    printf ("\nYou have entered the [MIRROR MAZE].\n");
    
    printf ("As you look around at your surrounds, you spot a milk jug.\n");
    printf ("The image was being reflected off the mirrors, but you decide to try and reach it.\n");
    printf ("\n[NOTE]: You must enter the correct directions to be able to pass!\n");
    
    printf ("\nPlease enter a direction: \n");
    printf ("1. Left\n");
    printf ("2. Right\n");
    printf ("3. Forward\n");
    
    
    while (success == 0)
    {
    
      for (i = 0; i < SIZE; i++)
      {
        printf ("Step %d: ", i+1);
        scanf ("%d", &playerPath[i]);
      }
    
      success = 1;
      
      for (i=0; i < SIZE; i++)
      {
        if (playerPath[i] != correctPath[i])
        {
          success = 0;
          break;
        }
      }
    
      if (success == 1)
      {
        printf ("You have successfully reached the milk jug!\n");
        printf ("But, suddenly, the milk jug turns into a puddle of milk!!\n");
        printf ("You fall to the ground in disbelief that the jug hs escaped you,\n");
        printf ("and then you proceed to slip and fall through the puddle!\n");
        
        printf ("\nYou lose 5 health due to the shock,\n");
        printf ("but you gain 10 money for correctly finishing the maze!");
        
        * health -= 5;
        * money += 10;
      }
      else
      {
        printf ("You accidentally run face first into a mirror and get disoriented.\n");
        printf ("You lose 1 health.\n");
        printf ("\nTry again! :)\n");
        
        * health -= 1;
      }
    }
  }
  else if (scenario == 1)
  {
    int throwChoice;
    
    printf ("\nAs you travel down a long forest trail, you begin to hear rustling in the bushes.\n");
    printf ("\nBAM!\n");
    printf ("You are now surrounded by a group of [MILK BANDITS]!\n");
    printf ("They demand that you surround all of your money, as well as your [INSERT SPECIAL ITEM]!\n"); // prolly the ice cream, if im incorporating it the correct way.
    
    printf ("You then remember that you have the [RUBBER CHICKEN OF DOOM]!\n");
    
    printf ("\nWhat do you do?\n");
    printf ("1. Throw [RUBBER CHICKEN OF DOOM] at the Leader\n");
    printf ("2. Run\n");
    printf ("3. Surrender your money and [SPECIAL ITEM]\n\n");
    
    printf ("Enter: ");
    scanf ("%d", &throwChoice);
    
    if (throwChoice == 1)
    { 
      printf ("The [MILK BANDIT] Leader is stunned!\n");
      printf ("They retreat due to the threat of the [RUBBER CHICKEN OF DOOM].\n");
      printf ("You escape safely (and manage to pick up some loot they dropped! ;)\n");
      printf ("\nYou gain 15 money.\n");
      
      * money += 15;
    }
    else if (throwChoice == 2)
    {
      printf ("You attempt to flee!\n");
      printf ("As you run, you trip and fall and,\n");
      printf ("the [RUBBER CHICKEN OF DOOM] falls out of your inventory!\n");
      printf ("It is now in possession of the [MILK BANDITS].\n");
      
      printf ("You lose 5 money, as you continue to run.\n");
      
      * money -= 5;
    }
    else
    {
      printf ("You surrender your money and the [SPECIAL ITEM].\n");
      printf ("\n... You have 0 money ...\n");
      
      * money = 0;
    }
    
  }
  else if (scenario == 2)
  {
    // follow the cow
  }
  else if (scenario == 3)
  {
    // marketplace, must bargain with the milk seller
  }
  
return scenario;
  
}

int main ()
{
  srand (time(NULL));
  
  return 0;
}

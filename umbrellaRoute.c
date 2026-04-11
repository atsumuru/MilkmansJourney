/*******************************************************
*File:	   umbrellaRoute.c
*Author:   Payton Phillips
*Purpose:  This program plays the mirror realm route, which contains four scenes and function to randomize them.
*Version:  1.0 April 1, 2026
*          1.1 April 9, 2026  
*          1.2 April 10, 2026        
*
********************************************************/

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "creamCrop.h"
# include "umbrellaRoute.h"

// scene one

void sceneOne (int * hp, int * money, FILE *f)
{
  int i;
  int success = 0;
  
  int correctPath[STEPS] = {1,3,2,1};
  int playerPath[STEPS];
  
  printf ("\n\n***");
  
  printf ("\n\nStumbling forward, you find MORE mirrors!\n");
  printf ("You let out a sigh of exasperation.\n");
  printf ("The milk jug appears again and you steel your resolve.\n\n");
  printf (YEL "For the milk!" RESET ", you think as you take a deep breath and push forward.\n");

  printf (BLU "\nPlease enter a direction: \n");
  printf ("1. Left\n");
  printf ("2. Right\n");
  printf ("3. Forward\n" RESET);
  
  // ***
  
  fprintf (f, "\n\nStumbling forward, you find MORE mirrors!\n");
  fprintf (f, "You let out a sigh of exasperation.\n");
  fprintf (f, "The milk jug appears again and you steel your resolve.\n\n");
  fprintf (f, "For the milk!, you think as you take a deep breath and push forward.\n");
  
  // ***

  while (success == 0)
  {
    printf ("\n");
  
    for (i = 0; i < STEPS; i++)
    {
    
      printf ("Step %d: ", i+1);
      scanf ("%d", &playerPath[i]);
      
      while(playerPath[i] != 1 && playerPath[i] != 2 && playerPath[i] != 3)
      {
        printf ("\nInvalid input. Please enter 1,2, or 3.\n");
        printf ("Step %d: ", i+1);
        scanf ("%d", &playerPath[i]);
      }
    }
    
    success = 1;
    
    for (i = 0; i < STEPS; i++)
    {
      if (playerPath[i] != correctPath[i])
      {
        success = 0;
        break;
      }
    }
    
    if (success == 1)
    {
      printf ("\nYou have successfully reached the milk jug!\n\n");
      printf ("But, suddenly, the milk jug turns into a puddle of milk!!\n");
      printf ("You fall to the ground in disbelief that the jug has escaped you,\n");
      printf ("and then you proceed to slip and fall through the puddle!\n");
      
      printf ("\nYou " RED "lose 3 HP" RESET " due to the shock,\n");
      printf ("but you" GRN " gain 10 money" RESET " for correctly finishing the maze!\n");
      
      * hp -= 3;
      * money += 10;
      
      // ***
      
      fprintf (f, "\nYou go through the maze and successfully reached the milk jug!\n\n");
      fprintf (f, "But, suddenly, the milk jug turns into a puddle of milk!!\n");
      fprintf (f, "You fall to the ground in disbelief that the jug has escaped you,\n");
      fprintf (f, "and then you proceed to slip and fall through the puddle!\n");
      fprintf (f, "\nYou lose 3 HP due to the shock,\n");
      fprintf (f, "but you gain 10 money for correctly finishing the maze!\n");
      
      // ***
    }
    else
    {
      printf ("\nYou accidentally run face first into a mirror and get disoriented.\n");
      printf ("You " RED "lose 1 HP.\n" RESET);
      printf (YEL "\nTry again! :)\n" RESET);
      
      * hp -= 1;
      
      // ***
      
      fprintf (f, "\nYou accidentally run face first into a mirror and get disoriented.\n");
      fprintf (f, "You lose 1 HP.\n");
      
      // ***
    }
  }
}

// scene two

void sceneTwo (int * hp, int * money, FILE *f)
{
  int choice;
  int escape = 0;
  
  printf ("\n\n***");
  
  printf ("\n\nYou've landed in another room of mirrors.\n");
  printf ("You just sigh. Picking yourself back up.\n");
  
  printf ("\nAnd then you hear it.\n");
  
  printf ("\nThe rumble sound coming from behind you.\n");
  printf ("You turn around to find a" YEL" WAVE OF MILK" RESET" heading straight for you.\n");
  printf ("You quickly begin to run, with a single thought running through your head.\n");
  
  printf (YEL "\nIs the milk truely worth it?" RESET);
  
  // ***

  fprintf (f, "\n\nYou've landed in another room of mirrors.\n");
  fprintf (f, "You just sigh. Picking yourself back up.\n");
  fprintf (f, "\nAnd then you hear it.\n");
  fprintf (f, "\nThe rumble sound coming from behind you.\n");
  fprintf (f, "You turn around to find a WAVE OF MILK heading straight for you.\n");
  fprintf (f, "You quickly begin to run, with a single thought running through your head.\n");
  fprintf (f, "\nIs the milk truely worth it?");
  
  // ***
  
  while (escape == 0)
  {
    printf (BLU "\n\nChoose what to do: \n");
    printf ("1. Run straight forward.\n");
    printf ("2. Proceed with caution.\n");
    printf ("\t(please note, there is a giant wave behind you.)\n");
    printf ("3. Smash a mirror to find a shortcut.\n" RESET);
    
    printf ("You choose: ");
    scanf("%d", &choice);
    
    if (choice == 1)
    {
      printf ("\nYou sprint forward.\n");
      
      // ***
      
      fprintf (f, "\nYou sprint forward.\n");
      
      // ***
      
      if (rand() % 2 == 0)
      {
        printf ("You crash into a mirror wall!\n");
        printf ("You get cut and " RED "lose 5 HP" RESET ".");
        
        * hp -= 5;
        
        printf (YEL "\nTry again! :)" RESET);
        
        // ***
        
        fprintf (f, "You crash into a mirror wall!\n");
        fprintf (f, "You get cut and lose 5 HP.");
        
        // ***
        
      }
      else
      {
        printf ("\nYou narrowly avoid a mirror collision.\n");
        printf ("\nYou push forward and spot a mirror doorway.\n");
        printf ("You run towards it, entirely aware of the wave getting closer and closer.\n");
        printf ("You finally reach the door, open it, and slam it shut behind you.\n\n");
        
        escape = 1;
        
        // ***
        
        fprintf (f, "\nYou narrowly avoid a mirror collision.\n");
        fprintf (f, "\nYou push forward and spot a mirror doorway.\n");
        fprintf (f, "You run towards it, entirely aware of the wave getting closer and closer.\n");
        fprintf (f, "You finally reach the door, open it, and slam it shut behind you.\n\n");
        
        // ***
      }
    }
    else if (choice == 2)
    {
      printf ("\nYou are too cautious and the milk wave crashes into you and pulls you under.\n");
      printf ("You " RED "lose 10 HP" RESET ".\n");
      printf (YEL "\nTry again! :)" RESET);
      
      * hp -= 10;
      
      // ***
      
      fprintf (f, "\nYou are too cautious and the milk wave crashes into you and pulls you under.\n");
      fprintf (f, "You lose 10 HP.\n");
      
      // ***
    }
    else if (choice == 3)
    {
      printf ("You purposefully slam yourself against one of the wall mirrors.\n\n");
      
      printf ("You take some minor damage " RED "(lose 3 HP)" RESET ", but you successfully find a hidden passage and escape!\n\n");
      
      * hp -= 3;
      escape = 1;
      
      // ***
      
      fprintf (f, "You purposefully slam yourself against one of the wall mirrors.\n\n");
      fprintf (f, "You take some minor damage (lose 3 HP), but you successfully find a hidden passage and escape!\n\n");
      
      // ***
    }
  }
}

// scene three

void sceneThree (int * hp, int * money, Inventory *inv, FILE *f)
{
  int choice;
  
  printf ("\n\n***");
  
  printf ("\n\nYou open your eyes and find a cow in front of you.\n");
  printf ("You blink.\n");
  printf ("A random cow.\n");
  printf ("In the middle of a mirror room. place. thingy.\n");
  printf ("Yeah, totally normal.\n\n");
  
  printf ("You and the cow stare at each other for\n");
  printf ("One second.\n");
  printf ("Two seconds.\n");
  
  printf ("The cow moos at you.\n");
  
  printf ("\nThis is getting weird and awkward.\n");
  printf ("\nThe cow finally starts moving along it's intended path.\n");
  
  printf ("You sit there in pure confusion for a bit until the thought occurs to you.\n");
  printf (YEL "Cow, milk. Cow must have milk.\n" RESET);
  printf ("So you make a decision.\n");
  
  printf (BLU "\nYou choose: \n");
  printf ("1. Follow the cow\n");
  printf ("2. Don't follow the cow.\n" RESET);
  
  printf ("\nYou enter: ");
  scanf ("%d", &choice);
  
  // ***
  
  fprintf (f, "\n\nYou open your eyes and find a cow in front of you.\n");
  fprintf (f, "You blink.\n");
  fprintf (f, "A random cow.\n");
  fprintf (f, "In the middle of a mirror room. place. thingy.\n");
  fprintf (f, "Yeah, totally normal.\n\n");
  fprintf (f, "You and the cow stare at each other for\n");
  fprintf (f, "One second.\n");
  fprintf (f, "Two seconds.\n");
  fprintf (f, "The cow moos at you.\n");
  fprintf (f, "\nThis is getting weird and awkward.\n");
  fprintf (f, "\nThe cow finally starts moving along it's intended path.\n");
  fprintf (f, "You sit there in pure confusion for a bit until the thought occurs to you.\n");
  fprintf (f, "Cow, milk. Cow must have milk.\n");
  fprintf (f, "So you make a decision.\n");
  
  // ***
  
  
  if (choice == 1)
  {
    printf ("\nYou proceed to follow the cow.\n");
    printf ("It takes you through several rooms before finally finding an open room,\n");
    printf ("made with only a limited numbers of mirrors.\n");
    
    printf ("The cow moos at you again to grab your attention.\n");
    printf ("\nHe gives you an " YEL "Umbrella, " GRN "10 money" RESET ", and you "GRN "earn 15 HP" RESET ".\n");
    printf ("(don't ask how. explaination: magic)\n\n");
    
    inv -> UM = 1;
    * money += 10;
    * hp += 15;
    
    
    printf ("You thank the cow and turn around to find a NEW doorway!\n");
    printf ("You bid the cow farewell befoe finally bracing yourself for what's to come.\n");
    
    // ***
    
    fprintf (f, "\nYou proceed to follow the cow.\n");
    fprintf (f, "It takes you through several rooms before finally finding an open room,\n");
    fprintf (f, "made with only a limited numbers of mirrors.\n");
    fprintf (f, "The cow moos at you again to grab your attention.\n");
    fprintf (f, "\nHe gives you an Umbrella, 10 money, and you earn 15 HP.\n");
    fprintf (f, "(don't ask how. explaination: magic)\n\n");
    fprintf (f, "You thank the cow and turn around to find a NEW doorway!\n");
    fprintf (f, "You bid the cow farewell befoe finally bracing yourself for what's to come.\n");
    
    // *** 
  }
  else
  {
    printf ("\nYou choose to ignore the cow.\n");
    printf ("Nothing major happens, and you continue forward.\n");
    printf ("You find a doorway and continue on.\n");
    printf ("You feel slightly disapointed.\n");
    
    // ***
    
    fprintf (f, "\nYou choose to ignore the cow.\n");
    fprintf (f, "Nothing major happens, and you continue forward.\n");
    fprintf (f, "You find a doorway and continue on.\n");
    fprintf (f, "You feel slightly disapointed.\n");
    
    // ***
  }

}

// scene four

void sceneFour (int * hp, int * money, Inventory * inv, FILE *f)
{
  int choice;
  int success = 0;
  
  printf ("\n\n***"); // for testing purposes

  printf ("\n\nYou find yourself inside an empty room with a single mirror in front of you.\n");
  printf ("You look around at your surroundings, with caution.\n\n");
  printf ("You look towards the mirror, slowly moving forward.\n");
  printf ("You find the milk jug.\n");
  printf ("Inside the mirror.\n");
  printf ("You examine the mirror.\n");
  
  printf ("\nYou sigh. " YEL "You just want your jug of milk!\n" RESET);

while (success == 0)
  {
    printf (BLU"\nYou choose to: \n");
    printf ("1. Bang on the mirror\n");
    printf ("2. Break the mirror.\n" RESET);
    
    if (inv -> RC == 1)
    {
    printf (BLU "3. Throw the " YEL "Rubber Chicken of Doom" RESET " at the mirror.\n" RESET);
    }
  
    printf ("\nYou enter: ");
    scanf ("%d", &choice);
    
    if (choice == 1)
    {
      if (inv -> RC == 0)
      {
        printf ("\nYou tap the mirror, only to find it's a portal.\n");
        printf ("You enter the mirror.\n");
        
        success = 1;
      }
      else
      {
        printf ("\nYou bang on the mirror. The milk jug disappears.\n");
        printf (YEL "Try again! :)\n" RESET);
      }
    }
    else if (choice == 2)
    {
      printf ("\nYou break the mirror but all that's left is broken glass on an empty frame.\n");
      printf ("You " RED "lose 1 HP" RESET ".");
      printf (YEL "\nTry again! :)\n" RESET);
      
      * hp -= 1;
    }
    else if (choice == 3 && inv -> RC == 1)
    {
      printf ("\nYou throw the " YEL "Rubber Chicken of Doom " RESET " at the mirror. It goes into it.\n");
      printf ("You blink.\n");
      printf ("You move through the portal.\n");
      
      success = 1;
    }
  }
}

void playScenes (int * hp, int * money, Inventory * inv, FILE *f)
{
  if (* hp > 0)
    {
      sceneOne (hp, money, f);
    }
  if (* hp > 0)
    {
      sceneTwo (hp, money, f);
    }
  if (* hp > 0)
    {
      sceneThree (hp, money, inv, f);
    }
  if (* hp > 0)
    {
      sceneFour (hp, money, inv, f);
    }
  if (* hp <= 0)
    {
      printf ("\nYou have collapsed in the mirror realm.\n");
      
      // ***
      
      fprintf (f, "\nYou have collapsed in the mirror realm.\n");
      
      // ***
    }
}

// main

int umbrellaRoute(int *hp, int *money, Inventory *inv);
{
  
  srand(time(NULL));
  
  FILE* f = fopen("AdventLog.txt", "a"); // open file

  if (f == NULL)
  {
    printf("Error opening log file.\n");
    return 1;
  } 
  
  Inventory inv;
  inv.UM = 0;
  inv.RC = 0;
  inv.EB = 0;
  inv.GC = 0;
  inv.count = 0;

  printf ("\nYou find yourself in a room full of mirrors, with no clue of how far they go.\n");
  printf ("Suddenly, a milk jug appears, somewhere inside the room.\n");
  printf ("You can see the image bouncing off each mirror, but you decide to venture forward.\n");
  printf ("Keeping one hand on the wall, you move deeper into the mirror room.\n");
  printf ("You hit a corner and before you can continue forward, you get pulled into a mirror.\n");
  
  printf ("\nYou have entered the " YEL "MIRROR REALM.\n" RESET);

  // ***

  fprintf (f, "\nYou find yourself in a room full of mirrors, with no clue of how far they go.\n");
  fprintf (f, "Suddenly, a milk jug appears, somewhere inside the room.\n");
  fprintf (f, "You can see the image bouncing off each mirror, but you decide to venture forward.\n");
  fprintf (f, "Keeping one hand on the wall, you move deeper into the mirror room.\n");
  fprintf (f, "You hit a corner and before you can continue forward, you get pulled into a mirror.\n");
  
  fprintf (f, "\nYou have entered the MIRROR REALM.\n");
  
  // *** 
  
  playScenes (&hp, &money, &inv, f);
  
  if (hp > 0)
  {
    printf ("\nYou have successfully escaped the MIRROR REALM.\n");
  
  // ***
    
    fprintf (f,"\nYou have successfully escaped the MIRROR REALM.\n");
    
  // ***
  }
  
  fclose(f); // close file
}

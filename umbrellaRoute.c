# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "creamCrop.h"

# define SIZE 6

// scene one

void sceneOne (int * health, int * money)
{
  int i;
  int success = 0;
  
  int correctPath[SIZE] = {1,3,2,2,3,1};
  int playerPath[SIZE];
  
  
  printf ("Stumbling forward, you find MORE mirrors!\n");
  printf ("You let out a sigh of exasperation.\n");
  printf ("The milk jug appears again and you steel your resolve.\n\n");
  printf ("For the milk!, you think as you take a deep breath and push forward.\n");

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
    
    for (i = 0; i < SIZE; i++)
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

// scene two

void sceneTwo (int * health, int * money)
{
  int choice;
  int escape = 0;
  
  printf ("You've landed in another room of mirrors.\n");
  printf ("You just sigh. Picking yourself back up.\n");
  
  printf ("\nAnd then you hear it.\n");
  
  printf ("\nThe rumble sound coming from behind you.\n");
  printf ("You turn around to find a wave of milk heading straight for you.\n");
  printf ("You quickly begin to run, with a single thought running through your head.\n");
  
  printf ("\nIs the milk truely worth it?\n");
  
  while (escape == 0)
  {
    printf ("\n\nChoose what to do: \n");
    printf ("1. Run straight forward.\n");
    printf ("2. Proceed with caution.\n");
    printf ("\t(please note, there is a giant wave behind you.)\n");
    printf ("3. Smash a mirror to find a shortcut.\n");
    
    printf ("You choose: ");
    scanf("%d", &choice);
    
    if (choice == 1)
    {
      printf ("You sprint forward...\n");
      
      if (rand() % 2 == 0)
      {
        printf ("You crash into a mirror wall!\n");
        printf ("You get cut and lose 5 health.\n");
        
        * health -= 5;
      }
      else
      {
        printf ("You narrowly avoid a mirror collision.\n");
        printf ("\nYou push forward and spot a mirror doorway.\n");
        printf ("You run towards it, entirely aware of the wave getting closer and closer.\n");
        printf ("You finally reach the door, open it, and slam it shut behind you.\n");
        
        escape = 1;
      }
    }
    else if (choice == 2)
    {
      printf ("You are too cautious and the milk mave crashes into you and pulls you under.\n");
      printf ("You lose 25 health.\n");
      printf ("\nTry again! :)\n");
      
      * health -= 25;
    }
    else
    {
      printf ("You purposefully slam yourself against one of the wall mirrors.\n\n");
      
      printf ("You take some minor damage (lose 5 health), but you successfully find a hidden passage and escape!\n");
      
      escape = 1;
    }
  }
}

// scene three

void sceneThree (int * health, int * money)
{
  int choice;
  
  printf ("You open your eyes and find a cow in front of you.\n");
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
  printf ("Cow, milk. Cow must have milk.\n");
  printf ("So you make a decision.\n");
  
  printf ("You choose: \n");
  printf ("1. Follow the cow\n");
  printf ("2. Don't follow the cow.\n");
  
  printf ("\nYou enter: ");
  scanf ("%d", &choice);
  
  if (choice == 1)
  {
    printf ("You proceed to follow the cow.\n");
    printf ("It takes you through several rooms before finally finding an open room,");
    printf ("made with only a limited numbers of mirrors.\n");
    
    printf ("The cow moos at you again to grab your attention.\n");
    printf ("He gives you an Umbrella and 15 money.\n");
    printf ("(don't ask how. explaination: magic)\n\n");
    
    printf ("You thank the cow and turn around to find a NEW doorway!\n");
    printf ("You bid the cow fairwell before finally bracing yourself for what's too come.\n");
  }
  else
  {
    printf ("You choose to ignore the cow.\n");
    printf ("Nothing major happens, and you continue forward.\n");
    printf ("You find a doorway and continue forward.\n");
    printf ("You feel slightly disapointed.\n");
  }

}

// scene four

void sceneFour (int * health, int * money)
{



// need scenario to use Rubber Chicken of Doom

}

// randomize

void playRandomScene(int *health, int *money)
{
    int r = rand() % 4;

    if (r == 0) sceneOne(health, money);
    else if (r == 1) sceneTwo(health, money);
    else if (r == 2) sceneThree(health, money);
    else sceneFour(health, money);
}

int main ()
{

  printf ("You find yourself in a room full of mirrors, with no clue of how far they go.\n");
  printf ("Suddenly, a milk jog appears, somewhere inside the room.\n");
  printf ("You can see the image bouncy off each mirror, but you decide to venture forward.\n");
  printf ("Keeping one hand on the wall, you move deeper into the mirror room.\n");
  printf ("You hit a corner and before you can continue forward, you get pulled mirror.");
  
  printf ("\nYou have entered the MIRROR REALM.\n");
  
  // add randomized scenes

}

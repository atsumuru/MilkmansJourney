//********************************
//Dean Bingham
//CS125
//Final project, tell a story, export data to main
//Go on a Dungeon Adventure!!!
//3/23/2026
//**********************************




/*
#ifndef HEADER_FILENAME 
#define HEADER_FILENAME 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bottleRoute.h"

/*
Notes - Colour coding
	Narration: default (\e[0m)
	Dialogue: yellow (\e[1;33m)
	Decisions: blue (\e[1;34m)
	Warnings: red (\e[1;31m)
  Grey: \033[90m
 -provided by Fred
 */

//brainstorming:
// 3 encounters. few choices each. Keep it short and sweet
//do not nest functions!!

//Player is given a set of options, some of them are randomized, resulting in different outcomes. During random number generation, the range is between 1 and 10, but one outcome can have weight across mulktiple integers, meaning that different results can be more or less common than others.
//if the player inputs an incompatable character, they punch themselves and take damage.




//Random Function: Generate and return a random int between 1 and 10

int randGen(int param)
  {
  //printf("Debug.randNum: ");
  srand(time(NULL));
  int randNum;
  
  randNum = rand()%param +1;
  
  

  //int num = 0;
  //num = rand()%param+1;
  //printf("%d\n",randNum);

  
  return randNum;
  
  }
  
  
int confusion()  //triggers upon invalid player input
  {
  
  //Damage - 5
  printf("wtf you hust hit yourself in the face\n");
  return 0;
  }
  
  
  

//Opening
        //Player finds themselves standing in front of a tall dungeon door. Entering the door they find an opening  

//Encounter 1
        //Puzzle encounter, in the entrance opening, a large gap between the player and the next room prevents them from continuing. Get over the gap.
        //Examining your surroundings, you find torches lining the wall of the entrance, a broken bridge along the chasm, and a fountain that pours directly to it, along your side. Stalacttites line the cieling of this faintly dim room.
  //option A1: Jump Across?
        //Outcome AA1: Ur too fat, you fall. take damage and climb back up, take lots of damage. try another option.
        //Outcome AA2: Your atheltic prowess overcomes adversity as you effortlessly leap across the chasm. Go to encounter 2.
        //Outcome AA3: You chicken out last second and decide to take another option. Try another option.
        //outcome AA4: Calmly, you walk across the chasm. For no particualr reason, you do not fall, completely ignoring the fact that theres a 50m foot chasm beneath you.
    
  //option B1: Throw something at the stalactites?
        //Outcome BB1: You miss, the item you threw glides off course and lands into the chasm, never to be seen again. Lose random item. try another option
        //Outcome BB2: You HIT! you idiot! the stalactite comes free from the cieling and lands on you! take lots of damage. try another option
        //Outcome BB3: You HIT! and the stalactite explodes, a grilled cheese comes out of its core, you pick it up and eat it, gain health. try another option.
        //Outcome BB4: You HIT! the stalactite is now pissed and is going to mug you, start a fight. After, try another option.
        //Outcome BB5: You HIT! against all logic and reasoning the stalactite comes free from the cieling, doing a triple backflip and landing perfectly along the chasm, replacing the bridge, you may cross.
  //option C1: Scale the chasm with the rope?
        //Outcome CC1: As you cross into the chasm. the rope snaps! you fall down and take some damage and climb back out, try again.
        //Outcome CC2: You reach the bottom of the chasm safely, at the bottomn you find some coins buried in the stream. Gain some money. What else did you expect was going to happen? Climb back up and try again.
        //Outcome CC3: using a known physics exploit, you clip into the pole while holding the rope, this causes you to fling into the cieling from where you climb across the chasm from the opposite face of the cieling. Go to                 encounter 2.
        
  //SECRET option D1: Jam the fountain with your umbrella?
        //Outcome DD1: The fountain ceases to spray water, with it out of the way, you notice a gleaming light hidden within it. Its a metal bottle! Your years of dungeon experience compels you to nab it and hoard it with your life.          The jamming of the fountain causes it to explode, flooding the room. You take advantage of this by swimming to the next room. Go to encounter 2.
        
  //Call encounter 2
  
//Encounter 2
        //Enemy goblin encounter, fight or otherwise de-escalate with the threat
  //option A2: Mug the enemies back!
        //Outcome AA1: the goblins are done with your games, they collectively jump you, fight.
        //Outcome BB1: You stand as tall as you can go and approach the goblins, they shriek in disbelief, dropping their belongings and fleeing. Gain somne money and health, go to encounter 3.
        //Outcome CC1: Well, the goblins are mugging you and you are mugging the goblins, might as well just duke it out now, fight.
  //option B2: Play Uno with the enemies
        //Outcome AA1: After playing a draw 4, one of the goblins angrily grabs and flings the table backwards. try another option.
        //Outcome BB1: You win! being sore losers, the goblins decide to collectively jump you anyway. Fight.
        //Outcome CC1: You lose! the goblins planned an ultimate combo that resulted in you drawing 50 cards!!! Laughing and rolling on the floor, you notice the perfect opportunity to sneak past, go to encounter 3.
  //option C2: Vanish out of existence
        //Outcome AA1: You hold two fingers up to your chest and fade away, flabbergasted, the goblins shriek in shock as you vanish out of existence and away from their trap. You reappear in the next room, go to encounter 3.
        //Outcome BB1: You hold two fingers up to your chest, nothing happens. albeit a little confused, the goblins collectively jump you all at once, fight.
        //Outcome CC1: You hold two fingers up to your chest and fade out of existence. Unfortunately, so do the goblins, you both reappear in a different room, and theyre back to mugging you, try another option.
  //call encounter 3
      
//Encounter 3 
        //Trap encounter, a large series of traps stands in your way, either disarm or navigate across. A long corridor littered with swinging axes stands in your way. A large bonfire sits at the entrance and casts light into this            room, resulting in the corridor turning dark as it progresses to the end, leaving the last few axes in darkness.
  //option A3: Immolate Yourself
        //Outcome AA1: Jumping onto the bonfire, you panic as you lose all sense of motor control as your pants ignite, unknowingly, you bolt across the room, miraculously unharmed. Continue to encounter 4
        //Outcome AA2: How are you expecting a different result than is common sense? You ignite into a ball of fire and turn into a pile of crisp ashes :(
       
        
  //option B3: Disarm the traps.
        //Outcome BB1: You try to grab the swinging axe as it comes down, you catch it, causing it to become dislodged from its handle, you then swing it into its gearbox, jamming the system to a standstil. Continue to encounter 4
        //Outcome BB2: You poilitely remind the axes that they need your consent to kill you, they instantly slow to a stop. Continue to encounter 4
        //Outcome BB3: You try to jam a nearby rock into one of the slits in which the axes pop out from, it doesnt work, the system overloads and explodes as youre blanketed in shrapnel and splinters, take damage. continue to               encounter 4
  //option C3; Run across the traps. (Naruto style)
        //Outcome AA1: The axes have no trouble catching a middle aged fat man slowly running across the hall with their arms stretched out behind them. One of the axes slams directly into you and knocks you into the wall. Take              damage, try another option.
        //Outcome BB1: In the blink of an eye, you start at the beginning of the corridor and then post blink find yourself at the end of it, only issue is that you completely overshot, running into the door at lightspeed. Take lots of damage and go to encounter 4.
        //Outcome CC1: You trip on your face, faceplanting into the hard rock floor. Take damage, try another option.
        
  //call encounter 4
  
//Encounter 4
        // A basic shop, in a dungeon. Buy (or steal) stuff
  //option A4: Buy health
      //outcome AA1: Gain health
  //option B4: Buy Money:
      //Outcome BB1: Gain money
  //option C4: Mug the seller
      //Outcome CC1: Take 2,147,483,647 damage
  //call encounter 5
  
//Encounter 5 (Final Challenge)
        //Fight a bid baddie, you can choose a special method of starting the fight, which is mostly visual
        
  //Option A5: Cry for mommy
        //Outcome AA1: 
        //Outcome BB1: 
        //Outcome CC1: 
  //Option B5: Explode
        //Outcome AA1: 
        //Outcome BB1: 
        //Outcome CC1: 
  //option C5: Stand there, MENACINGLY
        //Outcome AA1: 
        //Outcome BB1: 
        //Outcome CC1: 
        
        
  //end







int bottleRoute()
{
  FILE *f = fopen ("AdventureLog.txt","a");
  int param = 1;
  //printf("Debugging/ ");
  int randNum =randGen(param);

  
// randGen(2);
//  randGen(2);


/*

  int x =0;
    
  for(x=0;x<10;x++)
    {
    int randNum =randGen(param);
    if(randNum == 1)
      {
      printf("Number triggered\n");
      }
  else
      {
      printf("error\n");
      }
      
    }
  
  */
  
  
  //Debugging done
  
  
  char playerSelect = 0;
  
  printf("\e[0mYou wake up on the floor in a forest clearing, overshadowed by the size of a large door right in front of you. Pulling yourself back onto your feet, and feel enticed about the door and what riches could lie behind it. Pressing your weight against the door, you eventually feel the old, rusted"                 "door part from its hinges after spending who knows how long there. Entering a large cave opening, you spot your first challenge.\n");
  fprintf(f,"you wake up on the floor in a forest clearing, overshadowed by the size of a large door right in front of you. Pulling yourself back onto your feet, and feel enticed about the door and what riches could lie behind it. Pressing your weight against the door, you eventually feel the old, rusted door"              "part from its hinges after spending who knows how long there. Entering a large cave opening, you spot your first challenge.\n");

  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //Start Encounter 1
  printf("\033[90m========================================\n");
  printf("\e[0mEntering the dungeon you notice the walls stretch outwards, into a large open room; appearing rudimentary in construction, the floor is bare stone and the cieling is rough and adorned with sharp spikes. These spikes precariously protrude downards, threatening to impale any would be passerbies."          " You hear the sound of flowing water as a fountain on your side of the room empties an endless stream of water into a large, noticable chasm; blocking your progress.\n");
  fprintf(ff"\e[0mEntering the dungeon you notice the walls stretch outwards, into a large open room; appearing rudimentary in construction, the floor is bare stone and the cieling is rough and adorned with sharp spikes. These spikes precariously protrude downards, threatening to impale any would be passerbies."         "You hear the sound of flowing water as a fountain on your side of the room empties an endless stream of water into a large, noticable chasm; blocking your progress.\n");
  printf("A chasm stands before you, what to do?\n");
  printf("\e[1;34m1. Jump Across the Chasm\n");
  printf("2. \e[1;34mThrow something at the cieling\n");
  printf("3. \e[1;34mRapel using the rope\n");
  
  //triggers if player has secret item
  /*
  if(hasSecretitem)
    {
    printf("4. Use your umbrella\n");
    }
  */
  
  printf("\e[0mWhat is your selection: ");
  scanf("%d",&playerSelect);
  printf("You selected %d", playerSelect);
  printf("\n");
  printf("\033[90m========================================\n");
                                          //Transcribe option to summary
  
  
  if(playerSelect ==1)
    {
    printf("\033[90m==============");
    printf("\n\e[0mChose option 1\n");
    //trigger outcome 1
    int randNum = randGen(3);
    printf("%d",randNum);
    //param 4
    if(randNum == 1)
      {
      printf("Triggered outcome 1\n");
      printf("\e[1;33mUr too fat, you fall. take \e[1;31mdamage\e[1;33m and climb back up the other side\n");
      fprintf(f,"Ur too fat, you fall. take \e[1;31mdamage\e[1;33m and climb back up the other side\n");
      }
    else if(randNum==2)
      {
      printf("Triggered outcome 2\n");
      printf("\e[1;33mYour atheltic prowess overcomes adversity as you effortlessly leap across the chasm!!\n");
      fprintf(f,"Your atheltic prowess overcomes adversity as you effortlessly leap across the chasm!!\n");
      }
    else if(randNum == 3)
      {
       printf("Triggered outcome 3\n");
       printf("\e[1;33mCalmly, you walk across the chasm. For no particualr reason, you do not fall, completely ignoring the fact that theres a 50m foot chasm beneath you.\n");
       fprintf(f,"Calmly, you walk across the chasm. For no particualr reason, you do not fall, completely ignoring the fact that theres a 50m foot chasm beneath you.\n");
      }
    printf("\033[90m==============\n");
    }
    
       
  else if (playerSelect ==2)
    {
    printf("\033[90m==============");
    printf("\n\e[0mChose option 2\n");
    //trigger outcome 2
    int randNum = randGen(5);
    printf("%d",randNum);
    //param 5
    if(randNum == 1)
      {
      printf("Triggered outcome 1\n");
      printf("\e[1;33mYou miss, the item you threw glides off course and lands into the chasm, never to be seen again. You just decide it's easier to climb across\n");
      fprintf(f,"You miss, the item you threw glides off course and lands into the chasm, never to be seen again. You just decide it's easier to climb across\n");
      }
    else if(randNum==2)
      {
      printf("Triggered outcome 2\n");
      printf("\e[1;33mYou HIT! you idiot! the stalactite comes free from the cieling and \e[1;31mlands on you!\e[1;33m Somehow, it rolls off and forms a bridge.\n");
      fprintf(f,"You HIT! you idiot! the stalactite comes free from the cieling and \e[1;31mlands on you!\e[1;33m Somehow, it rolls off and forms a bridge.\n");
      }
    else if(randNum == 3)
      {
       printf("Triggered outcome 3\n");
       printf("\e[1;33mYou HIT! and the stalactite explodes, a grilled cheese comes out of its core, you pick it up and eat it, gaining such energy that you can vault across the chasm; and heal 10 health!\n");
       fprintf(f,"You HIT! and the stalactite explodes, a grilled cheese comes out of its core, you pick it up and eat it, gaining such energy that you can vault across the chasm; and heal 10 health!\n");
      }
    else if(randNum == 4)
      {
       printf("Triggered outcome 4\n");
       printf("\e[1;33mYou HIT! the stalactite is now pissed and is going to \e[1;31mmug \e[1;33myou, starting a fight with you.\n");
       fprintf("\e[1;33mYou HIT! the stalactite is now pissed and is going to \e[1;31mmug \e[1;33myou, starting a fight with you.\n");
       //fight
       printf("You win! you pick up the stalactite and drop it over the chasm, using it as a bridge.\n");
       fprintf(f,"You win! you pick up the stalactite and drop it over the chasm, using it as a bridge.\n");
      }
    else if(randNum == 5)
      {
       printf("Triggered outcome 5\n");
       printf("\e[1;33mYou HIT! against all logic and reasoning the stalactite comes free from the cieling, doing a triple backflip and landing perfectly along the chasm, replacing the bridge, you may cross.\n");
       fprintf(f,"You HIT! against all logic and reasoning the stalactite comes free from the cieling, doing a triple backflip and landing perfectly along the chasm, replacing the bridge, you may cross.\n");
      }
       printf("\033[90m=============\n");
    }
   
      
    
    
  else if (playerSelect ==3)
    {
    //trigger outcome 3
    //param 3
    printf("\033[90m==============");
    printf("\n\e[0mChose option 3\n");
    int randNum = randGen(3);
    printf("%d",randNum);
  
    if(randNum == 1)
      {
      printf("Triggered outcome 1\n");
      printf("\e[1;33m As you cross into the chasm. the rope snaps! you fall down and take some damage and climb back out the other side\n");
      fprintf(f,"As you cross into the chasm. the rope snaps! you fall down and take some damage mand climb back out the other side\n");
      }
    else if(randNum==2)
      {
      printf("Triggered outcome 2\n");
      printf("\e[1;33mYou reach the bottom of the chasm safely, at the bottomn you find some coins buried in the stream. You climb back out the other side\n");
      fprintf(f,"You reach the bottom of the chasm safely, at the bottomn you find some coins buried in the stream. You climb back out the other side\n");
      //add 8 money
      }
    else if(randNum == 3)
      {
       printf("Triggered outcome 3\n");
       printf("\e[1;33musing a known physics exploit, you clip into the pole while holding the rope, this causes you to fling into the cieling from where you climb across the chasm from the opposite face of the cieling.\n");
       fprintf(f,"\e[1;33musing a known physics exploit, you clip into the pole while holding the rope, this causes you to fling into the cieling from where you climb across the chasm from the opposite face of the cieling.\n");
        printf("\033[90m==============\n");
      }
    }
    
    
      /*
  if(hasSecretitem)
    {
     if(playerSelect ==4)
       {
       printf("SECRET outcome\n");
       (add bottle to inventory)
       }
    }
  */
       
  else
    {

    confusion(); //punich misinput
    printf("\033[90m==============\n");
    }
  
  
  
  
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
   
  //Start Encounter 2
  printf("\033[90m========================================\n\e[0m");
 // printf("Goblins Mug you, what do to?\n");
  printf("\e[0mbrushing yourself off from the dusty room you just left, you find yourself walk into a series of basic hallways, laid with cheap stone bricks and unimpressive wood floors. As you make your way through the path, you notice movement off in the distance. Only to get caught off guard by a squad of 4 goblins, the size of a small child, approach you, brandishing crude bronze daggers at you. One of the goblins points their dagger at your chest, and demands you relinquish your liver!\n");
  fprintf(f,"\e[0mbrushing yourself off from the dusty room you just left, you find yourself walk into a series of basic hallways, laid with cheap stone bricks and unimpressive wood floors. As you make your way through the path, you notice movement off in the distance. Only to get caught off guard by a squad of 4 goblins, the size of a small child, approach you, brandishing crude bronze daggers at you. One of the goblins points their dagger at your chest, and demands you relinquish your liver!\n");
  printf(" Goblins mug you, demanding your liver! What are you to do??\n");
  printf("\e[1;34m1. Mug them back!\n");
  printf("2. Play Uno\n");
  printf("3. Vanish from existance\n");
  printf("4. Give in and give up\n");
  
  printf("What is your selection: ");
  scanf("%d",&playerSelect);
  printf("You selected %d", playerSelect);
  printf("\n");
  printf("\e[0m\033[90m========================================\n\e[0m");
                                          //Transcribe option to summary
  
  
  if(playerSelect ==1)
    {
    printf("\033[90m==============\e[0m");
    printf("\nChose option 1\n");
    //trigger outcome 1
    int randNum = randGen(4);
    printf("%d",randNum);
    //param 4
    if(randNum == 1)
      {
      printf("Triggered outcome 1\n");
      printf("\e[1;33mthe goblins are done with your games, they collectively jump you.\n");
      fprintf(f,"\e[1;33mthe goblins are done with your games, they collectively jump you.\n");
      //start fight
      }
    else if(randNum==2)
      {
      printf("Triggered outcome 2\n");
      printf("\e[1;33mYou stand as tall as you can go and approach the goblins, they shriek in disbelief of your aura, dropping their belongings and fleeing. You pick up their dropped belongings\n");
      fprintf(f,"\e[1;33mYou stand as tall as you can go and approach the goblins, they shriek in disbelief of your aura, dropping their belongings and fleeing. You pick up their dropped belongings\n");
      //health += 5, money += 15
      }
    else if(randNum == 3)
      {
       printf("Triggered outcome 3\n");
       printf("\e[1;33mWell, the goblins are mugging you and you are mugging the goblins, might as well just duke it out now, fight!\n");
       fprintf(f,"\e[1;33mWell, the goblins are mugging you and you are mugging the goblins, might as well just duke it out now, fight!\n");
       //start fight
      }
      printf("\033[90m==============\n\e[0m");
      

    }
    
       
  else if (playerSelect ==2)
    {
    printf("\033[90m==============\e[0m");
    printf("\nChose option 2\n");
    //trigger outcome 2
    int randNum = randGen(5);
    printf("%d",randNum);
    //param 5
    if(randNum == 1)
      {
      printf("Triggered outcome 1\n");
      printf("\e[1;33mAfter playing a draw 4, one of the goblins angrily grabs and flings the table forwards! The goblins respond in kind by jumping you\n");
      fprintf(f,"\e[1;33mAfter playing a draw 4, one of the goblins angrily grabs and flings the table forwards! The goblins respond in kind by jumping you\n");
      }
    else if(randNum==2)
      {
      printf("Triggered outcome 2\n");
      printf("\e[1;33mYou win! being sore losers, the goblins decide to collectively jump you anyway. Get ready for a fight\n");
      fprintf(f,"\e[1;33mYou win! being sore losers, the goblins decide to collectively jump you anyway. Get ready for a fight\n");
      }
      
    else if(randNum == 3)
      {
       printf("Triggered outcome 3\n");
       printf("\e[1;33mYou lose! the goblins planned an ultimate combo that resulted in you drawing 46 cards!!! Laughing and rolling on the floor, you notice the perfect opportunity to sneak past.\n");
       fprintf(f,"\e[1;33mYou lose! the goblins planned an ultimate combo that resulted in you drawing 46 cards!!! Laughing and rolling on the floor, you notice the perfect opportunity to sneak past.\n");
      }
      
      printf("\033[90m=============\n\e[0m");
     
    }
   
      
    
    
  else if (playerSelect ==3)
    {
    //trigger outcome 3
    //param 3
    printf("\033[90m==============\e[0m");
    printf("\nChose option 3\n");
    int randNum = randGen(3);
    printf("%d",randNum);
  
    if(randNum == 1)
      {
      printf("Triggered outcome 1\n");
      printf("\e[1;33mYou hold two fingers up to your chest and fade away, flabbergasted, the goblins shriek in shock as you vanish out of existence and away from their trap. You reappear in the next room\n");
      fprintf(f,"\e[1;33mYou hold two fingers up to your chest and fade away, flabbergasted, the goblins shriek in shock as you vanish out of existence and away from their trap. You reappear in the next room\n");
      }
    else if(randNum==2)
      {
      printf("Triggered outcome 2\n");
      printf("\e[1;33mYou hold two fingers up to your chest, nothing happens. albeit a little confused, the goblins collectively jump you all at once\n");
      fprintf(f,"\e[1;33mYou hold two fingers up to your chest, nothing happens. albeit a little confused, the goblins collectively jump you all at once\n");
      //start fight
      }
    else if(randNum == 3)
      {
       printf("Triggered outcome 3\n");
       printf("\e[1;33mYou hold two fingers up to your chest and fade out of existence. Unfortunately, so do the goblins, you both reappear in a different room, and theyre back to mugging you.\n");
       fprintf(f,"\e[1;33mYou hold two fingers up to your chest and fade out of existence. Unfortunately, so do the goblins, you both reappear in a different room, and theyre back to mugging you.\n");
       //start fight
      }  
   
    }

  else if (playerSelect ==4)
    {
    printf("Triggered outcome 1\n");
    printf("\e[1;33mYou relent, giving the goblins your liver, maybe they can make better use of it than you. One of the goblins happily shouts: WE CAN PAY FOR MOMS CANCER TREAMENT NOW! before leaving you alone. You take \e[1;31m50 damage\e[0m!\n");
    fprintf(f,"\e[1;33mYou relent, giving the goblins your liver, maybe they can make better use of it than you. One of the goblins happily shouts: WE CAN PAY FOR MOMS CANCER TREAMENT NOW! before leaving you alone. You take \e[1;31m50 damage\e[0m!\n");
    //take 50 damage  
   
    }  
  



  else
      {
    
      confusion(); //punich misinput
      }
      printf("\033[90m==============\n\e[0m");
    
    


  
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
  //start encounter 3
  printf("\033[90m========================================\n");
  printf("\e[0mStill recovering from the bizarre encounter, you reach the next door. While it conceals the next room, you can make out the recognizable sound of videogame traps from beyond the room. Only to have your assumptions confirmed as the next room leads into a narrow corridor lines with slits in which autonomous axes swing across the room. It may be dangerous, but at least you can take all the time you need to progress from here.\n");
  fprintf(f,"\e[0mStill recovering from the bizarre encounter, you reach the next door. While it conceals the next room, you can make out the recognizable sound of videogame traps from beyond the room. Only to have your assumptions confirmed as the next room leads into a narrow corridor lines with slits in which autonomous axes swing across the room. It may be dangerous, but at least you can take all the time you need to progress from here.\n");
  printf("A trap stands in your way, what do to?\n");
  printf("\e[1;34m1. Immolate yourself!\n");
  printf("2. Disarm the traps\n");
  printf("3. Run across\n");

  
  printf("What is your selection: ");
  scanf("%d",&playerSelect);
  printf("You selected %d", playerSelect);
  printf("\n");
  printf("\e[0m\033[90m========================================\n\e[0m");
                                          //Transcribe option to summary
  
  
  if(playerSelect ==1)
    {
    printf("\033[90m==============\e[0m");
    printf("\nChose option 1\n");
    //trigger outcome 1
    int randNum = randGen(2);
    printf("%d",randNum);
    if(randNum == 1)
      {
      printf("Triggered outcome 1\n");
      printf("\e[1;33mJumping onto the bonfire, you panic as you lose all sense of motor control as your pants ignite, unknowingly, you bolt across the room, miraculously unharmed.\n");
      fprintf(f,"\e[1;33mJumping onto the bonfire, you panic as you lose all sense of motor control as your pants ignite, unknowingly, you bolt across the room, miraculously unharmed.\n");
      }
    else if(randNum==2)
      {
      printf("Triggered outcome 2\n");
      printf("\e[1;33mHow are you expecting a different result than is common sense? \e[1;31mYou ignite into a ball of fire and turn into a pile of crisp ashes :(\n\e[0m");
      fprintf(f,"\e[1;33mHow are you expecting a different result than is common sense? \e[1;31mYou ignite into a ball of fire and turn into a pile of crisp ashes :(\n\e[0m");

      }
      

    }
    
       
  else if (playerSelect ==2)
    {
    printf("\033[90m==============\n\e[0m");
    printf("\nChose option 2\n");
    //trigger outcome 2
    int randNum = randGen(3);
    printf("%d",randNum);
    if(randNum == 1)
      {
      printf("Triggered outcome 1\n");
      printf("\e[1;33mYou try to grab the swinging axe as it comes down, you catch it, causing it to become dislodged from its handle, you then swing it into its gearbox, jamming the system to a standstill.\n");
      fprintf(f,"\e[1;33mYou try to grab the swinging axe as it comes down, you catch it, causing it to become dislodged from its handle, you then swing it into its gearbox, jamming the system to a standstill.\n");
      }
    else if(randNum==2)
      {
      printf("Triggered outcome 2\n");
      printf("\e[1;33mYou poilitely remind the axes that they need your consent to kill you, they instantly slow to a stop.\n");
      fprintf(f,"\e[1;33mYou poilitely remind the axes that they need your consent to kill you, they instantly slow to a stop.\n");
      }
    else if(randNum == 3)
      {
       printf("Triggered outcome 3\n");
       printf("\e[1;33mYou try to jam a nearby rock into one of the slits in which the axes pop out from, it doesnt work, the system overloads and explodes as youre blanketed in shrapnel and splinters, taking \e[1;31mdamage.\n\e[0m");
       fprintf(f,"\e[1;33mYou try to jam a nearby rock into one of the slits in which the axes pop out from, it doesnt work, the system overloads and explodes as youre blanketed in shrapnel and splinters, taking \e[1;31mdamage.\n\e[0m");
      }
      
      printf("\033[90m=============\n\e[0m");
     
    }
    
      else if (playerSelect ==3)
    {
    printf("\033[90m==============\n\e[0m");
    printf("\nChose option 3\n");
    int randNum = randGen(3);
    printf("%d",randNum);
  
    if(randNum == 1)
      {
      printf("Triggered outcome 1\n");
      printf("\e[1;33mThe axes have no trouble catching a middle aged fat man slowly running across the hall with their arms stretched out behind them. One of the axes slams directly into you and\e[1;31m knocks you into the wall.\n\e[0m");
      fprintf(f,"\e[1;33mThe axes have no trouble catching a middle aged fat man slowly running across the hall with their arms stretched out behind them. One of the axes slams directly into you and\e[1;31m knocks you into the wall.\n\e[0m");
      //(Health -= 10)
      }
    else if(randNum==2)
      {
      printf("Triggered outcome 2\n");
      printf("\e[1;33mYou wind up your sprint in the Naruto position, and in the blink of an eye, you start at the beginning of the corridor and then post blink find yourself at the end of it, only issue is that you completely overshot, running into the door at lightspeed. Taking \e[1;31mlots of damage from the blunt force\n\e[0m");
      fprintf(f,"\e[1;33mYou wind up your sprint in the Naruto position, and in the blink of an eye, you start at the beginning of the corridor and then post blink find yourself at the end of it, only issue is that you completely overshot, running into the door at lightspeed. Taking \e[1;31mlots of damage from the blunt force\n\e[0m");
      //health -= 35)
      }
    else if(randNum == 3)
      {
       printf("Triggered outcome 3\n");
       printf("\e[1;33mYou trip on your face, \e[1;31mfaceplanting into the hard rock floor\n\e[0m");
       fprintf(f,"\e[1;33mYou trip on your face, \e[1;31mfaceplanting into the hard rock floor\n\e[0m");
      }
      printf("==============\n\e[0m");
    }
    
    
    else
    {

    confusion(); //punich misinput
    printf("\033[90m==============\n\e[0m");
    }
    
      
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      //start encounter 4
  printf("\033[90m========================================\n");
  printf("\e[0mxhausted and nearly out of constitution, you reach a small room. It stands as the only welcoming area within the dungeon, and another man has set up a small supplies shop here. 'isnt running a business at the back iof a dungeon a terrible choice for business?' you ask the man. He turns you to to give the response: 'youre going to need all the supplies you can get if you wish to survive the horrible, indescribable monster that sleeps within the next chamber!' You feel a flooding sense of dread as you soon realize there might not be any chance of turning back now, you either fight the monster ahead or die trying\n");
  fprintf(f,"\e[0mxhausted and nearly out of constitution, you reach a small room. It stands as the only welcoming area within the dungeon, and another man has set up a small supplies shop here. 'isnt running a business at the back iof a dungeon a terrible choice for business?' you ask the man. He turns you to to give the response: 'youre going to need all the supplies you can get if you wish to survive the horrible, indescribable monster that sleeps within the next chamber!' You feel a flooding sense of dread as you soon realize there might not be any chance of turning back now, you either fight the monster ahead or die trying\n");
  printf("You find a convenient little shop, what to do?\n");
  printf("\e[1;34m1. Buy health\n");
  printf("2. Buy money\n");
  printf("3. Rob the seller\n");

  
  printf("What is your selection: ");
  scanf("%d",&playerSelect);
  printf("You selected %d", playerSelect);
  printf("\n");
  printf("\e[0m\033[90m========================================\n\e[0m");
                                          //Transcribe option to summary
  
  
  if(playerSelect ==1)
    {
    printf("\033[90m==============\e[0m");
    printf("\nChose option 1\n");
    printf("\n\e[1;33mYou purchased 10 health\n");
    fprintf(f,"\n\e[1;33mYou purchased 10 health\n");
    //(money -$5)
    //trigger outcome 1
    int randNum = randGen(1);
    printf("%d",randNum);
    if(randNum == 1)
      {
      //printf("Triggered outcome 1\n");
      }
      printf("==============\n");
      

    }
    
       
  else if (playerSelect ==2)
    {
    printf("\033[90m==============\e[0m");
    printf("\nChose option 2\n");
    printf("\n\e[1;33mYou purchase $20\n");
    fprintf(f,"\n\e[1;33mYou purchase $20\n");
    //(Money -$10)
    //(Money +$20)
    //trigger outcome 2
    int randNum = randGen(1);
    printf("%d",randNum);
    if(randNum == 1)
      {
      //printf("Triggered outcome 1\n");
      }     
      printf("\033[90m=============\n\e[0m");
     
    }
    
      else if (playerSelect ==3)
    {
    printf("\033[90m==============\e[0m");
    printf("\nChose option 3\n");
    printf("\e[1;33mYou decide to try and show the shopkeeper your (100%) discount coupon, he isn't having it. He gives you the gaze of death.\nTake Take \e[1;31m2,147,483,647 damage!\n\e[0m");
    fprintf(f,"\e[1;33mYou decide to try and show the shopkeeper your (100%) discount coupon, he isn't having it. He gives you the gaze of death.\nTake Take \e[1;31m2,147,483,647 damage!\n\e[0m");
    //(health -= 100)
    int randNum = randGen(1);
    printf("%d",randNum);
  
    if(randNum == 1)
      {
      //printf("Triggered outcome 1\n");
      }
      printf("\033[90m==============\n\e[0m");
    }
    
    
    else
    {

    confusion(); //punich misinput
    printf("\033[90m==============\n\e[0m");
    }
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    //start encounter 5
    
    printf("\033[90m========================================\n\e[0m");
    printf("Slowly and quietly creeping into the next room, you find a monster of indescribable nature lurking within the chamber center. It yields powerful horns on its face, with strong legs sporting dense hooves at the feet. Accompanies by massive proportions, towering at over twice your width. All to come with the cherry on top of its bulbous eyes and screaming bell of impending doom.\n\e[1;31mIt's a cow...\n\e[0m");
    fprintf(f,"Slowly and quietly creeping into the next room, you find a monster of indescribable nature lurking within the chamber center. It yields powerful horns on its face, with strong legs sporting dense hooves at the feet. Accompanies by massive proportions, towering at over twice your width. All to come with the cherry on top of its bulbous eyes and screaming bell of impending doom.\n\e[1;31mIt's a cow...\n\e[0m");
    printf("This is it, the big baddie, they must be guarding whatever treasure is sure to be found in this dungeon. How should you open up this fight?\n");
    printf("\e[1;34m1. Cry for Mommy\n");
    printf("2. Explode\n");
    printf("3. Stand there (Menacingly)\n");
  
    
    printf("What is your selection: ");
    scanf("%d",&playerSelect);
    printf("You selected %d", playerSelect);
    printf("\n");
    printf("\e[0m\033[90m========================================\n\e[0m");
    
    if(playerSelect==1)
      {
      printf("\e[1;33mYou fall back, sitting on your butt while sobbing profuseley, the big baddie gets so annoyed that they break the silence just to attack you.\n");
      fprintf(f,"\e[1;33mYou fall back, sitting on your butt while sobbing profuseley, the big baddie gets so annoyed that they break the silence just to attack you.\n");
      //start fight
      }
    
    else if(playerSelect==2)
      {
      printf("\e[1;33mYou explode, causing a chain reaction that results in the big baddie exploding too. Congratulations! You defeated the big baddie! \e[1;31mBut you also defeated yourself :/\n\e[0m");
      fprintf(f,"\e[1;33mYou explode, causing a chain reaction that results in the big baddie exploding too. Congratulations! You defeated the big baddie! \e[1;31mBut you also defeated yourself :/\n\e[0m");
      //take 100 damage
      }
    
    else if(playerSelect==3)
      {
      printf("\e[1;33mYou farm aura by standing in place, idle. The sheer awesomeness causes a powerful radiance to shoot out of your stance, melting the big baddie into a pile of goop.\n");
      fprintf(f,"\e[1;33mYou farm aura by standing in place, idle. The sheer awesomeness causes a powerful radiance to shoot out of your stance, melting the big baddie into a pile of goop.\n");
      }
      
    else
      {
      
      confusion(); //punich misinput
      printf("\033[90m==============\n\e[0m");
      }
    
                                            //Transcribe option to summary
                                            
                                            
    //The ending
    printf("\n\nCongratulate yourself and pat yourself on the back because you have done it, you have overcome all of the trials within the dungeon. Now it is time for your reward. You skip up to the treasure room door, and with a joyful gesture, you place your hand on the ring shaped handle and push it open, causing the massive 10 foot ornate door to creak open. The room inside is dim, enticing you to walk in. Only to find the door slam and lock behind you as the walls warp into some new, unforseeable form. You can only brace yourself for what is to come next...");
    fprintf(f,"\n\nCongratulate yourself and pat yourself on the back because you have done it, you have overcome all of the trials within the dungeon. Now it is time for your reward. You skip up to the treasure room door, and with a joyful gesture, you place your hand on the ring shaped handle and push it open, causing the massive 10 foot ornate door to creak open. The room inside is dim, enticing you to walk in. Only to find the door slam and lock behind you as the walls warp into some new, unforseeable form. You can only brace yourself for what is to come next...");
    fclosef(f);
}

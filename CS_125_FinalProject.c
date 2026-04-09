//********************************
//Dean Bingham
//CS125
//Final project, tell a story, export data to main
//Go on a Dungeon Adventure!!!
//3/23/2026
//**********************************


#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//brainstorming:
// 3 encounters. few choices each. Keep it short and sweet
//do not nest functions!!

//Player is given a set of options, some of them are randomized, resulting in different outcomes. During random number generation, the range is between 1 and 10, but one outcome can have weight across mulktiple integers, meaning that different results can be more or less common than others.
//if the player inputs an incompatable character, they punch themselves and take damage.




//Random Function: Generate and return a random int between 1 and 10

int randGen(int param)
  {
  printf("this is running\n");
  srand(time(NULL));
  int randNum;
  
  randNum = rand()%param+1;
  
  

  int num = 0;
  num = rand()%param+1;
  printf("%d\n",num);

  
  return randNum;
  
  }
  
  
int confusion()  //triggers upon invalid player input
  {
  
  //Damage - 5
  
  return 0;
  }
  
void E1O1()
  {
  
  

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







int main()
{
/*
	printf("this is running\n");
  srand(time(NULL));
  int num = 0;
  num = rand()%10+1;
  printf("%d",num);
  return 0;
  */
  
  randGen(100);
  
  //Debugging done
  
  char playerSelect = 0;
  
  
  //Start Encounter 1
  
  printf("A chasm stands before you, what to do");
  scanf("%d",&playerSelect);
  
  if(playerSelect ==1)
    {
    //trigger outcome 1
    //param 3
    }
  else if (playerSelect ==2)
    {
    //trigger outcome 2
    }  
  else if (playerSelect ==3)
    {
    //trigger outcome 3
    }
  else
    {
    confusion() //punich misinput
    }
  
  
  
  
  
}

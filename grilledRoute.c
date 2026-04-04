#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include "creamCrop.h" 



void sceneOne(int *h, int *m) 
{
	printf("You walk up some stalls that look like they were made by a groups of 10 year olds when you hear a commotion up ahead. You turn "
				"the corner to see two stallowners arguing in the middle of the pathway. Their endless back and forth is taking up the whole "
				"path.\n\n"); 
	
	int c = 0; 
	int skill_check;
	
	char junk;
	while (c = 0)
	{ 
		skill_check = rand()%12+1;
		printf("What do you do? \n1) Go around \n2) De-escalate \n3) Tell them to move \n");
		printf("> ");
		scanf("%d", &c);
		while(c != 1 && c != 2 && c != 3) 
		{
			junk = getchar();
      printf("Your thoughts seem jumbled. Try again.\n> ");
      scanf("%d", &c); 
		}
		
		if(c == 1)
		{
			printf("You decide to go around. \n\n")
			if(skill_check < 3)
			{
				printf("You try squeezing past them, but as you do, they get into a heated argument and start fighting. You catch a random stray "
							"to the cheek, easily leaving a bruise on your supple face. You quickly scuttle out of the way, cupping your cheek.\n");
				*h = -5; 
			}
			else 
			{
				printf("You slowly back up and go down another path.\n");
			} 
		}
		else if(c == 2) 
		{
			printf("You decide to de-escalate the situation. \n"); 
			if(skill_check < 6)
			{
				printf("You try to talk the storeowners down, but they're too deep in their spat to recognize your presence.\nWell, that was "
							"useless.\n");
				c = 0; 
			} 
			else 
			{
				printf("You interupt their argument and start giving a speech about kindness and the importance of helping one another."
							"Your speech brings a tear to their eyes as they look at each other and hug it out. They then walk away, "
							"arm over the other's shoulder.\nYou always did had a way with words.\n");
			} 
		}
		else if(c == 3)
		{
			printf("You decide to tell them to move.\n");
			if(skill_check < 3)
			{
				printf("You tell them to move their @sses out of the way. They immediately stop arguing and glare at you. They turn back to each "
							"and shake hands. You raise your eyebrow in confusion before they both punch you in face, knocking you onto the ground."
							"\nThe stallowners then turn and walk away while you wipe the blood from your nose.\nWell, on the bright side, the "
							"path's free.\n");
				*h = -10;
			}
			else
			{
				printf("You yell at them to move outta the way and they jump in surprise. Red flushes their faces as they scurry out of the way in "
				"embarrassment.\nPeople these days just don't have any common sense.\n");
			}
		} 
	} 
} 


void sceneTwo(int *h, int *m) 
{
	printf("As you walk down the stalls, you hear a loud crash as metal trashcan falls over in the way. A raccoon crawls out, "
				"chewing on a old bone.


void grilledRoute(int *health, int *money) //Include the inventory lists when they get made 
{ 
	srand(time(NULL)); 

	int scene_select; 
	int scene_list[5] = {1,1,1,1,1}; 
	int list_full = 5;

	int health_change; 
	int money_change; 
	char quitting;
	char rid_letter; 

	printf("\nYou come to an active intersection and press the crosswalk button, but after waiting for a total of 25 seconds, you grew impatient."
				"\nYou look around and spot a large wall of bushes. You decide it's better than just waiting there and take a shortcut through\nthe "
				"bushes. After wading through foliage for a while, you come out the other side and find a quite unusual sight.\n\nThere appears to "
				"be some sort of outdoor market with a ... 'Hobo' chic. \n\nIt couldn't hurt to look around. Maybe they have milk here?\n\n"); 
	
	while(quitting != y) //Splice MisAdventures and milkMain for choice loop
	{ 
		
		while(list_full >= 1) 
		{ 
			if(quitting == 'y' || *health < 1 || *money < 1)
      {
				 break;
      } 
			printf("\n HP: %d   Money: %d\n"
						"-------------------------------------------\n", *health, *money);

	    scene_select = rand()%5+1;
			if(scene_list[scene_select - 1] != 0) 
			{
				if(scene_select == 1) 
				{ 
					sceneOne(&health_change, &money_change);  
					scene_list[scene_select - 1] = 0; 
					*health += health_change; 

					*money += money_change;
					
					quitting = quit(); 
					while (quitting != 'y' && quitting != 'n') 
					{ 
						rid_letter = getchar(); 
						printf("Your thoughts seem jumbled. Should you go or nah? (y/n) "); 
						scanf(" %c", &quiting);
					}
						
					if(quitting == 'y') 
					{
						break; 
					}	
					else
					{
						printf("The adventure continues on.\n\n");
					}
		
				} 
				else if(random_select == 2) 
				{ 
					sceneTwo(&health_change, &money_change);
          scene_list[scene_select - 1] = 0;
          *health += health_change;

          *money += money_change;

          quitting = quit();
          while (quitting != 'y' && quitting != 'n')
          {
            rid_letter = getchar();
            printf("Your thoughts seem jumbled. Should you go or nah? (y/n) ");
            scanf(" %c", &quiting);
          }

          if(quitting == 'y')
          {
            break;
          }
          else
          {
            printf("The adventure continues on.\n\n");
          }
				} 
        else if(random_select == 3)
        {
          sceneThree(&health_change, &money_change);
          scene_list[scene_select - 1] = 0;
          *health += health_change;

          *money += money_change;

          quitting = quit();
          while (quitting != 'y' && quitting != 'n')
          {
            rid_letter = getchar();
            printf("Your thoughts seem jumbled. Should you go or nah? (y/n) ");
            scanf(" %c", &quiting);
          }

          if(quitting == 'y')
          {
            break;
          }
          else
          {
            printf("The adventure continues on.\n\n");
          }

        }
        else if(random_select == 4)
        {
          sceneFour(&health_change, &money_change);
          scene_list[scene_select - 1] = 0;
          *health += health_change;

          *money += money_change;

          quitting = quit();
          while (quitting != 'y' && quitting != 'n')
          {
            rid_letter = getchar();
            printf("Your thoughts seem jumbled. Should you go or nah? (y/n) ");
            scanf(" %c", &quiting);
          }

          if(quitting == 'y')
          {
            break;
          }
          else
          {
            printf("The adventure continues on.\n\n");
          }

        }

			}

		}

	}

}

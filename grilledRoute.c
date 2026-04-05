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
				"chewing on a old bone. It spots you and drops the bone, growling fiercly. You try to back away but it just growls "
				"louder.\nSeems you're not getting out of this without some kind of altercation.\n");

	int c; 
	int skill_check = rand()%12+1; 
	char junk;
	
	printf("What do you do? \n1) Distract the raccoon \n2) Fight it \n3) Run like a Coward \n");
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
		printf("You decide to distract the raccoon. \n");
		printf("You dig in your pocket and take out a shiny quarter. The raccoon immediately stops growling and makes a curious chitter, "
					"its eyes going wide with intrigue. You toss the coin into the bushes and the raccoon instantly gives chase.\n"
					"Well, that was easy. However, after a second of deep thought, you realize that coin wasn't a quarter, "
					"but a rare silver dollar you were hoping to save till it gained some real monetary value. So much for that investment.\n");
		*m = -1; 
	} 

	else if(c == 2) 
	{
		int enemy_hp = 10; 
		int action;
		printf("You decide to fight the raccoon. \n");
		printf("You give your best war cry as you charge straight at the small urban beastie. It hisses back and run towards you.\n");
		while(enemy_hp < 1 || action == 2)
		{ 
			skill_check = rand()%10+1;
			printf("Raccoon - HP: %d\n\n", enemy_hp);
			printf("1) Fight \n2) Give up \n");
			printf("> ");
			scanf("%d", &action);
			while(action != 1 && action != 2) 
			{
				junk = getchar();
      	printf("Your thoughts seem jumbled. Try again.\n> ");
      	scanf("%d", &action); 
			} 
			if(action == 1)
			{ 
				printf("You attack and do %d damage.\n", skill_check);
				if(skill_check >= 8)
				{ 
					printf("Critical Hit!!\n"); 
				}
				if(enemy_hp < 1)
				{
					break;
				}
				else
				{
					printf("\nRaccoon attacks! -5 hp\n");
					*h -= 5;
				} 
			} 
		} 
		if(enemy_hp < 1) 
		{
			printf("The raccoon was defeated\n\nIt falls flat on the ground as it shakes its head. You growl at it and it "
						"quickly scrambles to its feet and scampers away. You puff out your chest and put your hands on your "
						"hips triumphantly, basking in your victory.\n\nYou wonder if this counts as animal cruelty.\n");
		}
		else if(action == 2)
		{
			printf("You decide that the fight wasn't worth it and stop, being the bigger man. Unfortunately, your "
						"opponent is a wild raccoon. It scratches and bites you before running off.\nNext time, keep in mind "
						"that animals do not follow the rules of engagement.\n");
			*h -= 15;
		} 
	}
	else if(c == 3) 
	{
		printf("You decide to pull your family's secret technique. \n"
					"You immediately turn on your heels and sprint off in the opposite.\n\n");
		if(skill_check > 5)
		{
			printf("You take off so fast that the raccoon doesn't have time to react.\nYour family's technique truly is "
						"unbeatable.\n");
		}
		else 
		{
			printf("As you run away, you hear scampering behind you. You look behind you and see the raccoon right behind you."
						"\nYou scream in panic as you trip on a random rock and tumble into a large bush. Thankfully, this allows you "
						"lose the raccoon, at the cost of a few scratches.\n");
			*h = -3;
		}
	}
} 


void sceneThree(int *h, int *m)
{
	printf("After looking around for awhile, you come up to a more 'professional' stall surrounded by goats?? You walk up it "
				"and a guy carrying bottles of goat's milk comes from behind the stall. He look up at you in surprise, "
				"'Oh! A customer!! One moment,' he says as he places the bottles down on the table. 'What can I get you?' he asks. "
				"\nYou ask if he has regular, cow's milk. \n'Cow's milk? What do I look like, a Dairy Farmer?? Nope, only got goat's "
				"milk. However, I do have some jun-er, products... that I'm willing to sell, if you're interested.' \n\n"
				"Not exactly what you were looking for, but you might as well browse. \n");
	
	int c = 0;
	while(c == 0) 
	{
		printf("'Take a look.' \n\n1) Old Bandage \n2) Goat Yogurt \n3) Nothing \n");
		printf("%d", &c); 
		while(c != 1 && c != 2 && c != 3) 
		{
			junk = getchar();
      printf("Your thoughts seem jumbled. Try again.\n> ");
      scanf("%d", &c); 
		}

		if(c == 1)
		{
			printf("You ask to buy the bandage. \n'Really? I... Okay. Here ya go. Just don't ask where I got it. Seriously.\n");
			//Add bandage to inventory 
			*m = -5; 
		}
		else if(c == 2) 
		{
			printf("You ask to buy the yogurt.\n");
			printf("'Yeah, sorry. But, this is premium yogurt and it costs way more the chump change you got.'\n Well, that's hurtful.\n");
		//if( player has empty bottle )
		//{
		//	printf("'Wait, what's that in your pocket?'\nYou take out the empty bottle from your pocket.\n'Whoa! That's a rare water bottle"
		//				" from the collab with Lady Gaga!!'\nYou look down at it at the bottle in confusion.\n'Look, you can have the yogurt, "
		//				"just give me the bottle.'\nYou hand it over and get the yogurt. It's a win-win. Probably.\n");
		// 	add the yogurt to secret inventory 
		//	remove empty bottle from inventory 
		//}
			c = 0; 
		} 
		else if(c == 3) 
		{
			printf("'Alright then, stranger. See you.'\n");
		}
	}	
	printf("You leave the stallowner, the goat smell giving you a headache.\n" 
} 

void sceneFour(int *h, int *m)
{
	int scene_chance = rand()%3+1; 
	int c;
	if(scene_chance == 1)
	{
		printf("You pass by an empty dirt path. Strange, but you feel like something's supposed to be there.\n" 
	} 
	else
	{
		printf("You pass by a dirt path and see an old man struggling to take back his bag from a stray dog.\n");
		printf("What should you do? \n1) Help him \n2) Ignore him \n");
		printf("> ");
		scanf("%d", &c); 
		while(c != 1 && c != 2) 
		{
			junk = getchar();
      printf("Your thoughts seem jumbled. Try again.\n> ");
      scanf("%d", &c); 
		} 
		if(c == 1)
		{
			printf("You decide to help the old man.\nYou run up and scare away the dog and help the old man steady himself."
						"\nHe turns to you and gives a warm smile. 'Why, thank you, kind stranger. I know it's not much, but here.' He hands "
						"you a perfectly wrapped grill cheese sandwich, still warm to the touch. He then shambles off down the path."
						"\nYou feel a warmness fill you up from the interaction and you decide to hold onto the sandwich. Forntunately, "
						"you know better than to eat something given to you by a random stranger, so you you just shove it in your pocket "
						"and continue on.\n");
			//add the grilled cheese to inventory
		}
		else
		{
			printf("You decide to leave the old man in his time of need. Well, aren't you a upstanding citizen? Leaving an old man in "
						"distress.\n\nWhatever, it's your choice, you choose how to life your life.\n");
		} 
	}
}

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
				else if(scene_select == 2) 
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
        else if(scene_select == 3)
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
        else if(scene_select == 4)
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
				else if(scene_select == 5) 
				{ 
					sceneFive(&health_change, &money_change);
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

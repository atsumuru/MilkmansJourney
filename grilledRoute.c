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
	while (c == 0)
	{ 
		skill_check = rand()%12+1;
		printf("What do you do?\e[1;34m \n1) Go around \n2) De-escalate \n3) Tell them to move \n\e[0m");
		printf("> ");
		scanf("%d", &c);
		while(c != 1 && c != 2 && c != 3) 
		{
			junk = getchar();
      printf("\e1;31mYour thoughts seem jumbled. Try again.\e[0m\n> ");
      scanf("%d", &c); 
		}
		
		if(c == 1)
		{
			printf("\e[1;34mYou decide to go around. \e[0m\n\n");
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
			printf("\e[1;34mYou decide to de-escalate the situation. \e[0m\n\n"); 
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
							"arm over the\nother's shoulder.\nYou always did had a way with words.\n\n");
			} 
		}
		else if(c == 3)
		{
			printf("\e[1;34mYou decide to tell them to move. \e[0m\n\n");
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
				"embarrassment.\nPeople these days just don't have any common sense.\n\n");
			}
		} 
	} 
} 


void sceneTwo(int *h, int *m) 
{
	printf("As you walk down the stalls, you hear a loud crash as metal trashcan falls over in the way. A raccoon crawls out, "
				"chewing on a old bone. It spots you and drops the bone, growling fiercly. You try to back away but it just growls\n"
				"louder.\nSeems you're not getting out of this without some kind of altercation.\n\n");

	int c; 
	int skill_check = rand()%12+1; 
	char junk;
	
	printf("What do you do? \e[1;34m\n1) Distract the raccoon \n2) Fight it \n3) Run like a Coward \e[0m\n");
	printf("> ");
	scanf("%d", &c);
	while(c != 1 && c != 2 && c != 3)
	{
		junk = getchar(); 
		printf("\e[1;31mYour thoughts seem jumbled. Try again. \e[0m\n> ");
    scanf("%d", &c); 
	} 
	
	if(c == 1)
	{
		printf("\e[1;34mYou decide to distract the raccoon. \e[0m\n\n");
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
		printf("\e[1;34mYou decide to fight the raccoon. \e[0m\n\n");
		printf("You give your best war cry as you charge straight at the small urban beastie. It hisses back and run towards you.\n");
		while(enemy_hp < 1 || action == 2)
		{ 
			skill_check = rand()%10+1;
			printf("Raccoon - HP: %d\n\n", enemy_hp);
			printf("\e[1;34m1) Fight \n2) Give up \e[0m\n");
			printf("> ");
			scanf("%d", &action);
			while(action != 1 && action != 2) 
			{
				junk = getchar();
      	printf("\e[1;31mYour thoughts seem jumbled. Try again. \e[0m\n> ");
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
					printf("\nRaccoon attacks! -3 hp\n");
					*h -= 3;
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
		printf("\e[1;34mYou decide to pull your family's secret technique. \e[0m\n"
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
				"and a guy carrying bottles of goat's milk comes from behind the stall.\nHe look up at you in surprise, "
				"\e[1;33m'Oh! A customer!! One moment,' \e[0mhe says as he places the bottles down on the table. \e[1;33m'What can I get you?'"
				"\e[0m he asks.\n\nYou ask if he has regular, cow's milk. \n\n\e[1;33m'Cow's milk? What do I look like, a Dairy Farmer?? Nope, "
				"only got goat's milk. However, I do have some jun-er, products... that I'm willing to sell, if you're interested.'\e[0m \n\n"
				"Not exactly what you were looking for, but you might as well browse. \n");
	
	int c = 0;
	char junk;
	while(c == 0) 
	{
		printf("\n\e[1;33m'Take a look.' \e[1;34m\n1) Old Bandage \n2) Goat Yogurt \n3) Nothing \e[0m\n");
		scanf("%d", &c); 
		while(c != 1 && c != 2 && c != 3) 
		{
			junk = getchar();
      printf("\e[1;31mYour thoughts seem jumbled. Try again. \e[0m\n> ");
      scanf("%d", &c); 
		}

		if(c == 1)
		{
			printf("\e[1;34mYou ask to buy the bandage. \n\e[1;33m'Really? I... Okay. Here ya go. Just don't ask where I got it. Seriously.'\n");
			*h = 10;
			*m = -5; 
		}
		else if(c == 2) 
		{
			printf("\e[1;34mYou ask to buy the yogurt.\n");
			printf("\e[1;33m'Yeah, sorry. But, this is premium yogurt and it costs way more the chump change you got.'\n"
						"\e[0mWell, that's hurtful.\n");
			c = 0; 
		} 
		else if(c == 3) 
		{
			printf("\e[1;33m'Alright then, stranger. See you.'\n");
		}
	}	
	printf("\e[0mYou leave the stallowner, the goat smell giving you a headache.\n"); 
} 

void sceneFour(int *h, int *m, Inventory *inv)
{ 
	int c; 
	char junk;
	if((*inv).EB != 1) //Make it check for the empty bottle in inventory
	{
		printf("You pass by an empty dirt path. Strange, but you feel like something's supposed to be there.\n"); 
	} 
	else
	{
		printf("You pass by a dirt path and see an old man struggling to take back his bag from a stray dog.\n");
		printf("What should you do? \e[1;34m\n1) Help him \n2) Ignore him \e[0m\n");
		printf("> ");
		scanf("%d", &c); 
		while(c != 1 && c != 2) 
		{
			junk = getchar();
      printf("\e[1;31mYour thoughts seem jumbled. Try again. \e[0m\n> ");
      scanf("%d", &c); 
		} 
		if(c == 1)
		{
			printf("\e[1;34mYou decide to help the old man.\e[0m\nYou run up and scare away the dog and help the old man steady himself."
						"\nHe turns to you and gives a warm smile. \e[1;33m'Why, thank you, kind stranger. I know it's not much, but here.'\e[0m"
						" He hands you a perfectly wrapped grill cheese sandwich, still warm to the touch. He then shambles off down the path."
						"\nYou feel a warmness fill you up from the interaction and you decide to hold onto the sandwich. Forntunately, "
						"you know better than to eat something given to you by a random stranger, so you you just shove it in your pocket "
						"and continue on.\n");
			(*inv).GC = 1;
		}
		else
		{
			printf("\e[1;34mYou decide to leave the old man in his time of need.\e[0m Well, aren't you a upstanding citizen? Leaving an old man in "
						"distress.\n\nWhatever, it's your choice, you choose how to life your life.\n");
		} 
	}
} 

void sceneFive(int *h, int *m) 
{
	printf("You stare confused at a sign for a stall, unable to discern the gibberish scrawled across it. As you puzzle it over "
				"in your mind, you feel something small slip into your pocket and grab your wallet. You spin around and see a little\n"
				"kid trying to pickpocket you. You grab their hand and pull out their hand, still holding your wallet. They cower a "
				"bit with fearful eyes.\n");

	int c;  
	char junk;
	int skill_check = rand()%12+1;
	
	printf("What do you do? \e[1;34m\n1) Scold them \n2) Let them have it \n3) Yeet the child \e[0m\n");
	printf("> ");
	scanf("%d", &c);
	while(c != 1 && c != 2 && c != 3) 
	{
		junk = getchar();
    printf("\e[1;31mYour thoughts seem jumbled. Try again.\e[0m\n> ");
    scanf("%d", &c); 
	} 
	if(c == 1) 
	{
		printf("\e[1;34mYou decide to scold the child. \e[0m\n\n");
		printf("You rip the wallet out of their hand and begin to lecture them about stealing. The kid looks down in shame, their eyes" 
					" tearing up a little. After you're done, you let them go and they shamble off. It makes you feel kinda bad, but\n"
					"they needed to learn their lesson.\n\n");
	} 
	else if(c == 2)
	{
		printf("\e[1;34mYou decide to let the child have the money. \e[0m\n\n");
		printf("You give a gentle smile as you take out all your money from your wallet and hand it to the kid. They look "
					"bewildered at your offering as they take it. You let them go and start walking away.\n\nYou realize that without "
					"any money you can't buy milk, but al least, you helped out that kid. Suddenly, you feel someone run up and hug you."
					"\nYou turn and see the child holding onto you tightly, not wanting you to leave. You smile and pat their head before "
					"taking their hand.\n");
		*m = -150; 
	}
	else if(c == 3) 
	{
		printf("\e[1;34mYou decide to yeet the child. \e[0m\n\n"); 
		printf("Theft is never tolerated. You pick up the child and dropkick them into the bushes. You dust your hands and feel good "
					"about yourself for defending your property.\n \nSurrounding bystanders, however, did not approve of your self defense. ");
		if(skill_check < 9)
		{
			printf("You manage to get away from the angry mob.\nSome people seem really sensitive nowadays.\n");
		}
		else
		{
			printf("The mob quickly surrounds you and proceeds to beat you within an inch of your life.\nHonestly, what did you expect "
						"would happen?\n");
			*h = -15; 
		}
	} 
}



void grilledRoute(int *health, int *money, Inventory *inv) //Include the inventory lists when they get made 
{ 
	srand(time(NULL)); 

	int scene_select; 
	int scene_list[5] = {1,1,1,1,1}; 
	int list_full = 5; 


	int health_change = 0; 
	int money_change = 0; 
	char quitting;
	char rid_letter; 

	printf("\nYou come to an active intersection and press the crosswalk button, but after waiting for a total of 25 seconds, you grew impatient."
				"\nYou look around and spot a large wall of bushes. You decide it's better than just waiting there and take a shortcut through\nthe "
				"bushes. After wading through foliage for a while, you come out the other side and find a quite unusual sight.\n\nThere appears to "
				"be some sort of outdoor market with a ... 'Hobo' chic. \n\nIt couldn't hurt to look around. Maybe they have milk here?\n\n"); 
	
	while(quitting != 'n') //Splice MisAdventures and milkMain for choice loop
	{ 
		
		while(list_full >= 1) 
		{ 
			if(quitting == 'n' || *health < 1 || *money < 1)
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
						printf("\e[1;31mYour thoughts seem jumbled. \e[0mShould you go or nah? (y/n) "); 
						scanf(" %c", &quitting);
					}
						
					if(quitting == 'n') 
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
					if(*health < 0) 
					{ 
						*health = -125;
					}
					
          *money += money_change;

          quitting = quit();
          while (quitting != 'y' && quitting != 'n')
          {
            rid_letter = getchar();
            printf("\e[1;31mYour thoughts seem jumbled. \e[0mShould you go or nah? (y/n) ");
            scanf(" %c", &quitting);
          }

          if(quitting == 'n')
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
          sceneThree(&health_change, &money_change, inv);
          scene_list[scene_select - 1] = 0;
          *health += health_change;

          *money += money_change;

          quitting = quit();
          while (quitting != 'y' && quitting != 'n')
          {
            rid_letter = getchar();
            printf("\e[1;31mYour thoughts seem jumbled. \e[0mShould you go or nah? (y/n) ");
            scanf(" %c", &quitting);
          }

          if(quitting == 'n')
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
          sceneFour(&health_change, &money_change, );
          scene_list[scene_select - 1] = 0;
          *health += health_change;

          *money += money_change;

          quitting = quit();
          while (quitting != 'y' && quitting != 'n')
          {
            rid_letter = getchar();
            printf("\e[1;31mYour thoughts seem jumbled. \e[0mShould you go or nah? (y/n) ");
            scanf(" %c", &quitting);
          }

          if(quitting == 'n')
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
					if(money_change == -150) 
					{
						*money = -150;
					}
					else 
					{
         		*money += money_change; 
					}

          quitting = quit();
          while (quitting != 'y' && quitting != 'n')
          {
            rid_letter = getchar();
            printf("\e[1;31mYour thoughts seem jumbled. \e[0mShould you go or nah? (y/n) ");
            scanf(" %c", &quitting);
          }

          if(quitting == 'n')
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

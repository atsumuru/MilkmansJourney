#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "creamCrop.h"
#include "chickenRoute.h"

/*
Notes - Colour coding
	Narration: default (\e[0m)
	Dialogue: yellow (\e[1;33m)
	Decisions: blue (\e[1;34m)
	Warnings: red (\e[1;31m)
*/

//clear buffer so that my code will work lmao

void clearInput()
{
	char c;
	while(scanf("%c", &c) && c != '\n');
}

//user input choice function, allows up to three choices
//returns users choice as int for determining scenario

int inp(int x, int y, int z)
{
	int choice;
	while(choice!=x&&choice!=y&&choice!=z)
	{
		scanf("%d", &choice);

		if(choice!=x&&choice!=y&&choice!=z)
		{
			printf("\e[1;31mInvalid input\e[0m\n");
			clearInput();
		}
	}
	return choice;
}

//scenario for acquiring the rubber chicken of doom
void festival(int* m, Inventory* i, FILE* f)
{
	int c = 1;
	int molePos = 0;
	int turn = 1;
	int hits = 0;
	int str = 0;

	printf("\e[0mToday is Charlotte's birthday. To celebrate, you go with her to"
	       " the festival that's always held around this time of year.\n"
	       "She chuckles and gives you a playful jab on the side.\n"
	       "\e[1;33mYou're rather bold, you know, taking me on a date for my "
	       "birthday. Shall we hold hands?\n"
	       "\e[0mYou've learnt to just put up with her teasing by now. You "
	       "extend your hand towards her.\nCharlotte pouts in response.\n"
	       "\e[1;33mAww, but it's no fun when you don't get all flustered.\n"
	       "\e[0mShe lays her hand in yours, and the two of you proceed to visit"
	       " the festival's various stalls. There's so much to see and do.\n"
	       "You see a man on a stage juggling marbles between his fingers.\n"
	       "A food stand selling deep-fried salad.\nAnother food stand selling"
	       " plain white rice with nothing else.\nA third food stand selling"
	       "what initially appeared to be milk, but upon further inspection"
	       " you realized was just carbonated water with white food dye.\nYou"
	       " had gotten your hopes up for nothing.\n");
 	fprintf(f, "\e[0mToday is Charlotte's birthday. To celebrate, you go with her to"
	       " the festival that's always held around this time of year.\n"
	       "She chuckles and gives you a playful jab on the side.\n"
	       "\e[1;33mYou're rather bold, you know, taking me on a date for my "
	       "birthday. Shall we hold hands?\n"
	       "\e[0mYou've learnt to just put up with her teasing by now. You "
	       "extend your hand towards her.\nCharlotte pouts in response.\n"
	       "\e[1;33mAww, but it's no fun when you don't get all flustered.\n"
	       "\e[0mShe lays her hand in yours, and the two of you proceed to visit"
	       " the festival's various stalls. There's so much to see and do.\n"
	       "You see a man on a stage juggling marbles between his fingers.\n"
	       "A food stand selling deep-fried salad.\nAnother food stand selling"
	       " plain white rice with nothing else.\nA third food stand selling"
	       "what initially appeared to be milk, but upon further inspection"
	       " you realized was just carbonated water with white food dye.\nYou"
	       " had gotten your hopes up for nothing.\n");


	//minigame to unlock rubber chicken --> blind whackamole
	printf("\e[1;33mPLEASE! We've got to try it! Don't you see the prizes?\n"
	       "\e[0mYou look up and see a plushie that looks awfully familiar...\n"
	       "A laughing red cow sporting round earings. A very stylish mascot,"
	       " but why was it here of all places? This was no place for a cheese"
	       " mascot.\nIt seems your question will forever remain unanswered.\n"
	       "In any case, it seems like Charlotte is absolutely obsessed with it"
	       " for whatever reason. Perhaps you should try and win this prize for"
	       " her.\nAfter all, it's her birthday, and you have yet to buy her a "
	       "proper gift.\n");
  fprintf(f, "\e[1;33mPLEASE! We've got to try it! Don't you see the prizes?\n"
	       "\e[0mYou look up and see a plushie that looks awfully familiar...\n"
	       "A laughing red cow sporting round earings. A very stylish mascot,"
	       " but why was it here of all places? This was no place for a cheese"
	       " mascot.\nIt seems your question will forever remain unanswered.\n"
	       "In any case, it seems like Charlotte is absolutely obsessed with it"
	       " for whatever reason. Perhaps you should try and win this prize for"
	       " her.\nAfter all, it's her birthday, and you have yet to buy her a "
	       "proper gift.\n");

	while(c==1)
	{
		printf("The price to play is $10. You currently have: $%d\n", *m);
		printf("\e[1;34mWould you like to play the game?\n(1) Yes\n(2) No\n");
		c = inp(1,1,2);

		if(c==1&&*m>=10)
		{
			*m -= 10;
			printf("\e[0mYou purchase tickets for both youreslf and Charlotte.\n"
			       "\nThis game functions similarly to wack-a-mole, with "
			       "a few changes. There are three holes from which a mole"
			       " may appear, and you are to strike it with a hammer.\n"
			       "The catch is that you are blindfolded, and after each"
			       " hit the mole may or may not change positions.\nYou're allowed"
			       " seven turns, and you win should four of those succesfully"
			       " contact hit mole.\nTime to play:\n");
     fprintf(f, "Play the Game\n" 
             "\e[0mYou purchase tickets for both youreslf and Charlotte.\n"
			       "\nThis game functions similarly to wack-a-mole, with "
			       "a few changes. There are three holes from which a mole"
			       " may appear, and you are to strike it with a hammer.\n"
			       "The catch is that you are blindfolded, and after each"
			       " hit the mole may or may not change positions.\nYou're allowed"
			       " seven turns, and you win should four of those succesfully"
			       " contact hit mole.\nTime to play:\n");

			while (turn<8&&hits<4)
			{
				printf("Turn #%d\n", turn);
				molePos = rand()%3+1;
				printf("\e[1;34mWhich hole would you like to strike?"
				       "\n(1)\n(2)\n(3)\n\e[0m");
				str = inp(1,2,3);

				if (str==molePos)
				{
					printf("Nice! You landed a hit!\n");
					hits++;
				}
				else
				{
					printf("Dang, you missed.\n");
				}
				turn++;
			}

			if (hits==4)
			{
				c = 0;
				printf("Congratulations! You've earned the top prize!\nThe man "
				       "working this stall hands you the plush, and gives Charlotte"
				       " a rubber chicken as a consolation prize.\nHer face beams "
				       "as you present the glorious prize to her.\n"
				       "\e[1;33mI can't thank you enough! Please, at least take "
				       "my rubber chicken in exchange for giving me this.\n"
				       "\e[0mYou didn't really give a crap about the cow, you were just "
				       "happy to see Charlotte smile.\nBut she insisted she at least"
				       " give you something in return for your hard work.\n"
				       "\e[1;33mIt's no ordinary rubber chicken, after all. It's "
				       "the \"Rubber Chicken of Doom!\" Just take it already!\n");
        fprintf(f, "Congratulations! You've earned the top prize!\nThe man "
				       "working this stall hands you the plush, and gives Charlotte"
				       " a rubber chicken as a consolation prize.\nHer face beams "
				       "as you present the glorious prize to her.\n"
				       "\e[1;33mI can't thank you enough! Please, at least take "
				       "my rubber chicken in exchange for giving me this.\n"
				       "\e[0mYou didn't really give a crap about the cow, you were just "
				       "happy to see Charlotte smile.\nBut she insisted she at least"
				       " give you something in return for your hard work.\n"
				       "\e[1;33mIt's no ordinary rubber chicken, after all. It's "
				       "the \"Rubber Chicken of Doom!\" Just take it already!\n");

				//if not already have rubber chicken
				if (i -> RC == 0)
				{
					printf("\e[0mShe shoves the chicken into your arms. Well, at the very "
					       "least, you were intrigued by it. You decide to hold on to it\n");
          fprintf(f, "\e[0mShe shoves the chicken into your arms. Well, at the very "
					       "least, you were intrigued by it. You decide to hold on to it\n");

					printf("\nYou're now in possession of the Rubber Chicken of Doom!\n");
          fprintf(f, "\nYou're now in possession of the Rubber Chicken of Doom!\n");

					//Add rubber chicken to inventory
					i -> RC = 1;
				}

				//if already have rubber chicken
				else
				{
					printf("\e[0mYou already have this Rubber Chicken of Doom. You accept the new"
					       " one from Charlotte to appease her, but you'll just get rid of"
					       " it later since it's pointless to have more than one.\n");
          fprintf(f, "\e[0mYou already have this Rubber Chicken of Doom. You accept the new"
					       " one from Charlotte to appease her, but you'll just get rid of"
					       " it later since it's pointless to have more than one.\n");
				}

			}
			else
      {
				printf("Well, better luck next time.\n");
        fprintf(f,"You failed at the game.\n" 
                  "Well, better luck next time.\n");
      }

			turn = 1;
			hits = 0;
		}

		else if(c==1&&*m<10)
		{
			printf("\e[31mYou don't have enough money to play.\e[0m\n");
		}

		else
		{
			printf("\e[0mYou apologize and explain to Charlotte that you can't play."
			       "\nShe's noticeably upset, but eventually cheers up as you "
			       "move on to other activities.\n");
     fprintf(f, "\e[0mYou apologize and explain to Charlotte that you can't play."
			       "\nShe's noticeably upset, but eventually cheers up as you "
			       "move on to other activities.\n");
		}
	}
}


//function for gambling job
int bet(int q)
{
	printf("\e[0mYou've bet $%d\n", q);
	if ((rand()%2)==1)
	{
		printf("You win! You've earned a 20%% profit.\n");
		return q + (q/5);
	}
	else
	{
		printf("Oh no! You lose half of what you bet.\n");
		return -(q/2);
	}
}

//randomly selects a job (minigame) for player, returns cash money
void job(int* hp, int* money, FILE* f)
{
	int enemyHP = 30;
	int choice;
	int gamble;
	int enemyAttack;
	int hits = 0;
	int code[5];
	int guess[5];
	int j = 0;


	int k = rand()%3;
	printf("Johnny gives you a tap on the shoulder.\n"
         "\e[1;33mI've got another job for you today.\n\e[0m");
  fprintf(f, "Johnny gives you a tap on the shoulder.\n"
         "\e[1;33mI've got another job for you today.\n\e[0m");

	switch(k)
	{
	//brawl (rock-paper-scissors style minigame, best of three.)
	case 0:
		printf("Today's job: Brawl.\n");
    fprintf(f, "Today's job: Brawl.\n");

		while(*hp>0&&enemyHP>0)
		{
			printf("\e[1;34mWhich style of attack would you like to use?\n"
			       "(1) Power\n(2) Speed\n(3) Technical\n");
			choice = inp(1,2,3);
			enemyAttack = rand()%3 + 1;

			if (enemyAttack == 1)
			{
				printf("The enemy chose a \e[1;34mPower\e[0m attack\n");

				if(choice==1)
				{
					printf("You're evenly matched.\n");
					printf("Your HP:%d\nEnemy HP:%d\n", *hp, enemyHP);
				}
				else if(choice==2)
				{
					printf("You overwhelm him with your speed.\n");
					enemyHP-=rand()%20+1;
					printf("Your HP:%d\nEnemy HP:%d\n", *hp, enemyHP);

				}
				else
				{
					printf("You succumb to the brute strength of your opponent.\n");
					*hp-=rand()%20+1;
					printf("Your HP:%d\nEnemy HP:%d\n", *hp, enemyHP);
				}
			}

			else if(enemyAttack == 2)
			{
				printf("The enemy chose a \e[1;34mSpeed\e[0m attack\n");

				if(choice==1)
				{
					printf("You are overwhelmed by your opponent's speed\n");
					*hp-=rand()%20+1;
					printf("Your HP:%d\nEnemy HP:%d\n", *hp, enemyHP);
				}
				else if(choice==2)
				{
					printf("You're evenly matched.\n");
					printf("Your HP:%d\nEnemy HP:%d\n", *hp, enemyHP);
				}
				else
				{
					printf("You outsmart him with your technique.\n");
					enemyHP-=rand()%20+1;
					printf("Your HP:%d\nEnemy HP:%d\n", *hp, enemyHP);
				}
			}

			else
			{
				printf("The enemy chose a \e[1;34mTechnical\e[0m attack\n");

				if(choice==1)
				{
					printf("You slam your opponent with your brute strength.\n");
					enemyHP-=rand()%20+1;
					printf("Your HP:%d\nEnemy HP:%d\n", *hp, enemyHP);
				}
				else if(choice==2)
				{
					printf("You are outsmarted by your opponent.\n");
					*hp-=rand()%20+1;
					printf("Your HP:%d\nEnemy HP:%d\n", *hp, enemyHP);
				}
				else
				{
					printf("You are evenly matched.\n");
					printf("Your HP:%d\nEnemy HP:%d\n", *hp, enemyHP);
				}
			}
		}

		if(hp>0&&enemyHP<=0)
		{
			*money+=25;
			printf("You were awarded $25 for your victory. You now hold $%d.\n", *money);
			printf("You return to the penthouse triumphantly.\n");
      fprintf(f, "You were awarded $25 for your victory. You return to the penthouse triumphantly.\n");

			if(*hp<20)
			{
				printf("After some rest, your HP is restored to 50.\n");
				*hp=20;
			}
			else if(*hp>=20)
			{
				printf("After some rest, your HP increases by 10.\n");
				*hp+=10;
			}
		}

		if(*hp<=0&&enemyHP>0)
		{
			printf("You are knocked unconscious. Charlotte carries you back to the penthouse.\n"
			       "After some rest, your HP is restored to 20.\n");
			*hp=20;
      fprintf(f, "You are knocked unconscious. Charlotte carries you back to the penthouse.\n"
			       "After some rest, your HP is restored to 20.\n");
		}

		break;

	//gambling (literally just gamble money)
	case 1:
		choice = 1;
		*money+=25;
		printf("Today you are tasked with making some\"investments\"... at the casino\n"
		       "Johnny has lent you $25 to start with. You may add some additional funds"
		       " at your own expense.\n");
    fprintf(f, "Today you are tasked with making some\"investments\"... at the casino\n"
		       "Johnny has lent you $25 to start with. You may add some additional funds"
		       " at your own expense.\n");

		while(choice==1&&*money>25)
		{
			printf("You currently have $%d\n", *money);
			printf("\e[1;34mWould you like to gamble?\n(1) Yes\n(2) No\n");
			choice=inp(1,1,2);
			printf("\e[0m");
			if (choice==1)
			{
				printf("\e[1;34mHow much money would you like gamble?\n(1) $25\n(2) $50\n(3) Life Savings\n");
				gamble = inp(1,2,3);

				if (gamble==1)
				{
					*money += bet(25);
				}
				else if(gamble==2)
				{
					if (*money<50)
						printf("You don't have enough money.\n");
					else
					{
						*money += bet(50);
					}
				}
				else
				{
					*money += bet(*money);
				}
			}

			printf("After having gambled to your heart's content, you return to the penthouse with $%d\n\n", *money);
      fprintf(f, "After having gambled to your heart's content, you return to the penthouse with $%d\n\n", *money);
			break;

		//code cracking (a random code is generated, input correct number sequence to win)
		case 2:
			printf("\e[0mYour job is find the correct number sequence in order to crack a safe\n"
			       "The sequence is composed of numbers 1, 2, and 3. There are a total of"
			       " 5 digits in the code.\n");
			fprintf(f, "\e[0mYour job is find the correct number sequence in order to crack a safe\n"
			       "The sequence is composed of numbers 1, 2, and 3. There are a total of"
			       " 5 digits in the code.\n");
			for (j=0; j<5; j++)
			{
				code[j]=rand()%3 + 1;
			}


			while(hits<5)
			{
				hits = 0;

				for (j=0; j<5; j++)
				{
					if (j==0)
						printf("\e[1;34mEnter your guess for the first digit: ");
					else
						printf("\e[1;34mEnter your guess for the next digit: ");

					guess[j]=inp(1,2,3);
					clearInput();
				}

				for (j=0; j<5; j++)
				{
					if (code[j]==guess[j])
					{
						printf("\e[0m\e[42m%d\e[0m", guess[j]);
						hits++;
					}
					else
						printf("\e[0m%d", guess[j]);
				}
				printf("\n");
			}

			printf("You cracked the code! As a reward, you've earned $25\n"
			       "You make your way back to the penthouse.\n");
      fprintf(f, "You cracked the code! As a reward, you've earned $25\n"
			       "You make your way back to the penthouse.\n");
			*money+=25;
			break;

//in case something messes up (this is totally a feature, not a bug)
		default:
			printf("Johnny didn't have any jobs for you today.\n");
			break;
		}
	}
}
void chickenRoute(int* health, int* money, Inventory *inv)
{
	FILE* f = fopen("AdventLog.txt","a");
	static int mem = 0;
	int choice = 0;
	int j = 0;

//Common intro to route

	printf("\e[0mStill disoriented from the accident, you begin stumbling along a path"
	       " leading to the metro station. You enter the subway and fall unconscious.\n"
	       "Upon waking, you find that you've been transported to a penthouse"
	       " in the midst of a large, unfamiliar city.\nA glance to your right reveals"
	       " a maid sitting neatly beside your bed, holding an expensive tray of food.\n"
	       "\e[1;33m~ Good morning ~ \e[0m\n"
	       "She smiles sweetly and hands you the breakfast platter. You scratch your head "
	       "in confusion, but accept the food.\nOnly when you begin to eat do you realize"
	       " truly how hungry you were. You devour every last scrap ravenously.\nStill beside "
	       "you, the maid softly chuckles.\n"
	       "\e[1;33mMy my, well aren't you hungry! Shall I prepare you some tea?\e[0m\n"
	       "You nod. She quickly strides over to a table, upon which rested a tea kettle. "
	       "She pours two cups of tea, returns to your side,\nand hands you one before sipping"
	       " on her own. You decide now is a good time to ask a few questions:\n");
  fprintf(f, "\e[0mStill disoriented from the accident, you begin stumbling along a path"
	       " leading to the metro station. You enter the subway and fall unconscious.\n"
	       "Upon waking, you find that you've been transported to a penthouse"
	       " in the midst of a large, unfamiliar city.\nA glance to your right reveals"
	       " a maid sitting neatly beside your bed, holding an expensive tray of food.\n"
	       "\e[1;33m~ Good morning ~ \e[0m\n"
	       "She smiles sweetly and hands you the breakfast platter. You scratch your head "
	       "in confusion, but accept the food.\nOnly when you begin to eat do you realize"
	       " truly how hungry you were. You devour every last scrap ravenously.\nStill beside "
	       "you, the maid softly chuckles.\n"
	       "\e[1;33mMy my, well aren't you hungry! Shall I prepare you some tea?\e[0m\n"
	       "You nod. She quickly strides over to a table, upon which rested a tea kettle. "
	       "She pours two cups of tea, returns to your side,\nand hands you one before sipping"
	       " on her own. You decide now is a good time to ask a few questions:\n");
	printf("\e[1;34m(1) Where am I?\e[0m\n");
	choice = inp(1,1,1);
	printf("The maid sighs in dissapointment.\n"
         "\e[1;33mSo it would seem you do have amnesia after all. Have you really no idea "
	       "whatsoever?\n"
         "\e[0mYou remain silent as you comb through your recent memories...\n");
  fprintf(f, "Where am I?\n"
         "The maid sighs in dissapointment.\n"
         "\e[1;33mSo it would seem you do have amnesia after all. Have you really no idea "
	       "whatsoever?\n"
         "\e[0mYou remain silent as you comb through your recent memories...\n");


//First time looping through this route, everyone will die.

	if (mem==0)
	{
		printf("Realizing you truly have no memory of this place, you shake your head.\n"
		       "Once more the maid sighs, then starts to explain:\n"
		       "\e[1;33mI suppose I had ought to reintroduce myself, although it pains me "
		       "to know you've forgotten everything. My name is Charlotte...\n"
		       "\e[0mYou begin putting together the pieces. You've somehow replaced "
		       "been transported to an alternate reality:\none where you live here"
		       " with Charlotte and Johnny, who you've apparently been friends with"
		       " since childhood.\nAll you wanted was to get some damn milk. You can't "
		       "help but chuckle at the absurdity of it all.\n"
		       "\e[1;33mYou've been out cold for three days straight. We've been terribly "
		       "worried about you.\n"
		       "\e[0mA young man steps into the room. This was Johnny, apparently your best"
		       " friend since middle school.\n"
		       "\e[1;33mHey you, you're finally awake!\n"
		       "\e[0mYou spit out a mouthful of tea. Of all the things he could've said!\n"
		       "\e[1;33mWe've been worried sick about you, bud. Don't go entering any on us"
		       " again! Especially on Sandwich Sunday.\nYou still haven't told us your secret"
		       " grilled cheese recipe, after all. Those sandwiches are to die for!\n"
		       "\e[0mHe gives you a friendly slap on the back. Your conversation continues"
		       " with mostly normal banter.\nIt's rather uncanny just how natural it all feels -"
		       " these people really did seem to know you, even though you've never met.\n"
		       "The \"you\" who existed in their memories, although false, must have "
		       "reflected your own personality quite accurately.\nJohnny and Charlotte "
		       "knew things about you like your favourite foods, your birthday, etc...\n"
		       "But the details of your life were totally wrong.\n"
		       "\e[1;33mWell, you'd oughta rest up some more. Although were friends, you also"
		       " work for me. I'm going to have you run a little job for me tomorrow.\n"
		       "\e[0mJohnny parts with those words, leaving you completely baffled.\n"
		       "You worked for him? You had a job to do tomorrow?\n"
		       "But you just got here! And you didn't even know where the hell you were, "
		       "let alone any of these people!\nYou ask Charlotte if you could "
		       "have a glass of milk to help you calm down.\n"
		       "\e[1;33mHave you lost it? Everyone knows that drinking milk is the habit "
		       "of evildoers and the morally corrupt.\nYou wouldn't want to associate "
		       "yourself with the likes of them.\n"
		       "\e[0mWonderful.\nCharlotte soon departs, leaving you to ponder your situation"
		       " alone. You've been marooned here in this world, unsure of how to leave.\n"
		       "This may just become your new reality. If you never make it back to your"
		       " own world, you'll have to continue living here with Johnny and Charlotte.\n"
		       "And you'll never be able to drink milk again.\nWith that final thought, you "
		       "go to sleep for the night.\n\n"
		       "\e[1;33mWell, here we go. I'll be your personal guide for this job.\n"
		       "\e[0mCharlotte's face shines with a beaming smile. She had been asked to show"
		       " you around the town, since you had no memory of it.\nAlong the way, you pick"
		       " up that item Johnny asked you to get. Your first job here in this new world.\n");
    fprintf(f, "Realizing you truly have no memory of this place, you shake your head.\n"
		       "Once more the maid sighs, then starts to explain:\n"
		       "\e[1;33mI suppose I had ought to reintroduce myself, although it pains me "
		       "to know you've forgotten everything. My name is Charlotte...\n"
		       "\e[0mYou begin putting together the pieces. You've somehow replaced "
		       "been transported to an alternate reality:\none where you live here"
		       " with Charlotte and Johnny, who you've apparently been friends with"
		       " since childhood.\nAll you wanted was to get some damn milk. You can't "
		       "help but chuckle at the absurdity of it all.\n"
		       "\e[1;33mYou've been out cold for three days straight. We've been terribly "
		       "worried about you.\n"
		       "\e[0mA young man steps into the room. This was Johnny, apparently your best"
		       " friend since middle school.\n"
		       "\e[1;33mHey you, you're finally awake!\n"
		       "\e[0mYou spit out a mouthful of tea. Of all the things he could've said!\n"
		       "\e[1;33mWe've been worried sick about you, bud. Don't go entering any on us"
		       " again! Especially on Sandwich Sunday.\nYou still haven't told us your secret"
		       " grilled cheese recipe, after all. Those sandwiches are to die for!\n"
		       "\e[0mHe gives you a friendly slap on the back. Your conversation continues"
		       " with mostly normal banter.\nIt's rather uncanny just how natural it all feels -"
		       " these people really did seem to know you, even though you've never met.\n"
		       "The \"you\" who existed in their memories, although false, must have "
		       "reflected your own personality quite accurately.\nJohnny and Charlotte "
		       "knew things about you like your favourite foods, your birthday, etc...\n"
		       "But the details of your life were totally wrong.\n"
		       "\e[1;33mWell, you'd oughta rest up some more. Although were friends, you also"
		       " work for me. I'm going to have you run a little job for me tomorrow.\n"
		       "\e[0mJohnny parts with those words, leaving you completely baffled.\n"
		       "You worked for him? You had a job to do tomorrow?\n"
		       "But you just got here! And you didn't even know where the hell you were, "
		       "let alone any of these people!\nYou ask Charlotte if you could "
		       "have a glass of milk to help you calm down.\n"
		       "\e[1;33mHave you lost it? Everyone knows that drinking milk is the habit "
		       "of evildoers and the morally corrupt.\nYou wouldn't want to associate "
		       "yourself with the likes of them.\n"
		       "\e[0mWonderful.\nCharlotte soon departs, leaving you to ponder your situation"
		       " alone. You've been marooned here in this world, unsure of how to leave.\n"
		       "This may just become your new reality. If you never make it back to your"
		       " own world, you'll have to continue living here with Johnny and Charlotte.\n"
		       "And you'll never be able to drink milk again.\nWith that final thought, you "
		       "go to sleep for the night.\n\n"
		       "\e[1;33mWell, here we go. I'll be your personal guide for this job.\n"
		       "\e[0mCharlotte's face shines with a beaming smile. She had been asked to show"
		       " you around the town, since you had no memory of it.\nAlong the way, you pick"
		       " up that item Johnny asked you to get. Your first job here in this new world.\n");

		for(j=0; j<4; j++)
		{
			printf("\n\e[0mA new morning. You get dressed and go out to meet with Johnny\n");
			job(health, money, f);
		}

		printf("\e[1;33mGood work, lad.\n"
           "\e[0mJohnny rests a hand upon your shoulder. He's beaming. You inquire"
		       " as to what may be the source of his present joviality.\n"
           "\e[1;33mI've just received an incredibly favourable promotion! This will"
		       " assuredly prove to be a massive boon for our finances.\nTonight, we party!\n"
           "\e[0mAs though on queue, Charlotte appears carrying one of Johnny's finest bottles"
		       " of champagne. She pops the cork.\nA fountain of fizz sprouts from the bottle's"
		       " opening, showering down upon everyone. The three of you cheer.\n"
		       "You play all sorts of games until you all completely knock out.\n");
    fprintf(f, "\e[1;33mGood work, lad.\n"
           "\e[0mJohnny rests a hand upon your shoulder. He's beaming. You inquire"
		       " as to what may be the source of his present joviality.\n"
           "\e[1;33mI've just received an incredibly favourable promotion! This will"
		       " assuredly prove to be a massive boon for our finances.\nTonight, we party!\n"
           "\e[0mAs though on queue, Charlotte appears carrying one of Johnny's finest bottles"
		       " of champagne. She pops the cork.\nA fountain of fizz sprouts from the bottle's"
		       " opening, showering down upon everyone. The three of you cheer.\n"
		       "You play all sorts of games until you all completely knock out.\n");

		job(health, money, f);
		printf("As per usual, Johnny praises you for your hard work. But today, he seems"
		       " rather distracted.\nHe paces back and forth, checking his phone sporadically."
		       " It finally rings, and he quickly rushes outside.\nHe didn't return for the "
		       "rest of the night.\nYou ask Charlotte about his odd behavior, but she simply"
		       " shrugs her shoulders.\n"
		       "\e[1;33mIt's like this every so often. I think he's gotten into some dirty "
		       "business... but it's not really my place to question him.\n"
		       "\e[0mSomething tells you she knows more than she's letting on. There's a hint"
		       " of anger in her voice. Perhaps even malice.\nWhatever it is that Johnny is"
		       " up to is something she truly detestes.\nYou consider prodding for more "
		       "information, but she changes the subject.\nYou continue pondering this "
		       "until you fall asleep.\n");
		fprintf(f, "As per usual, Johnny praises you for your hard work. But today, he seems"
		       " rather distracted.\nHe paces back and forth, checking his phone sporadically."
		       " It finally rings, and he quickly rushes outside.\nHe didn't return for the "
		       "rest of the night.\nYou ask Charlotte about his odd behavior, but she simply"
		       " shrugs her shoulders.\n"
		       "\e[1;33mIt's like this every so often. I think he's gotten into some dirty "
		       "business... but it's not really my place to question him.\n"
		       "\e[0mSomething tells you she knows more than she's letting on. There's a hint"
		       " of anger in her voice. Perhaps even malice.\nWhatever it is that Johnny is"
		       " up to is something she truly detestes.\nYou consider prodding for more "
		       "information, but she changes the subject.\nYou continue pondering this "
		       "until you fall asleep.\n");

		festival(money, inv, f);

		printf("You return from the festival late at night, completely exhausted.\n"
		       "\nThe next morning, with the sun still yet to rise, you were roused "
		       "from your sleep.\nYou see Johnny standing before you, a grim expression"
		       " upon his face.\n"
		       "\e[1;33mI'm going to have to ask you to do another job for me...\n"
		       "but this one won't be like the others.\n"
		       "\e[0mAnd then he presents you with a pistol. You stare at it in silence.\n"
		       "Did Johnny expect you to use this?\nOn who?\nWhy?\nSurely, it must be a joke\n"
		       "\e[1;33mI made a mistake. If we don't do this... we'll lose everything...\n"
		       "\e[0mWe? Who's we? It'll be you carrying out the deed. Johnny is just the one"
		       " ordering you to do it.\nA sickening dread starts to build up in your stomach.\n"
		       "This is crazy! You'll just refuse. Johnny can't force you to kill anyone.\n"
		       "You just want to figure out how to get yourself some milk. Murder was not on"
		       "your shopping list.\n"
		       "\e[1;33m...They took Charlotte. I really don't have time to explain. Just go!\n"
		       "I'll be there to back you up, but you gotta hold out on your own for a while.\n"
		       "\e[0mYou rush outside and sprint to the public park as soon as possible.\n"
		       " There, in the dark, you see a collection of silhouettes hud'dled beside the pond.\n"
		       "Dawn starts to break, and the pond illuminates with the milky hues of sunrise.\n"
		       "Then you see her... At the center of their huddle was Charlotte. One of the men "
		       "held a pistol to her head.\nYou couldn't make out what they were saying.\n"
		       "You grip your own pistol and try to think of a way to stop them. They can't kill"
		       " Charlotte! You won't allow it!\n"
		       "\e[1;33mYou'll tell us where it is. Tell us, and we'll leave everyone alone.\n"
		       "\e[0mYou managed to crawl within hearing range. You count four men total. If"
		       " only you had a way to distract them...\nHand hand suddenly clasps over your mouth"
		       " from behind, and you're dragged out into the field beside the pond.\nYou face "
		       "Charlotte. She had seemed relatively composed before, but now she begins to panick.\n"
		       "\e[1;33mIf you don't care about your own life, then what about his? Will you talk now?\n"
		       "\e[0mThe man holding the gun snickers, then beckons another one of the goons forwards."
		       "\nA knife is pressed against your throat, digging into your skin.\nYou feel a warm trail"
		       " of blood trickle down your neck.\nThey still haven't noticed your firearm, you may "
		       "be able to free yourself from this situation.\nCharlotte cries out in dismay.\n"
		       "\e[1;33mPlease don't! He doesn't know anything!\n"
		       "\e[0mHer composure breaks. She shouts maniacally, pleading for your life.\nThis "
		       "was a terrible situation. You'd meant to save her, yet now you stood at the mercy"
		       " of these men as Charlotte attempted to bargain for your safety.\nYou still had your"
		       " gun. Perhaps, if you took out the one pointing a Charlotte, the two of you could"
		       "flee amidst the confusion.\nBut before a moment could arise, Charlotte spoke\n"
		       "\e[1;33mLet him go, and I'll tell you.\nI'll tell you where the milk is.\n"
		       "\e[0mWait a minute. Actually, wait a whole damn year! You mean these guys were "
		       "really trying to kill the two of you over some MILK?!?!\nThe man holding you releases"
		       " his grip. You realize this is your chance. You pull out the gun you've beeen hiding "
		       "and...\nA loud bang cracks through the silence of dawn...\nYou never pulled the "
		       "trigger.\nYou look back at Charlotte. She's gasping for breath...\nA crimson stain"
		       " spreads from her side.\nShe clutches it weakly, then falls forward onto the ground.\n"
		       "As her body slumps over, you see Johnny standing behind her.\nSmoke trailed from the"
		       " barrel of his gun.\nHe fires thrice more, taking down all but one of the goons.\n"
		       "Then he walks up to you, and extends out a hand.\nYou have no idea what to do anymore.\n"
		       "He just killed Charlotte, but it hasn't really registered yet."
		       "\nThen the gravity of what's just happened sinks in. You barrel your fist into Johnny's"
		       " face, crushing his nose.\n"
		       "\e[1;33mIt had to be done! She was about to tell them where I've hidden my milk supply.\n"
		       "It's worth more than anyone's life. I'm just glad I got to at least save yours...\n"
		       "\e[0mJohnny worked at the cheese production plant, and recently was promoted to "
		       "executive manager of dairy.\nHe abused this position to deal raw milk on the streets, "
		       "even though selling milk was prohibited.\nThese dealings had attracted the attention of"
		       " wrongdoers who sought to capture the milk supply for themselves.\nWhat a load of crap.\n"
		       "He just killed Charlotte. You shouldn't have to listen to his excuses.\nYou stumble over"
		       " to Charlotte's side, and clasp her hand in your own... she's already dead.\n"
		       "You then turn to Johnny, and point the gun at him.\n");
		fprintf(f, "You return from the festival late at night, completely exhausted.\n"
		       "\nThe next morning, with the sun still yet to rise, you were roused "
		       "from your sleep.\nYou see Johnny standing before you, a grim expression"
		       " upon his face.\n"
		       "\e[1;33mI'm going to have to ask you to do another job for me...\n"
		       "but this one won't be like the others.\n"
		       "\e[0mAnd then he presents you with a pistol. You stare at it in silence.\n"
		       "Did Johnny expect you to use this?\nOn who?\nWhy?\nSurely, it must be a joke\n"
		       "\e[1;33mI made a mistake. If we don't do this... we'll lose everything...\n"
		       "\e[0mWe? Who's we? It'll be you carrying out the deed. Johnny is just the one"
		       " ordering you to do it.\nA sickening dread starts to build up in your stomach.\n"
		       "This is crazy! You'll just refuse. Johnny can't force you to kill anyone.\n"
		       "You just want to figure out how to get yourself some milk. Murder was not on"
		       "your shopping list.\n"
		       "\e[1;33m...They took Charlotte. I really don't have time to explain. Just go!\n"
		       "I'll be there to back you up, but you gotta hold out on your own for a while.\n"
		       "\e[0mYou rush outside and sprint to the public park as soon as possible.\n"
		       " There, in the dark, you see a collection of silhouettes hud'dled beside the pond.\n"
		       "Dawn starts to break, and the pond illuminates with the milky hues of sunrise.\n"
		       "Then you see her... At the center of their huddle was Charlotte. One of the men "
		       "held a pistol to her head.\nYou couldn't make out what they were saying.\n"
		       "You grip your own pistol and try to think of a way to stop them. They can't kill"
		       " Charlotte! You won't allow it!\n"
		       "\e[1;33mYou'll tell us where it is. Tell us, and we'll leave everyone alone.\n"
		       "\e[0mYou managed to crawl within hearing range. You count four men total. If"
		       " only you had a way to distract them...\nHand hand suddenly clasps over your mouth"
		       " from behind, and you're dragged out into the field beside the pond.\nYou face "
		       "Charlotte. She had seemed relatively composed before, but now she begins to panick.\n"
		       "\e[1;33mIf you don't care about your own life, then what about his? Will you talk now?\n"
		       "\e[0mThe man holding the gun snickers, then beckons another one of the goons forwards."
		       "\nA knife is pressed against your throat, digging into your skin.\nYou feel a warm trail"
		       " of blood trickle down your neck.\nThey still haven't noticed your firearm, you may "
		       "be able to free yourself from this situation.\nCharlotte cries out in dismay.\n"
		       "\e[1;33mPlease don't! He doesn't know anything!\n"
		       "\e[0mHer composure breaks. She shouts maniacally, pleading for your life.\nThis "
		       "was a terrible situation. You'd meant to save her, yet now you stood at the mercy"
		       " of these men as Charlotte attempted to bargain for your safety.\nYou still had your"
		       " gun. Perhaps, if you took out the one pointing a Charlotte, the two of you could"
		       "flee amidst the confusion.\nBut before a moment could arise, Charlotte spoke\n"
		       "\e[1;33mLet him go, and I'll tell you.\nI'll tell you where the milk is.\n"
		       "\e[0mWait a minute. Actually, wait a whole damn year! You mean these guys were "
		       "really trying to kill the two of you over some MILK?!?!\nThe man holding you releases"
		       " his grip. You realize this is your chance. You pull out the gun you've beeen hiding "
		       "and...\nA loud bang cracks through the silence of dawn...\nYou never pulled the "
		       "trigger.\nYou look back at Charlotte. She's gasping for breath...\nA crimson stain"
		       " spreads from her side.\nShe clutches it weakly, then falls forward onto the ground.\n"
		       "As her body slumps over, you see Johnny standing behind her.\nSmoke trailed from the"
		       " barrel of his gun.\nHe fires thrice more, taking down all but one of the goons.\n"
		       "Then he walks up to you, and extends out a hand.\nYou have no idea what to do anymore.\n"
		       "He just killed Charlotte, but it hasn't really registered yet."
		       "\nThen the gravity of what's just happened sinks in. You barrel your fist into Johnny's"
		       " face, crushing his nose.\n"
		       "\e[1;33mIt had to be done! She was about to tell them where I've hidden my milk supply.\n"
		       "It's worth more than anyone's life. I'm just glad I got to at least save yours...\n"
		       "\e[0mJohnny worked at the cheese production plant, and recently was promoted to "
		       "executive manager of dairy.\nHe abused this position to deal raw milk on the streets, "
		       "even though selling milk was prohibited.\nThese dealings had attracted the attention of"
		       " wrongdoers who sought to capture the milk supply for themselves.\nWhat a load of crap.\n"
		       "He just killed Charlotte. You shouldn't have to listen to his excuses.\nYou stumble over"
		       " to Charlotte's side, and clasp her hand in your own... she's already dead.\n"
		       "You then turn to Johnny, and point the gun at him.\n");
		printf("\e[1;34mEnd it all, here and now?\n(1) Yes\n(2) No\n");
		choice = inp(1,1,2);

		if(choice == 1)
		{
			printf("You shoot Johnny. A demon like him didn't deserve to live anymore."
			       " And you... well, you didn't care anymore.\nYou're not part of this world"
			       " anyways, and with both your friends gone, you had no reason to stay.\n"
			       "\e[1;31mYou exit through the scarlet door.\n");
      fprintf(f, "End it all, here and now\n"
             "You shoot Johnny. A demon like him didn't deserve to live anymore."
			       " And you... well, you didn't care anymore.\nYou're not part of this world"
			       " anyways, and with both your friends gone, you had no reason to stay.\n"
			       "\e[1;31mYou exit through the scarlet door.\n");
		}

		else
		{
			printf("You just can't bring yourself to pull the trigger. You've been through enough"
			       "today.\nYou disconnect yourself from this reality. It's all fake, after all."
			       "This alternate world, one where milk drives people to kill each other, this "
			       "world is not one in which you ever belonged.\nIt may as well all be a dream."
			       "\n\nYou and Johnny go grab a grilled cheese at a local sandwich shop. The "
			       "flavour is good, but it lacks a special something.\n\e[1;33mYou know, this "
			       "grilled cheese has nothing on your own special recipe. I wish you'd tell me"
			       "it one of these days.\n\e[0mYou spend the next four month living the life of"
			       " a gangster. It's miserable. Johnny has elevated himself to an Al Capone level"
			       " figure.\nHis influence is so strong that the dairy company won't even dare to "
			       "fire him for the abuse of their product.\nBut in the end, he always supported you."
			       "It felt in every way a contradiction.\nAll were expendable to Johnny when it came"
			       " to milk, and yet the connection he formed with you and his new gang of goons felt"
			       " genuine.\nBut today was the day you strike back. You'll avenge Charlotte and "
			       "acquire Johnny's milk supply,\ndestroy the empire he built and erect yourself "
			       "a new throne upon the ashes.\nNo longer will you kill for this man.\nNo longer"
			       " will you suffer for this man.\nNo longer will you live for this man.\nYou will"
			       " be free, and you will be the Milken One.\n\nJohny leads you to the new milk tank"
			       " he'd acquired. You play along like usual, offering strategy for effective "
			       "distribution of the product.\nThen you point your gun at his back. You have"
			       " one chance at this. It's time to take your shot.\n");
			fprintf(f, "You just can't bring yourself to pull the trigger. You've been through enough"
			       "today.\nYou disconnect yourself from this reality. It's all fake, after all."
			       "This alternate world, one where milk drives people to kill each other, this "
			       "world is not one in which you ever belonged.\nIt may as well all be a dream."
			       "\n\nYou and Johnny go grab a grilled cheese at a local sandwich shop. The "
			       "flavour is good, but it lacks a special something.\n\e[1;33mYou know, this "
			       "grilled cheese has nothing on your own special recipe. I wish you'd tell me"
			       "it one of these days.\n\e[0mYou spend the next four month living the life of"
			       " a gangster. It's miserable. Johnny has elevated himself to an Al Capone level"
			       " figure.\nHis influence is so strong that the dairy company won't even dare to "
			       "fire him for the abuse of their product.\nBut in the end, he always supported you."
			       "It felt in every way a contradiction.\nAll were expendable to Johnny when it came"
			       " to milk, and yet the connection he formed with you and his new gang of goons felt"
			       " genuine.\nBut today was the day you strike back. You'll avenge Charlotte and "
			       "acquire Johnny's milk supply,\ndestroy the empire he built and erect yourself "
			       "a new throne upon the ashes.\nNo longer will you kill for this man.\nNo longer"
			       " will you suffer for this man.\nNo longer will you live for this man.\nYou will"
			       " be free, and you will be the Milken One.\n\nJohny leads you to the new milk tank"
			       " he'd acquired. You play along like usual, offering strategy for effective "
			       "distribution of the product.\nThen you point your gun at his back. You have"
			       " one chance at this. It's time to take your shot.\n");
			printf("Kill Johnny?\n(1) Yes\n(2) Yes\n(3) Yes\n");
			choice = inp(1,2,3);
			if(choice==(rand()%3+1))
			{
				printf("The gun jams. Johnny whips around and blows you to bits.\n\n");
        fprintf(f, "The gun jams. Johnny whips around and blows you to bits.\n\n");
			}
			else
			{
				printf("You genuinely pop Johnny with your shot and he dies instantly. However, as you"
				       " bask in your self-satisfaction, the milk silo bursts open.\nDamn that Johnny!"
				       " He had rigged the entire building bofore bringing you here. Now you were going"
				       " to die a painful death, drowned in scalding milk.\nThe one thing you sought, now"
				       " presented to you in abundance...\n\e[1;31mand yet, you exit this world before you "
				       "may partake.\n\n\e[0m");
        fprintf(f, "You genuinely pop Johnny with your shot and he dies instantly. However, as you"
				       " bask in your self-satisfaction, the milk silo bursts open.\nDamn that Johnny!"
				       " He had rigged the entire building bofore bringing you here. Now you were going"
				       " to die a painful death, drowned in scalding milk.\nThe one thing you sought, now"
				       " presented to you in abundance...\n\e[1;31mand yet, you exit this world before you "
				       "may partake.\n\n\e[0m");
			}
		}

		mem++;
	}


//Second time looping through this route. Can save Charlotte if have umbrella. Can't save Johnny.

	else if(mem==1)
	{
		printf("\nScattered images flash through your mind. The scent of grilled cheese, "
		       "the barrel of a gun fixed upon a pleading soul,\nthe heavy downpour of"
		       " rain on a moonlit night, and... Johnny, his eyes glazed over.\nWith that"
		       " last vision, you spring up from your bed and run over to Johnny's room."
		       " Charlotte stumbles, taken aback by your panicked frenzy.\n You shout out "
		       "Johnny's name in desperation, praying that all you've seen had merely been"
		       " a dream.\nDamn it! Why won't he answer the door?\n"
		       "\e[1;33mSo you've finally woken, and in such a riled state too.\n"
		       "\e[0mJohnny calls out to you from behind, and lays a gentle hand upon your "
		       "shoulder.\nThe hand of a dead man.\nA man you once called friend.\nA man you "
		       "loved.\nA man you loathed.\nConfusion besets your mind as you struggle with your"
		       " emotions. You grow tense, fists clenched, anger boiling within.\nThis man..."
		       " killed Charlotte. Perhaps you could change that.\n");
		fprintf(f, "\nScattered images flash through your mind. The scent of grilled cheese, "
		       "the barrel of a gun fixed upon a pleading soul,\nthe heavy downpour of"
		       " rain on a moonlit night, and... Johnny, his eyes glazed over.\nWith that"
		       " last vision, you spring up from your bed and run over to Johnny's room."
		       " Charlotte stumbles, taken aback by your panicked frenzy.\n You shout out "
		       "Johnny's name in desperation, praying that all you've seen had merely been"
		       " a dream.\nDamn it! Why won't he answer the door?\n"
		       "\e[1;33mSo you've finally woken, and in such a riled state too.\n"
		       "\e[0mJohnny calls out to you from behind, and lays a gentle hand upon your "
		       "shoulder.\nThe hand of a dead man.\nA man you once called friend.\nA man you "
		       "loved.\nA man you loathed.\nConfusion besets your mind as you struggle with your"
		       " emotions. You grow tense, fists clenched, anger boiling within.\nThis man..."
		       " killed Charlotte. Perhaps you could change that.\n");
		printf("\e[1;34mKill Johnny?\n(1)no\n(2)yes\e[0m\n");
		choice=inp(1,1,2);

		//killing Johnny will only work if you have Empty Bottle

		if (choice==2)
		{
			printf("You leap at Johnny, catching him off-guard. Fury fuels your fists as "
			       "you pummel him. The ferocity of your blows leaves hardly any chance for"
			       " Johnny to counte.r\n"
			       "\e[1;33mWhat the hell are you do---!\n"
			       "\e[0mYou sock him right in the mouth, cutting him short. This \"man\" had"
			       "no right to speak. The man who offered his hand, only to drag you straight "
			       "into the depths hell. Killing him would be a mercy to the world.\n"
			       "\e[1;33mDamn you! You're really trying to kill me!"
			       "\e[0mJohnny finally manages to push you away. You stumble onto the floor, "
			       "the roles reversed. His right arm pins you to the ground as he reaches "
			       "for his pocket with the left. Panick strikes as Johnny unveils the pocket "
			       "knife within.\n"
			       "\e[1;33mPlease... don't make me do this!\n"
			       "\e[0mJohnny hesitates, arm poised to strike.\n"
			       "\e[1;33mWe've been like brothers all this time! Just tell me what's gotten"
			       "into you! Why are you doing this? You're confused from the accident. You've"
			       " been out cold for three whole days now. Just calm down, we'll talk through it.\n");
			fprintf(f, "You leap at Johnny, catching him off-guard. Fury fuels your fists as "
			       "you pummel him. The ferocity of your blows leaves hardly any chance for"
			       " Johnny to counte.r\n"
			       "\e[1;33mWhat the hell are you do---!\n"
			       "\e[0mYou sock him right in the mouth, cutting him short. This \"man\" had"
			       "no right to speak. The man who offered his hand, only to drag you straight "
			       "into the depths hell. Killing him would be a mercy to the world.\n"
			       "\e[1;33mDamn you! You're really trying to kill me!"
			       "\e[0mJohnny finally manages to push you away. You stumble onto the floor, "
			       "the roles reversed. His right arm pins you to the ground as he reaches "
			       "for his pocket with the left. Panick strikes as Johnny unveils the pocket "
			       "knife within.\n"
			       "\e[1;33mPlease... don't make me do this!\n"
			       "\e[0mJohnny hesitates, arm poised to strike.\n"
			       "\e[1;33mWe've been like brothers all this time! Just tell me what's gotten"
			       "into you! Why are you doing this? You're confused from the accident. You've"
			       " been out cold for three whole days now. Just calm down, we'll talk through it.\n");
			printf("\e[1;34m(1) Stop struggling\n(2) Keep fighting back\n");
			choice = inp(1,1,2);

			//continue fighting
			if (choice == 2)
			{
				printf("\e[0mYou hesitate for a brief moment, but then your rage swells up again. You ram your"
				       " head straight up into Johnny's chin, causing him to fall backwards. The both of "
				       "recover to your feet. You lunge before he has a chance to prepare, reaching for his"
				       " knife. You were too slow.\nJohnny thrusts the knife into you.\n");
        fprintf(f, "Continue fighting\n"
               "\e[0mYou hesitate for a brief moment, but then your rage swells up again. You ram your"
				       " head straight up into Johnny's chin, causing him to fall backwards. The both of "
				       "recover to your feet. You lunge before he has a chance to prepare, reaching for his"
				       " knife. You were too slow.\nJohnny thrusts the knife into you.\n");

				//if you have the empty bottle
				if (inv -> EB == 1)
				{
					printf("...\n....\n.....\nThough the impact itself left you winded, you feel no pain.\n...\n"
					       "You reach down to where you were stabbed to find the empty bottle you picked up had "
					       "shielded you... So this thing had it's uses, after all!\nYour relief lasts only a moment\n"
					       " as you notice Johnny ready another strike. You won't get lucky again... you brace"
					       "yourself for the impact...\n...\nYou hear an earsplitting crack. Johnny's head erupts "
					       "into a burst of scarlet. He falls limp beside you, knife slipping loose from his grip.\n"
					       "You stumble backwards in shock. Charlotte catches you from behind...\nShe's holding a "
					       "gun.\nAs your ears recover, you hear violently sobbing.\n"
					       "\e[1;33mI'm sorry... I...\n"
					       "\e[0mShe breaks down into incoherent rambling and slumps down to the floor. You kneel "
					       "beside her. It wasn't supposed to go like this. You had let your emotions overcome you."
					       " You abandoned reason. Saving Charlotte like this had only flung her life into chaos."
					       " Would she ever know peace, having killed one of her closest friends?\n"
					       "\e[1;33mWill you stay with me?\n"
					       "\e[0mHer voice is frail. She's trying to hold on to the one piece of her life that"
					       " has yet to be destroyed. The very piece responsible for throwing it into disarray,"
					       " but she has nothing else to turn to.\nYou are consumed by guilt and self-hatred.\n"
					       "In truth, you never wanted any of this to happen.\n For Christ's sake, all you ever"
					       " wanted was to get some milk! You let yourself get too attached to this other reality."
					       "\nYou tried to lead a false life in a world you didn't belong in. All of this was"
					       " meaningless.\n"
					       "\e[1;33m...Please\n"
					       "\e[0mHer whispered plea only drives you further down the pit of despair.\nThough your "
					       "may not be tied to this world, you've irreperably damaged the lives of those within it.\n");
         fprintf(f, "...\n....\n.....\nThough the impact itself left you winded, you feel no pain.\n...\n"
					       "You reach down to where you were stabbed to find the empty bottle you picked up had "
					       "shielded you... So this thing had it's uses, after all!\nYour relief lasts only a moment\n"
					       " as you notice Johnny ready another strike. You won't get lucky again... you brace"
					       "yourself for the impact...\n...\nYou hear an earsplitting crack. Johnny's head erupts "
					       "into a burst of scarlet. He falls limp beside you, knife slipping loose from his grip.\n"
					       "You stumble backwards in shock. Charlotte catches you from behind...\nShe's holding a "
					       "gun.\nAs your ears recover, you hear violently sobbing.\n"
					       "\e[1;33mI'm sorry... I...\n"
					       "\e[0mShe breaks down into incoherent rambling and slumps down to the floor. You kneel "
					       "beside her. It wasn't supposed to go like this. You had let your emotions overcome you."
					       " You abandoned reason. Saving Charlotte like this had only flung her life into chaos."
					       " Would she ever know peace, having killed one of her closest friends?\n"
					       "\e[1;33mWill you stay with me?\n"
					       "\e[0mHer voice is frail. She's trying to hold on to the one piece of her life that"
					       " has yet to be destroyed. The very piece responsible for throwing it into disarray,"
					       " but she has nothing else to turn to.\nYou are consumed by guilt and self-hatred.\n"
					       "In truth, you never wanted any of this to happen.\n For Christ's sake, all you ever"
					       " wanted was to get some milk! You let yourself get too attached to this other reality."
					       "\nYou tried to lead a false life in a world you didn't belong in. All of this was"
					       " meaningless.\n"
					       "\e[1;33m...Please\n"
					       "\e[0mHer whispered plea only drives you further down the pit of despair.\nThough your "
					       "may not be tied to this world, you've irreperably damaged the lives of those within it.\n");
            
					printf("\e[1;34mStay with Charlotte?\n(1) Yes\n(2) No\n");
					choice = inp(1,1,2);

					//very brief, possible to buy chicken (though you'll need pre-existing funds)
					if (choice == 1)
					{
						printf("You to take responsibility for your actions. The milk can wait.\n\n"
						       "You spend the next three years living with Charlotte. By now,"
						       " you've both fully recovered from the whole ordeal with Johnny.\nIt "
						       "was a lot for Charlotte to come to terms with. She certainly would"
						       " never have recovered had she been alone.\nBut it was almost time to"
						       " say goodbye. Linger here any longer, and you very well may forget"
						       " to return to your own world. You can't allow that to happen, even if"
						       " living the rest of your life with Charlotte has its own appeal.\n"
						       "But before you go, there was one last to do.\n");
            fprintf(f, "You to take responsibility for your actions. The milk can wait.\n\n"
						       "You spend the next three years living with Charlotte. By now,"
						       " you've both fully recovered from the whole ordeal with Johnny.\nIt "
						       "was a lot for Charlotte to come to terms with. She certainly would"
						       " never have recovered had she been alone.\nBut it was almost time to"
						       " say goodbye. Linger here any longer, and you very well may forget"
						       " to return to your own world. You can't allow that to happen, even if"
						       " living the rest of your life with Charlotte has its own appeal.\n"
						       "But before you go, there was one last to do.\n");

						festival(money, inv, f);

						printf("At the festivals end, you bid her a final farewell. You've explained the "
						       "situation to her. She's accepted it, but you still feel guilty about leaving"
						       " her alone like this.\nIt's time to return to your old life. You may never"
						       " see Charlotte again, but that's simply the way things have to be.\n"
						       "\nAnd so, you exit this world without looking back.\n");
            fprintf(f, "At the festivals end, you bid her a final farewell. You've explained the "
						       "situation to her. She's accepted it, but you still feel guilty about leaving"
						       " her alone like this.\nIt's time to return to your old life. You may never"
						       " see Charlotte again, but that's simply the way things have to be.\n"
						       "\nAnd so, you exit this world without looking back.\n");

						mem++;
            fclose(f);
						return;
					}
					else
					{
						printf("You can't deal with it anymore. In order to escape back to your own world,"
						       " you take the gun from Charlotte's hand and point it at your own head.\n"
						       "Charlotte's eyes widen.\e[1;31m The last thing you hear is her anguished scream.\n"
						       "\e[0mYou're back in your own world. You try to repress that final image "
						       "of Charlotte crying out, but it's been permanently engraved in your mind.\n"
						       "Regardless, it's time to move on. What's done is done...\n");
           fprintf(f, "You can't deal with it anymore. In order to escape back to your own world,"
						       " you take the gun from Charlotte's hand and point it at your own head.\n"
						       "Charlotte's eyes widen.\e[1;31m The last thing you hear is her anguished scream.\n"
						       "\e[0mYou're back in your own world. You try to repress that final image "
						       "of Charlotte crying out, but it's been permanently engraved in your mind.\n"
						       "Regardless, it's time to move on. What's done is done...\n");

						mem++;
            fclose(f);
						return;
					}
				}

				else
				{
					printf("A sharp pain erupts spikes through your abdomen. The breath is forced out of your lungs. "
					       ");While you're still dazed from the first stab, Johnny pulls back his hand and thrusts "
					       "the knife into you once, twice, thrice more. You splatter blood on the floor with "
					       "a cough, and as you try to regain your breathe you feel more gurgling in your throat.\n"
					       "You hear a sharp cry echo across the hall, followed by an explosive crack.\n"
					       "Johnny falls limp.\nYou stare in disbelief, momentarily forgetting about the pain."
					       " Then, weakly, you begin to collapse backward onto the floor as well, but someone"
					       " catches you from behind.\nIt's Charlotte. Sobbing. A gun in her hand.\n"
					       "\e[1;33mWhy...? Why did all of this just happen? Why!\n"
					       "\e[0mYou are overcome with guilt and self-hatred. You wanted to protect her, but "
					       "you had acted irrationally. This was the result. You, bleeding out on the floor.\n"
					       " Charlotte, made to kill one of her closest friends while watching the other die"
					       "before her.\nNone of this should have happened.\nYour vision begins to blur.\n"
					       " To your dismay, the last thing you see is Charlotte fixing the gun's barrel"
					       " upon herself...\n\e[1;31m...and pulling the trigger...\e[0m\n");
          fprintf(f, "A sharp pain erupts spikes through your abdomen. The breath is forced out of your lungs. "
					       ");While you're still dazed from the first stab, Johnny pulls back his hand and thrusts "
					       "the knife into you once, twice, thrice more. You splatter blood on the floor with "
					       "a cough, and as you try to regain your breathe you feel more gurgling in your throat.\n"
					       "You hear a sharp cry echo across the hall, followed by an explosive crack.\n"
					       "Johnny falls limp.\nYou stare in disbelief, momentarily forgetting about the pain."
					       " Then, weakly, you begin to collapse backward onto the floor as well, but someone"
					       " catches you from behind.\nIt's Charlotte. Sobbing. A gun in her hand.\n"
					       "\e[1;33mWhy...? Why did all of this just happen? Why!\n"
					       "\e[0mYou are overcome with guilt and self-hatred. You wanted to protect her, but "
					       "you had acted irrationally. This was the result. You, bleeding out on the floor.\n"
					       " Charlotte, made to kill one of her closest friends while watching the other die"
					       "before her.\nNone of this should have happened.\nYour vision begins to blur.\n"
					       " To your dismay, the last thing you see is Charlotte fixing the gun's barrel"
					       " upon herself...\n\e[1;31m...and pulling the trigger...\e[0m\n");

					mem++;
          fclose(f);
					return;
				}

			}
		}

		//if choose not to kill Johnny
		else
		{
			printf("You calm yourself. You've returned to a time before he ran your life to ruin.\n"
			       "There is no need to be rash. You can fix things. You can save Charlotte. Maybe"
			       " even Johnny, should you divert him from the path of violence.\n"
			       "\e[1;33mAre you finally back to normal? I suppose being in that coma really "
			       "did a number on your mind.\n"
			       "\e[0mYou nod slowly. You still don't fully trust him, but you need to focus on"
			       " the present. Not the past... er the future? The past future? The future past?\n"
			       "For some inexplicable reason, the mental image of Hugh Jackman flashes through your mind"
			       ".\nCharlotte finally meets the two of you in the hall.\n"
			       "\e[1;33mJeez, the way you flew out of the room! What got into you?\n"
			       "\e[0mJohnny pipes in\n\e[1;33mI thought he'd gone mad for a moment, but "
			       "he seems to be back to normal. We're glad to have you back, Madman.\n"
			       "\e[0mThe rest of the day plays out almost exactly as it had the first time.\n"
			       "Johnny has taken it upon himself to continue calling you \"Madman\", "
			       "understandably so.\nWith a situation like this, you can't help but wonder if you "
			       "really have just lost it. Perhaps this was all some random delusion. Maybe you just"
			       " need some milk.\nOh right. For whatever reason, drinking milk is considered taboo"
			       " in this world.\nGuess there's no other choice but to resolve your issues here, and"
			       " return once more to your own world so you can finally sip upon your white delight.\n"
			       "And so came the day of your first job. Just like last time, it was a basic fetch quest."
			       "\nCharlotte is once more accompanying you, but you don't need her guidance this time.\n"
			       "\e[1;33mHmmm. I was supposed to be showing you around town today, but it seems you "
			       "remember the way just fine. I suppose the amnesia didn't alter your sense of direction.\n"
			       "\e[0mShe playfully grabs hold of your arm and throws you a mischevious glance.\n\e[1;33m"
			       "In any case, we've now got a ton of free time on our hands... shall we go on a date?\n"
			       "\e[0mHer remark leaves you stunned. You'd forgotten about her habit of teasing you "
			       "like this.\nShe erupts into laughter.\n"
			       "\e[1;33mMy my, you're as bashful as always, my dear.\n"
			       "\e[0mIt would seem she's taken to calling you \"dear\" now.\nFirst Johnny calling you "
			       "\"Madman\", now this... you're not quite sure that you agree with these nicknames.\n"
			       "\e[1;33mJokes aside, we really do have a whole lot of free time on our hands. What"
			       " should we do?\n");
			fprintf(f, "Stop Fighting\n"
             "You calm yourself. You've returned to a time before he ran your life to ruin.\n"
			       "There is no need to be rash. You can fix things. You can save Charlotte. Maybe"
			       " even Johnny, should you divert him from the path of violence.\n"
			       "\e[1;33mAre you finally back to normal? I suppose being in that coma really "
			       "did a number on your mind.\n"
			       "\e[0mYou nod slowly. You still don't fully trust him, but you need to focus on"
			       " the present. Not the past... er the future? The past future? The future past?\n"
			       "For some inexplicable reason, the mental image of Hugh Jackman flashes through your mind"
			       ".\nCharlotte finally meets the two of you in the hall.\n"
			       "\e[1;33mJeez, the way you flew out of the room! What got into you?\n"
			       "\e[0mJohnny pipes in\n\e[1;33mI thought he'd gone mad for a moment, but "
			       "he seems to be back to normal. We're glad to have you back, Madman.\n"
			       "\e[0mThe rest of the day plays out almost exactly as it had the first time.\n"
			       "Johnny has taken it upon himself to continue calling you \"Madman\", "
			       "understandably so.\nWith a situation like this, you can't help but wonder if you "
			       "really have just lost it. Perhaps this was all some random delusion. Maybe you just"
			       " need some milk.\nOh right. For whatever reason, drinking milk is considered taboo"
			       " in this world.\nGuess there's no other choice but to resolve your issues here, and"
			       " return once more to your own world so you can finally sip upon your white delight.\n"
			       "And so came the day of your first job. Just like last time, it was a basic fetch quest."
			       "\nCharlotte is once more accompanying you, but you don't need her guidance this time.\n"
			       "\e[1;33mHmmm. I was supposed to be showing you around town today, but it seems you "
			       "remember the way just fine. I suppose the amnesia didn't alter your sense of direction.\n"
			       "\e[0mShe playfully grabs hold of your arm and throws you a mischevious glance.\n\e[1;33m"
			       "In any case, we've now got a ton of free time on our hands... shall we go on a date?\n"
			       "\e[0mHer remark leaves you stunned. You'd forgotten about her habit of teasing you "
			       "like this.\nShe erupts into laughter.\n"
			       "\e[1;33mMy my, you're as bashful as always, my dear.\n"
			       "\e[0mIt would seem she's taken to calling you \"dear\" now.\nFirst Johnny calling you "
			       "\"Madman\", now this... you're not quite sure that you agree with these nicknames.\n"
			       "\e[1;33mJokes aside, we really do have a whole lot of free time on our hands. What"
			       " should we do?\n");
			printf("\e[1;34m(1) Picnic\n(2) Arcade\n(3) Amusement Park\n\e[0m");
			choice = inp(1,2,3);

			if (choice == 1)
			{
				printf("You stop by a local deli before heading to the park. You set up at a bench"
				       " beside the pond. A family of ducks swims nearby.\nThis place was truly "
				       "serene... and it was the very place Charlotte would die.\nThe colours of "
				       "the scene seemed to dull at that thought, the calm atmosphere replaced by"
				       " one of unease.\nWhat were you thinking, taking her here of all places?\n"
				       "\e[1;33mSay \"ahhhh\"\n"
				       "\e[0mYour brooding is interrupted by a poke on the side of your cheek. You turn"
				       " to find Charlotte holding a piece of bread up to your mouth, giggling.\nBefore "
				       "you could question her, she shoves it into your face. You attempt to free yourself"
				       " from her assault to no avail.\nUltimately, you give in and allow her to feed you"
				       " the bread.\nThe situation is rather embarrassing, but you're glad to spend these"
				       "  joyful days on things like this. The inferno would be upon them soon enough.\n");
        fprintf(f, "Picnic\n" 
               "You stop by a local deli before heading to the park. You set up at a bench"
				       " beside the pond. A family of ducks swims nearby.\nThis place was truly "
				       "serene... and it was the very place Charlotte would die.\nThe colours of "
				       "the scene seemed to dull at that thought, the calm atmosphere replaced by"
				       " one of unease.\nWhat were you thinking, taking her here of all places?\n"
				       "\e[1;33mSay \"ahhhh\"\n"
				       "\e[0mYour brooding is interrupted by a poke on the side of your cheek. You turn"
				       " to find Charlotte holding a piece of bread up to your mouth, giggling.\nBefore "
				       "you could question her, she shoves it into your face. You attempt to free yourself"
				       " from her assault to no avail.\nUltimately, you give in and allow her to feed you"
				       " the bread.\nThe situation is rather embarrassing, but you're glad to spend these"
				       "  joyful days on things like this. The inferno would be upon them soon enough.\n");
			}
			else if(choice == 2)
			{
				printf("The two of you visit the arcade. You hit up all the arcade staples: skii ball, "
				       "claw machines, photo booths, Dance Dance Revolution, shooting sims, Galaga...\n"
				       "Yeah I'll cut the list here, no reason to ramble on forever\nCharlotte cries out"
				       " in joy after winning one of the jackpots. You had no clue she was so good at "
				       "arcade games.\n");
        fprintf(f, "Arcade\n"
               "The two of you visit the arcade. You hit up all the arcade staples: skii ball, "
				       "claw machines, photo booths, Dance Dance Revolution, shooting sims, Galaga...\n"
				       "Yeah I'll cut the list here, no reason to ramble on forever\nCharlotte cries out"
				       " in joy after winning one of the jackpots. You had no clue she was so good at "
				       "arcade games.\n");
			}
			else
			{
				printf("The two of you go to the amusement park. On the ferris wheel, Charlotte remains "
				       "tense and grips the rail so tightly it might've bent.\nYou get up to move beside"
				       " her, and she yelps at the cabin's slight shifting at your motion.\nThough "
				       "the height made her uncomfortable, she also seemed rather happy.\n");
        fprintf(f, "Amusment Park\n" 
               "The two of you go to the amusement park. On the ferris wheel, Charlotte remains "
				       "tense and grips the rail so tightly it might've bent.\nYou get up to move beside"
				       " her, and she yelps at the cabin's slight shifting at your motion.\nThough "
				       "the height made her uncomfortable, she also seemed rather happy.\n");
			}

			printf("\nJohnny greets the two of you upon your return. You hand him the package, "
			       "and he gives you your payment of $25.\n");
      fprintf(f, "\nJohnny greets the two of you upon your return. You hand him the package, "
			       "and he gives you your payment of $25.\n");
			*money += 25;

			printf("\nYou spend the next couple of days working like usual.\n");
			for(j=0; j<3; j++)
			{
				printf("\n\e[0mA new morning. You get dressed and go out to meet with Johnny\n");
				job(health, money, f);
        printf("\n");
			}
			printf("\e[0mA feeling of dread fills your stomach. The day had come where Johnny boasted about his"
			       " new promotion.\nThe position of power that he'd inevitably abuse to become a dairy "
			       "dealer.\nYou have to act soon if you hope to save Charlotte.\n");
      fprintf(f, "\e[0mA feeling of dread fills your stomach. The day had come where Johnny boasted about his"
			       " new promotion.\nThe position of power that he'd inevitably abuse to become a dairy "
			       "dealer.\nYou have to act soon if you hope to save Charlotte.\n");

			festival(money, inv, f);
			printf("Now you turn to Charlotte, expression grim. You tell her that Johnny has likely"
			       " entered the field of dark dairy dealings.\nThe best option for the both of you is"
			       " to run away now, and leave Johnny to his own fate.\nShe remains silent for a while."
			       "\nThen, she shakes her head.\n\e[1;33mI had hoped you wouldn't get dragged into this."
			       "\nJohnny's always been one to fall into shady dealings, but I never truly believed"
			       " he'd go so far as to become a dairy dealer...\nHe gave me the address of the dairy"
			       " plant's milk supply, so I ignored my doubts and decided to trust that he'd be "
			       " responsible. But it would seem he betrayed my trust, after all.\e[0m\nThe two of you "
			       "plan to depart early before the mysterious gang came to kidnap Charlotte.\n"
			       "They struck before dawn last time, so you'll leave right at midnight.\n"
             "\nMidnight arrives. It's raining. You creak the front door to the penthouse open and"
			       " peak outside.\nAcross the street stood mysterious robed figures, watching the "
			       "penthouse intently.\nCrap! They were already here! You need to try and sneak by them.\n");
      fprintf(f, "Now you turn to Charlotte, expression grim. You tell her that Johnny has likely"
			       " entered the field of dark dairy dealings.\nThe best option for the both of you is"
			       " to run away now, and leave Johnny to his own fate.\nShe remains silent for a while."
			       "\nThen, she shakes her head.\n\e[1;33mI had hoped you wouldn't get dragged into this."
			       "\nJohnny's always been one to fall into shady dealings, but I never truly believed"
			       " he'd go so far as to become a dairy dealer...\nHe gave me the address of the dairy"
			       " plant's milk supply, so I ignored my doubts and decided to trust that he'd be "
			       " responsible. But it would seem he betrayed my trust, after all.\e[0m\nThe two of you "
			       "plan to depart early before the mysterious gang came to kidnap Charlotte.\n"
			       "They struck before dawn last time, so you'll leave right at midnight.\n"
             "\nMidnight arrives. It's raining. You creak the front door to the penthouse open and"
			       " peak outside.\nAcross the street stood mysterious robed figures, watching the "
			       "penthouse intently.\nCrap! They were already here! You need to try and sneak by them.\n");

			if(inv -> UM == 1)
			{
				printf("You remember the umbrella you grabbed on one of your previous adventures.\n"
				       "You step outside, letting the spies see you. Then you open it up and hold it"
				       " a very precise angle, taking care that your posture remained natural while"
				       " still calculated.\nYou beckon Charlotte forth, and instruct her to stay under"
				       " the cover of the umbrella. You swiftly make your escape.\n\nA week later, you"
				       " see a news report covering Johnny's unfortunate demise at the hands of the "
				       "dairy dealers.\nThat fool. You almost pity him. He didn't have to go down that "
				       "road.\nHowever, having seen Charlotte to safety, you decide that you can now"
				       " depart from this world.\n");
        fprintf(f, "You remember the umbrella you grabbed on one of your previous adventures.\n"
				       "You step outside, letting the spies see you. Then you open it up and hold it"
				       " a very precise angle, taking care that your posture remained natural while"
				       " still calculated.\nYou beckon Charlotte forth, and instruct her to stay under"
				       " the cover of the umbrella. You swiftly make your escape.\n\nA week later, you"
				       " see a news report covering Johnny's unfortunate demise at the hands of the "
				       "dairy dealers.\nThat fool. You almost pity him. He didn't have to go down that "
				       "road.\nHowever, having seen Charlotte to safety, you decide that you can now"
				       " depart from this world.\n");
			}
			else
			{
				printf("You attempt to create a distraction by sprinting towards that spies, allowing"
				       " Charlotte to slip away unnoticed... Or so you thought.\nYou got shot in the "
				       "leg and collapsed to the ground. Charlotte cried out to you out of concern,"
				       " blowing her cover.\nYou struggle back onto your feet"
				       " and engage in a fistfight with the spies, but they just blow your brains out."
				       "\nYou depart from this world knowing only that you failed miserably.\n");
        fprintf(f, "You attempt to create a distraction by sprinting towards that spies, allowing"
				       " Charlotte to slip away unnoticed... Or so you thought.\nYou got shot in the "
				       "leg and collapsed to the ground. Charlotte cried out to you out of concern,"
				       " blowing her cover.\nYou struggle back onto your feet"
				       " and engage in a fistfight with the spies, but they just blow your brains out."
				       "\nYou depart from this world knowing only that you failed miserably.\n");
			}

			mem++;
		}
	}


//third loop - can save Johnny with grilled cheese.
	else
	{
		printf("Images flash through your mind once more. Scenes of death. Of sorrow. Of pain.\n"
		       "That's right. You've been through this before. A wicked cycle of torment."
		       " The complete inverse of the temporal experience:\nto know one's future whilst "
		       "oblivious to an unseen past. A life not lived, but to be lived. What a joke.\n"
		       "\e[1;33mMy, this is a rare sight to behold! I've never seen such an exasperated expression\n"
		       "\e[0mYou lay it to her bare. Johnny is going run your lives to ruin. All three of your lives "
		       "could be at stake...\nWell, perhaps not your own. After all, you don't even live in this world.\n"
		       "Charlotte's eyes widen in shock. Now she, too, is wearing an expression of total exasperation.\n"
		       "\e[1;33mI've no clue whether I'm being played for a fool or if you've completely lost it.\n"
		       "\e[0mYou tell her you've been knocked out for three days, information you could not have already "
		       "known otherwise.\nCharlotte, however, is not yet fully convinced.\n"
		       "\e[1;33mThough I do wonder how you could know that without me having told you, it all just seems"
		       " too fantastical.\nAnd... well...\n"
		       "\e[0mHer gaze turns downward, her face molding to the shape of a frown\n"
		       "\e[1;33mIs it true? That you really aren't from this world? That the past we shared"
		       " never truly existed?\nAm I... just a stranger to you?\nI don't want to believe that.\n"
		       "\e[0mHer hand faintly squeezes your own, as if she were trying to cling to the \"you\" "
		       "that existed in her memory.\nShe looks up at you. You turn your head away, unable to bare"
		       " her gaze. Those pleading eyes.\nIt's true. The past you shared with Charlotte wasn't  "
		       "real. However, the futures you lived had been real. You weren't exactly strangers.\n"
		       "You squeeze her hand in return, and tell her this.\n"
		       "\e[1;33mI might've been better off had you not told me this... but I'm glad. Glad that "
		       "I still mean something to you...\n"
		       "\e[0mHer face flushes red. At that moment, the door opens and Johnny enters the your room.\n"
		       "You and Charlotte both tense up.\nThis man was fated to bring you misery.\nThis man was fated"
		       " to bring you joy.\nA friend.\nAn enemy.\nA man you loathed.\nA man you loved.\nYou take a"
		       " deep breathe. All of this has yet to happen. Perhaps, if you play your cards right, it'll "
		       "never happen again.\nAs of right now, Johnny was still a friend. So you forget the demon "
		       "of the future, and smile as he walks up to your side.\nHe glances down at your and Charlotte's "
		       "hands, still clasped together, and chuckles.\n"
		       "\e[1;33mYou wake up after being in a coma for three whole days just to flirt with our maid?\n"
		       "\e[0mYou snap back with a witty retort.\nFor now, you'll play along. At least until you can "
		       "find a time to confront Johnny and to turn him from the dark path.\nIt would seem that getting"
		       " that promotion is what turned him fully to the black milk market.\nIf you can convince him not"
		       " to accept it, you can save his mind from being corrupted by the allure of wealth.\nThe next few"
		       " days proceed much the same as they did the first time around. You and Charlotte run around town,"
		       " and you do the odd job here and there.\n");
     fprintf(f, "Images flash through your mind once more. Scenes of death. Of sorrow. Of pain.\n"
		       "That's right. You've been through this before. A wicked cycle of torment."
		       " The complete inverse of the temporal experience:\nto know one's future whilst "
		       "oblivious to an unseen past. A life not lived, but to be lived. What a joke.\n"
		       "\e[1;33mMy, this is a rare sight to behold! I've never seen such an exasperated expression\n"
		       "\e[0mYou lay it to her bare. Johnny is going run your lives to ruin. All three of your lives "
		       "could be at stake...\nWell, perhaps not your own. After all, you don't even live in this world.\n"
		       "Charlotte's eyes widen in shock. Now she, too, is wearing an expression of total exasperation.\n"
		       "\e[1;33mI've no clue whether I'm being played for a fool or if you've completely lost it.\n"
		       "\e[0mYou tell her you've been knocked out for three days, information you could not have already "
		       "known otherwise.\nCharlotte, however, is not yet fully convinced.\n"
		       "\e[1;33mThough I do wonder how you could know that without me having told you, it all just seems"
		       " too fantastical.\nAnd... well...\n"
		       "\e[0mHer gaze turns downward, her face molding to the shape of a frown\n"
		       "\e[1;33mIs it true? That you really aren't from this world? That the past we shared"
		       " never truly existed?\nAm I... just a stranger to you?\nI don't want to believe that.\n"
		       "\e[0mHer hand faintly squeezes your own, as if she were trying to cling to the \"you\" "
		       "that existed in her memory.\nShe looks up at you. You turn your head away, unable to bare"
		       " her gaze. Those pleading eyes.\nIt's true. The past you shared with Charlotte wasn't  "
		       "real. However, the futures you lived had been real. You weren't exactly strangers.\n"
		       "You squeeze her hand in return, and tell her this.\n"
		       "\e[1;33mI might've been better off had you not told me this... but I'm glad. Glad that "
		       "I still mean something to you...\n"
		       "\e[0mHer face flushes red. At that moment, the door opens and Johnny enters the your room.\n"
		       "You and Charlotte both tense up.\nThis man was fated to bring you misery.\nThis man was fated"
		       " to bring you joy.\nA friend.\nAn enemy.\nA man you loathed.\nA man you loved.\nYou take a"
		       " deep breathe. All of this has yet to happen. Perhaps, if you play your cards right, it'll "
		       "never happen again.\nAs of right now, Johnny was still a friend. So you forget the demon "
		       "of the future, and smile as he walks up to your side.\nHe glances down at your and Charlotte's "
		       "hands, still clasped together, and chuckles.\n"
		       "\e[1;33mYou wake up after being in a coma for three whole days just to flirt with our maid?\n"
		       "\e[0mYou snap back with a witty retort.\nFor now, you'll play along. At least until you can "
		       "find a time to confront Johnny and to turn him from the dark path.\nIt would seem that getting"
		       " that promotion is what turned him fully to the black milk market.\nIf you can convince him not"
		       " to accept it, you can save his mind from being corrupted by the allure of wealth.\nThe next few"
		       " days proceed much the same as they did the first time around. You and Charlotte run around town,"
		       " and you do the odd job here and there.\n");

		job(health, money, f;
		printf("Same routine for the next day.\n");
    fprintf(f, "Same routine for the next day.\n");
		job(health, money, f);
		printf("\n\nToday you go to work early so that you may confront Johnny later.\n");
    fprintf(f, "\n\nToday you go to work early so that you may confront Johnny later.\n");
		job(health, money, f);
		printf("\nYou meet with Johnny during his lunch break. You tell him you know about the cheese factory."
		       "About all the milk he manages there. About how he could abuse his position to smuggle milk"
		       "across the city.\n"
		       "\e[1;33mDid Charlotte tell you? I suppose it's only natural. You're like blood to me, you"
		       " had ought to find out about my job at some point.\n"
		       "\e[0mYou nod slowly. "
		       "You play at the idea some more. In fact, you throw his own idea back at him: \"isn't\n"
		       "that milk worth more than any person's life?\"\nHowever, Johnny remains cool.\n"
		       "\e[1;33mIt's true. That milk is a golden liquor. You can't place any price upon it.\n"
		       "\e[0mHis response was too matter-of-fact, you couldn't get a read on his intentions\n"
		       "At his present state, would he wager another's life to preserve his claim on the milk?\n"
		       "It seems that you won't get anywhere tonight. Best to hit the hay and prepare for your"
		       " job tomorrow.\nYou'll figure out how to correct Johnny's future, but it'll require patience.\n");
    fprintf(f, "\nYou meet with Johnny during his lunch break. You tell him you know about the cheese factory."
		       "About all the milk he manages there. About how he could abuse his position to smuggle milk"
		       "across the city.\n"
		       "\e[1;33mDid Charlotte tell you? I suppose it's only natural. You're like blood to me, you"
		       " had ought to find out about my job at some point.\n"
		       "\e[0mYou nod slowly. "
		       "You play at the idea some more. In fact, you throw his own idea back at him: \"isn't\n"
		       "that milk worth more than any person's life?\"\nHowever, Johnny remains cool.\n"
		       "\e[1;33mIt's true. That milk is a golden liquor. You can't place any price upon it.\n"
		       "\e[0mHis response was too matter-of-fact, you couldn't get a read on his intentions\n"
		       "At his present state, would he wager another's life to preserve his claim on the milk?\n"
		       "It seems that you won't get anywhere tonight. Best to hit the hay and prepare for your"
		       " job tomorrow.\nYou'll figure out how to correct Johnny's future, but it'll require patience.\n");
		job(health, money, f);
		printf("\nAfter work, Charlotte approaches you. The two of you have been discussing potential strategies"
		       " for changing Johnny's path through the future.\nYour new plan hinges upon Sandwich Sunday."
		       "The first time you woke up here, Johnny mentioned how deligthful your grilled cheese sandwiches"
		       " were.\nPerhaps the joy of cheese will ignite a passion for protecting the dairy arts, as "
		       "opposed to abusing it for his own personal gain.\n");
    fprintf(f, "\nAfter work, Charlotte approaches you. The two of you have been discussing potential strategies"
		       " for changing Johnny's path through the future.\nYour new plan hinges upon Sandwich Sunday."
		       "The first time you woke up here, Johnny mentioned how deligthful your grilled cheese sandwiches"
		       " were.\nPerhaps the joy of cheese will ignite a passion for protecting the dairy arts, as "
		       "opposed to abusing it for his own personal gain.\n");


		//if you have grilled cheese, you can save Johnny
		if (inv -> GC == 1)
		{
			printf("\nYou hand Charlotte the the grilled cheese you found on one of your previous adventures.\n"
			       "The two of you will deconstruct the sandwich to determine it's exact composition, then"
			       " present Johnny with the recipe.\nYou both gear up with lab coats and goggles before "
			       "running a series of intensive chemical tests.\nYou won't see the results for another 24 "
			       "hours, so the both of you just sit tight and wait until then.\nThat night, Johnny came home "
			       "boasting about his new promotion. If things proceed as they did before, tomorrow Johnny would"
			       " make a fatal mistake while they were away at the festival, and the very next morning Charlotte"
			       " would die. It was crucial to buy more time until the recipe was ready.\n\e[1;33mHey Johnny, why"
			       " not check out the festival tomorrow? The two of us are already going.\n\e[0mJohnny ponders the"
			       "idea. Though he had important work to do during the day, he could meet them there at night "
			       "if he rescheduled a few meetings.\nThat detail piques your interest. Might those meetings"
			       " be the ones that solidified his turn down the path of a Milk Gangster?\nIf so, you had to "
			       "hurry up and get him to cancel those plans.\n");
      fprintf(f, "\nYou hand Charlotte the the grilled cheese you found on one of your previous adventures.\n"
			       "The two of you will deconstruct the sandwich to determine it's exact composition, then"
			       " present Johnny with the recipe.\nYou both gear up with lab coats and goggles before "
			       "running a series of intensive chemical tests.\nYou won't see the results for another 24 "
			       "hours, so the both of you just sit tight and wait until then.\nThat night, Johnny came home "
			       "boasting about his new promotion. If things proceed as they did before, tomorrow Johnny would"
			       " make a fatal mistake while they were away at the festival, and the very next morning Charlotte"
			       " would die. It was crucial to buy more time until the recipe was ready.\n\e[1;33mHey Johnny, why"
			       " not check out the festival tomorrow? The two of us are already going.\n\e[0mJohnny ponders the"
			       "idea. Though he had important work to do during the day, he could meet them there at night "
			       "if he rescheduled a few meetings.\nThat detail piques your interest. Might those meetings"
			       " be the ones that solidified his turn down the path of a Milk Gangster?\nIf so, you had to "
			       "hurry up and get him to cancel those plans.\n");

			festival(money, inv, f);
			printf("\nThe sun sets in the distance, and the time for the fireworks display approaches.\n"
			       "Then you spot him, rushing over to meet the two of you.\n\e[1;33mForgive me, work"
			       " at the dairy plant ran a bit late!\n\e[0m\nYou suppress the urge to start cheering."
			       " Tomorrow, you'd finish preperations for the recipe, and serve him the grilled cheese"
			       " of legend that will turn him away forever from dark dairy dealings.\nBut for now,"
			       " the three of you enjoy the fireworks.\n\nThe next morning, you visit the laboratory."
			       "\nThe grilled cheese analysis was a success! You now could copy the recipe and present"
			       " it to Johnny.\nCharlotte had convinced him to stay home for Sandwich Sunday, promsing"
			       " a \"divine olfactory experience which could shatter the very barrier between heaven "
			       "and earth\".\nNow you serve him the grilled cheese. He nearly bursts into tears.\n"
			       "\e[1;33mYou've remembered the recipe! This greatness! This cheesiness! This is the true"
			       " essence of dairy! This is life itself!\n\e[0mYou hand him the printed recipe, and he vows"
			       " to dedicate his life to spreading the joys of dairy.\nHe brings about an era of peace,"
			       " the world united by the grilled cheese. Your work here done, you depart from this world.\n");
     fprintf(f, "\nThe sun sets in the distance, and the time for the fireworks display approaches.\n"
			       "Then you spot him, rushing over to meet the two of you.\n\e[1;33mForgive me, work"
			       " at the dairy plant ran a bit late!\n\e[0m\nYou suppress the urge to start cheering."
			       " Tomorrow, you'd finish preperations for the recipe, and serve him the grilled cheese"
			       " of legend that will turn him away forever from dark dairy dealings.\nBut for now,"
			       " the three of you enjoy the fireworks.\n\nThe next morning, you visit the laboratory."
			       "\nThe grilled cheese analysis was a success! You now could copy the recipe and present"
			       " it to Johnny.\nCharlotte had convinced him to stay home for Sandwich Sunday, promsing"
			       " a \"divine olfactory experience which could shatter the very barrier between heaven "
			       "and earth\".\nNow you serve him the grilled cheese. He nearly bursts into tears.\n"
			       "\e[1;33mYou've remembered the recipe! This greatness! This cheesiness! This is the true"
			       " essence of dairy! This is life itself!\n\e[0mYou hand him the printed recipe, and he vows"
			       " to dedicate his life to spreading the joys of dairy.\nHe brings about an era of peace,"
			       " the world united by the grilled cheese. Your work here done, you depart from this world.\n");
		}

		//if you can't save Johnny, you can still use umbrella to save Charlotte
		else if(inv -> UM == 1)
		{
			printf("\nDespite your efforts to come up with a grilled cheese recipe that might conquer"
			       " Johnny's terrible temptation to dairy dealing delight, neither you or Charlotte"
			       " succeed.\nBefore you know it, it's the night of Johnny's promotion. You know already"
			       " how to next two days will go.\n");
      fprintf(f, "\nDespite your efforts to come up with a grilled cheese recipe that might conquer"
			       " Johnny's terrible temptation to dairy dealing delight, neither you or Charlotte"
			       " succeed.\nBefore you know it, it's the night of Johnny's promotion. You know already"
			       " how to next two days will go.\n");
			festival(money, inv, f);
			printf("\nYou return home. The next morning, you are roused by Johnny. You don't ask any questions"
			       "\nHe hands you the gun, and you sock him in the face. Then you rush out to save Charlotte"
			       "\nYou find her in the park, just like the other time. She is surrounded by the four goons\n"
			       "You walk up to them so casually they don't even bat an eye. You wrap your arm around one's"
			       "neck, securing a choke-hold, and point a gun at him with your free hand.\nHe's now your "
			       "hostage.\nBut your plan was shortlived. In the dairy dealing business, everyone was expendable.\n"
			       "They shoot the hostage dead immediately, removing a liability, then steady their aim at you."
			       "\nJust then, you remember you still had that umbrella you picked up during another adventure.\n"
			       "You unfold it, obscuring yourself from their view. They open fire, shredding holes in the "
			       "umbrella's canvas.\nA bullet strikes your arm. Another grazes your cheek. But you are able "
			       "to succesfully close the distance.\nYou stab like prime John Wick with the umbrella and "
			       "completely penetrate the first goon.\nTwo to go.\nYou roll for cover, and engage in a shootout"
			       " with the other two.\nYou manage to get another one down, but the last guy nails you in the "
			       "shoulder.\nYou can't raise your shooting arm anymore. You become desperate. Then he lunges for"
			       " Charlotte, likely intending to use her as a human shield.\nYou leap out to defend her, but his"
			       " gun is already aimed at your position.\nYou've screwed up.\nJust then, Johnny leaps in front"
			       " of you, taking the bullet. You react quickly, firing at the final goon, then run to Johnny's"
			       " side.\nHe tries to tell you something, but he's gone before a single syllable could be "
			       "pronounced.\nWell... that kinda sucked. But at least Charlotte is alive.\nYou tie up the loose"
			       " ends and return to your own world, hopefully to never again repeat this dreadful cycle.\n");
      fprintf(f, "\nYou return home. The next morning, you are roused by Johnny. You don't ask any questions"
			       "\nHe hands you the gun, and you sock him in the face. Then you rush out to save Charlotte"
			       "\nYou find her in the park, just like the other time. She is surrounded by the four goons\n"
			       "You walk up to them so casually they don't even bat an eye. You wrap your arm around one's"
			       "neck, securing a choke-hold, and point a gun at him with your free hand.\nHe's now your "
			       "hostage.\nBut your plan was shortlived. In the dairy dealing business, everyone was expendable.\n"
			       "They shoot the hostage dead immediately, removing a liability, then steady their aim at you."
			       "\nJust then, you remember you still had that umbrella you picked up during another adventure.\n"
			       "You unfold it, obscuring yourself from their view. They open fire, shredding holes in the "
			       "umbrella's canvas.\nA bullet strikes your arm. Another grazes your cheek. But you are able "
			       "to succesfully close the distance.\nYou stab like prime John Wick with the umbrella and "
			       "completely penetrate the first goon.\nTwo to go.\nYou roll for cover, and engage in a shootout"
			       " with the other two.\nYou manage to get another one down, but the last guy nails you in the "
			       "shoulder.\nYou can't raise your shooting arm anymore. You become desperate. Then he lunges for"
			       " Charlotte, likely intending to use her as a human shield.\nYou leap out to defend her, but his"
			       " gun is already aimed at your position.\nYou've screwed up.\nJust then, Johnny leaps in front"
			       " of you, taking the bullet. You react quickly, firing at the final goon, then run to Johnny's"
			       " side.\nHe tries to tell you something, but he's gone before a single syllable could be "
			       "pronounced.\nWell... that kinda sucked. But at least Charlotte is alive.\nYou tie up the loose"
			       " ends and return to your own world, hopefully to never again repeat this dreadful cycle.\n");
		}

		else
		{
			printf("\nNo plan that you or Charlotte devise is succesful. Johnny becomes a tyrant. Charlotte"
			       " is executed.\nYou return to your own world, a failure. You pray you never return here"
			       " to relive this torturous cycle.\n");
      fprintf(f, "\nNo plan that you or Charlotte devise is succesful. Johnny becomes a tyrant. Charlotte"
			       " is executed.\nYou return to your own world, a failure. You pray you never return here"
			       " to relive this torturous cycle.\n");
		}
	}
  fclose(f);
	return;
}

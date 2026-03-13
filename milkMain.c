#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 



int routeCheck(int list[4]) 
{ 
	int i; 
	int open = 4; 
	for(i = 0, i < 4, i++) 
	{
		if(list[i] == 0) 
		{
			open -= 1; 
		} 
	} 
	
	if(open > 0) 
		return 1; 
	else 
		return 0; 
}


void onlyChance() 
{ 
	printf("While on your way out of the house you feel something heavy in your pocket. You reach into your pocket and find" 
					" a random rock just sitting there.\n\n[Annoying Rock] has been added to inventory.\n\n"); 
	//After inventory is settled, add the rock into array
	rock = 0; 
}


int main() 
{						   // hp money
  Player stats = {20, 100};
  srand(time(NULL); //to randomly select routes, I'd advise you use seperate one to select the scenes in your route
  int *health = &stats.hp;
  int *money = &stats.money; 
	int rock = 1;
	
	printf("One day, you wake up to find that all your milk was gone. You groan as you head off to the store to get "
          "more. While watching a random video your friend sent you, you walk into the street, not realizing the light\n"
          "had just turned green. You turn your head just in time to see a semi honk its horn at you before everything "
          "goes black.\n\nWhen you wake, you find yourself at home in your bed. What had happened? How did you get home? "
          "How did you survive? Are you dead!?!\nWho are you kidding, you don't care. All you know is that you still "
          "need to get milk. You throw yourself out of bed and begin your journey to the store to get a jug of milk.\n\n"); 
	
	printf("You start with 20 Hp and 100 dollars in your wallet as you leave your house./n/n"); 

	int selection_list[4] = {1, 1, 1, 1}; 
	int random_select; 
	char quit; 
	int list_full = 1;


	while(quit != y) //Need to make it so that when it selects a route it removes the option, so no duplicate runs
	{ 
		while(list_full == 1) 
		{
			random_select = rand()%4+1; //Also need to restore after end of loop
			if(selection_list[random_select-1] != 0) 
			{ 
				if(random_select == 1) 
				{ 
					//Dean's route is called 
					selection_list[0] = 0; 
					quit = quit(); 
					list_full = routeCheck(selection_list); 
				} 
				else if(random_select == 2) 
				{ 
					

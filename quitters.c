#include <stdio.h> 


char quit() 
{
	char q;
	printf("Should you continue or go home? (y/n) "); 
	scanf(" %c", &q);
	return q;
}

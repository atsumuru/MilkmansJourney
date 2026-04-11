/*****************************************************
*
*File: quitters
*Author: Esra Petty
*Purpose: One piece of a milky adventure (Final Project
*Version: 1.1 Apr 11, 2026
*
******************************************************/
#include <stdio.h> 


char quit() 
{
	char q;
	printf("Should you continue(y) or go home(n)? "); 
	scanf(" %c", &q);
	return q;
}

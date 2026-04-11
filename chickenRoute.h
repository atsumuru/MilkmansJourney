/*
File: chickenRoute.h
Author: Fred Washington
Purpose: Header file containing the functions from chickenRoute.c
Ver 1.0078 Apr 11, 2026
*/

#ifndef HEADER_FILENAME
#define HEADER_FILENAME

void clearInput();
int inp(int x, int y, int z);
void festival(int* m, INVENTORY* i, FILE* f);
int bet(int q);
void job(int* hp, int* money, FILE* f);
void chickenRoute(int* health, int* money, Inventory *inv);

#endif

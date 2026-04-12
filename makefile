/***************************************************************
*File: makefile
*Author: Esra P.
*Purpose: 
*Version: 1.0 Apr 11, 2026  
*Acknowledgment of AI usage: AI was used to help write the 
*	makefile due to the complexity of its nature.
****************************************************************/
CC = gcc 
CFLAGS = -Wall -Wextra -std=c11 -MMD -MP 

SRCS =	bottleRoute.c	chickenRoute.c	grilledRoute.c	umbrellaRoute.c	inventory.c	milkMain.c	quitters.c
OBJS = $(SRCS:.c=.o)

TARGET = milkMain 

all: $(TARGET) 

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) $(OBJS:.o=.d)

-include $(OBJS:.o=.d)

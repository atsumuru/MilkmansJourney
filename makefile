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

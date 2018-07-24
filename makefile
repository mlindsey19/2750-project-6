#David Lindsey
#cs2750 pa6
# 24-07-2018


CC = gcc -std=c99
CFLAGS = -Wall -g

OBJ = main.o

bank: $(OBJ)
	$(CC) $(CFLAGS) -o bank $(OBJ)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

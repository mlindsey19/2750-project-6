#David Lindsey
#cs2750 pa6
# 24-07-2018


CC = gcc -std=c99
CFLAGS = -Wall -g

OBJ = main.o newAcct.o

bank: $(OBJ)
	$(CC) $(CFLAGS) -o bank $(OBJ)
main.o: main.c newAcct.h
	$(CC) $(CFLAGS) -c main.c
newAcct.o: newAcct.c
	$(CC) $(CFLAGS) -c newAcct.c

clean:
	rm bank $(OBJ)

CC = gcc
CFLAGS = -Wall -Wextra -std=c11

default: Exercise9

Exercise9: Exercise9.o Struct.o Palindrome.o FileIO.o
	$(CC) $(CFLAGS) -o Exercise9 Exercise9.o Struct.o Palindrome.o FileIO.o -lm

Exercise9.o: Exercise9.c Struct.h Palindrome.h FileIO.h
	$(CC) $(CFLAGS) -c Exercise9.c

Struct.o: Struct.c Struct.h
	$(CC) $(CFLAGS) -c Struct.c

Palindrome.o: Palindrome.c Palindrome.h
	$(CC) $(CFLAGS) -c Palindrome.c
	
FileIO.o: FileIO.c FileIO.h
	$(CC) $(CFLAGS) -c FileIO.c

clean:
	$(RM) Exercise9 *.o *~

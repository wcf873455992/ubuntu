#
#file name :Makefile
#Athor	:WCF
#DATE	: 2015.11.25
#

VERSON = 1
PATCHLEVEL = 0
SUBLEVEL =		0

OBJS = main.o
CC = gcc
CFLAGS = -Wall -O -g

ALL += $(obj)main

all:		$(ALL)
		
$(obj)main : $(OBJS)
	$(CC)   $(OBJS) -o main 

main.o : main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

#file2.o : file2.c file2.h
#	$(CC) $(CFLAGS) -c file2.c -o file2.o
clean:
	rm -rf *.o main
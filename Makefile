#
# Makefile that builds the CS:APP Data Lab
# There is no need to ever change this Makefile

# General variables
TEAM = $(USER)
CPP = cpp
CPPFLAGS = -P -C
CC = gcc
# CFLAGS = -O1 -g -Wall -m32 
CFLAGS = -O1 -g -Wall
LIBS = 
# LIBS = -lm

# Where are the different parts of the lab should be copied to when they
# are handed in.
HANDINDIR-PARTA = ./handin-parta
HANDINDIR-PARTB = ./handin-partb

empty: main.c 
	$(CC) $(CFLAGS) $(LIBS) -c main.c 
	$(CC) $(CFLAGS) $(LIBS) main.o -o hw1 

all: hw1 handin

#
# Build the btest test harness that checks bits.c for correctness
#
hw1a.o: hw1a.c hw1a.h
	$(CC) $(CFLAGS) -c hw1a.c

hw1b.o: hw1b.c hw1b.h
	$(CC) $(CFLAGS) -c hw1b.c

hw1a: main.c hw1a.o 
	$(CC) -DHW1A $(CFLAGS) $(LIBS) -c main.c 
	$(CC) $(CFLAGS) $(LIBS) main.o hw1a.o -o hw1

hw1b: main.c hw1b.o 
	$(CC) -DHW1B $(CFLAGS) $(LIBS) -c main.c 
	$(CC) $(CFLAGS) $(LIBS) main.o hw1b.o -o hw1

hw1: main.c hw1a.o hw1b.o 
	$(CC) -DHW1A -DHW1B $(CFLAGS) $(LIBS) -c main.c 
	$(CC) $(CFLAGS) $(LIBS) main.o hw1a.o hw1b.o -o hw1 

# Use this rule to hand in Part A ("make handin-parta")
handin-parta: hw1a
	mkdir $(HANDINDIR-PARTA)
	cp -p hw1a.c $(HANDINDIR-PARTA)/$(TEAM)-hw1a.c

# Use this rule to hand in Part B ("make handin-partb")
handin-partb: hw1b
	mkdir $(HANDINDIR-PARTB)
	cp -p hw1b.c $(HANDINDIR-PARTB)/$(TEAM)-hw1b.c

#
# Clean the top-level src directory
#
clean:
	rm -f *.o *~ hw1a hw1b hw1 



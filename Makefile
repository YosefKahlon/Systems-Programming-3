CC=gcc
AR=ar
OBJECT_MAIN=main.o
OBJECT_LIB=NumClass.o
FLAGS=-Wall -g   
all: stringProg 
		
Ex3.o: main.c 
	$(CC) $(FLAGS) -c main.c
	
stringProg: main.o 
	$(CC) $(FLAGS) main.o -lm -o stringProg
	
.PHONY: clean all

clean:
	rm -f *.o *.a *.so stringProg	
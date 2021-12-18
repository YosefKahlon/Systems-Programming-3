CC=gcc
AR=ar
OBJECT_MAIN=main.o
OBJECT_LIB=NumClass.o
FLAGS=-Wall -g   
	
all: stringProg

stringProg: main.o str.o
	gcc -Wall -g -o stringProg main.o str.o

main.o: main.c mylib.h
	gcc -Wall -g -c main.c

str.o: str.c mylib.h
	gcc -Wall -g -c str.c

clean:
	rm -f *.o *.a stringProg
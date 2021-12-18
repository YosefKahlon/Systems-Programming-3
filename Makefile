all: stringProg 
		
Ex3.o: Ex3.c 
	$(CC) $(FLAGS) -c Ex3.c
	
stringProg: Ex3.o 
	$(CC) $(FLAGS) Ex3.o -lm -o stringProg
	
.PHONY: clean all

clean:
	rm -f *.o *.a *.so stringProg	
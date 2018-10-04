CC		= gcc
CFLAG	= -g

all : tobinary.o

tobinary.o : tobinary.c
	$(CC) -c tobinary.c $(CFLAG)
	
clean :
	rm -rf *.o
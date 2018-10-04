CC		= gcc
CFLAG	= -g

all : toBinary.o dataToBinary_p.o

toBinary.o : toBinary.c
	$(CC) -c toBinary.c $(CFLAG)
	
dataToBinary_p.o : dataToBinary_p.c
	$(CC) -c dataToBinary_p.c $(CFLAG)
	
clean :
	rm -rf *.o
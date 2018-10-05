CC		= gcc
CFLAG	= -g
LFLAG	= -g

all : main toBinary.o dataToBinary_p.o

main : main.c toBinary.o dataToBinary_p.o
	$(CC) -o main main.c toBinary.o dataToBinary_p.o $(LFLAG)

toBinary.o : toBinary.c
	$(CC) -c toBinary.c $(CFLAG)
	
dataToBinary_p.o : dataToBinary_p.c
	$(CC) -c dataToBinary_p.c $(CFLAG)
	
clean :
	rm -rf main *.o
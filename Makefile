CC=gcc
FLAGS=-mavx -mavx2 -Wall -lpapi -lm

all: program clear

program: main.o vetorizado.o 
	$(CC) -o arq2 main.o vetorizado.o $(FLAGS)

main.o: ./src/main.c vetorizado.o
	$(CC) -c ./src/main.c $(FLAGS)

vetorizado.o: ./src/vetorizado.c
	$(CC) -c ./src/vetorizado.c $(FLAGS)

clear:
	rm -r *.o ./info/resul*
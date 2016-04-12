CC=gcc
CFLAGS=-W -Wall -lrt -pthread 
LDFLAGS=
LDLIBS=
EXEC=main

all: $(EXEC)

main: main.o machine.o piece.o robot_retrait.o superviseur.o robot_alimentation.o predicat_liste.o message.o
	$(CC) -o main main.o machine.o piece.o robot_retrait.o superviseur.o robot_alimentation.o predicat_liste.o message.o $(CFLAGS)
	
	
	
main.o: main.c 
	$(CC) -o main.o -c main.c $(CFLAGS)
	
#fonctions_utiles.o: fonctions_utiles.c
#	$(CC) -o fonctions_utiles.o -c fonctions_utiles.c $(CFLAGS)

machine.o: machine.c
	$(CC) -o machine.o -c machine.c $(CFLAGS)

piece.o: piece.c
	$(CC) -o piece.o -c piece.c $(CFLAGS)

predicat_liste.o: predicat_liste.c
	$(CC) -o predicat_liste.o -c predicat_liste.c $(CFLAGS)
	
robot_retrait.o: robot_retrait.c
	$(CC) -o robot_retrait.o -c robot_retrait.c $(CFLAGS)

superviseur.o: superviseur.c
	$(CC) -o superviseur.o -c superviseur.c $(CFLAGS)

robot_alimentation.o: robot_alimentation.c 
	$(CC) -o robot_alimentation.o -c robot_alimentation.c $(CFLAGS)
	
message.0: message.c	
	$(CC) -o message.o -c message.c $(CFLAGS)

#variable_globale.o: variable_globale.c
	#$(CC) -o variable_globale.o -c variable_globale.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

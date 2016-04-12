#ifndef SUPERVISEUR
#define SUPERVISEUR
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h> 

#include "machine.h"
#include "predicat_liste.h"

#define nbMachine 1
extern pthread_t Th_machine[nbMachine];

struct param
{
	pthread_t code_piece;
	pthread_t numero_machine;
};
typedef struct param param;

void fonc_evenementielle_USER1 (list l);
void *Th_Dialogue();
/*void fonc_evenementielle_USER1 (list l);
void fnc_evenementielle_SIGUSER2(list l);*/

#endif

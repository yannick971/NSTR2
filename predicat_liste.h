#ifndef PREDICAT_LISTE
#define PREDICAT_LISTE

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list_thread list_thread;

struct list_thread
{
	pthread_t t;
	struct list_thread *next;

};
typedef list_thread* list;

list supprimerElementEnTete(list liste);
pthread_t teteListe(list liste);
list ajouterEnTete(list liste, pthread_t val);
list ajouterEnQueue(list liste,pthread_t val);

#endif

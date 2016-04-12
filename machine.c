#include "machine.h"
#include "message.h"


extern mq_t *message_RA_MA;
extern mq_t *message_PC_MA;
extern pthread_mutex_t Mutex_machine;
extern pthread_cond_t condition1;

void *Th_Machine()
{
	//while (1)
	//{
		printf("je suis le thread machine\n");
		sleep(2);
		printf("avant reception message table\n");
		pthread_mutex_lock(&Mutex_machine);
		pthread_cond_wait (&condition1, &Mutex_machine);
		printf("machine received '%s'\n",recv(message_PC_MA));
    	pthread_mutex_unlock(&Mutex_machine);
		//retirer piece du convoyeur
/*
		pthread_mutex_lock(&Mutex_machine);
		send(message_PC_MA, "fin de depot de piece brute sur la table");
		pthread_cond_signal (&condition);
		pthread_mutex_unlock (&Mutex_machine);
		//usinage
		//sleep(1);
		//send(message_PC_MA, "fin usinage");
		
		//printf("machine received '%s'\n",recv(message_PC_MA));//FIN DEPOT PIECE USINÉE
		//deposer piece
		//send(message_PC_MA, "fin depot piece usinnee sur convoyeur");
	//}*/
	return 0;
}
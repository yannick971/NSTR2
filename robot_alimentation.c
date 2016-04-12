#include "robot_alimentation.h"
#include "message.h"

extern mq_t *message_RA_PC;
//extern mq_t *message_RA_CV;
extern pthread_cond_t condition;
extern pthread_mutex_t Mutex_RA;

void fonc_evenementielle_timerRA(pthread_t x)
{
	
	printf("Arret du robot d'alimentation, car l'operation de dépot de piece a duree plus de 20 sec\n");
	
}

void *Th_Robot_alimentation()
{
	printf("je suis le robot alimentation\n");
	//sleep(1);
	//while(1)
	//{
		pthread_mutex_lock(&Mutex_RA);
		pthread_cond_wait (&condition, &Mutex_RA);
		printf("robot alim received '%s'\n",recv(message_RA_PC));
		sleep(2);

		send(message_RA_PC, "fin depot piece sur convoyeur");
		pthread_cond_signal (&condition);
		pthread_mutex_unlock(&Mutex_RA);
		
	//}
	return 0;
}
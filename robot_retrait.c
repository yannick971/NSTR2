#include "robot_retrait.h"
#include "message.h"

extern mq_t *message_RR_PC;

void fonc_evenementielle_timerRR(pthread_t x)
{

	printf("arret du robot d'alimentation, car l'opération de dépot de piece a duré plus de 20 sec");
}

void *Th_Robot_retrait()
{
	//while(1)
	//{
		//sleep(3);
		printf("je suis le robot retrait\n");
		//printf("Robot retrait received '%s'\n", recv(message_RR_PC));
		//sleep(1);
		//retrait piece du convoyeur

		//send(message_RR_PC,"fin du retrait de la piece usinée du convoyeur ");
	//}
	return 0;
}
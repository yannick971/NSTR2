/*#include "fonctions_utiles.h"*/
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <mqueue.h>

#include "superviseur.h"
#include "robot_alimentation.h"
#include "robot_retrait.h"
#include "machine.h"
#include "message.h"



#define nbMachine  1

pthread_t Th_dialogue;
pthread_t Th_robot_alimentation;
pthread_t Th_robot_retrait;
pthread_t Th_machine[nbMachine];
pthread_mutex_t mutexMachine[nbMachine];

mq_t *message_RA_PC;
mq_t *message_RA_CV;	
mq_t *message_RA_MA;
mq_t *message_RR_PC;
mq_t *message_PC_MA;

int main(void)
{		
	int dial=0;
	int r_alim=0;
	int r_retrait=0;
	int machine[3] = {0};
	int i=0;

	message_RA_PC = create();
	message_RA_CV = create();

	for(i=0; i<nbMachine; i++)
	{
		

		machine[i] = pthread_create(&Th_machine[i], NULL, Th_Machine,NULL);

			if(!machine[i])
				printf("Creation thread machine reussi!\n");
			else
				perror("thread machine non crée\n");
	}

	
	dial = pthread_create(&Th_dialogue, NULL, Th_Dialogue ,NULL);
	if(!dial)
		printf("Creation thread dialogue reussi!\n");
	
	r_alim = pthread_create(&Th_robot_alimentation, NULL, Th_Robot_alimentation,NULL);
	if(!r_alim)
		printf("Creation thread robot alim reussi!\n");
	r_retrait = pthread_create(&Th_robot_retrait, NULL, Th_Robot_retrait,NULL);		
	if(!r_retrait)
		printf("Creation thread robot retrait reussi!\n");
	
	if(pthread_join(Th_robot_alimentation,NULL))
		perror("join robot alim\n");
	if(pthread_join(Th_robot_retrait,NULL))
		perror("join robot retrait\n");	
	if(pthread_join(Th_dialogue,NULL))
		perror("join dialogue\n");
	
		
	return 0;
}

#include "piece.h"
#include "message.h"


extern mq_t *message_RA_PC;
extern mq_t *message_RA_MA;
extern mq_t *message_RR_PC;	
extern mq_t *message_PC_MA;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
pthread_cond_t condition1 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t Mutex_convoyeur = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t Mutex_RA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t Mutex_machine = PTHREAD_MUTEX_INITIALIZER;
void *Th_piece(void* parameters)
{
	param* p = (param*) parameters;
	p->code_piece = pthread_self();
	printf("je suis le thread piece\n");
	
	pthread_mutex_t Mutex_machine[nbMachine];
	int i;

	
	//condition = PTHREAD_COND_INITIALIZER;

	for(i =0; i<nbMachine; i++)
	{
		pthread_mutex_init ( &Mutex_machine[i], NULL);
	}

	//pthread_mutex_lock(Mutex_machine[0]);//a revoir le numéro de machine
	pthread_mutex_lock(&Mutex_RA);
	 
	send(message_RA_PC,"deposer piece brute sur convoyeur");
	pthread_cond_signal (&condition);
	pthread_mutex_unlock (&Mutex_RA);
	//printf("%s\n", );
	pthread_mutex_lock(&Mutex_RA);
	pthread_cond_wait (&condition, &Mutex_RA);
	printf("piece recieved '%s'\n", recv(message_RA_PC));
	pthread_mutex_unlock(&Mutex_RA);

	
	pthread_mutex_lock(&Mutex_machine);
	send(message_PC_MA,"deposer piece sur table");
	pthread_cond_signal (&condition1);
	pthread_mutex_unlock (&Mutex_machine);
/*
	pthread_mutex_lock(&Mutex_machine);
	pthread_cond_wait (&condition, &Mutex_machine);
	printf("piece recieved '%s'\n", recv(message_PC_MA));
	pthread_mutex_unlock(&Mutex_machine);
*/

	//sprintf("piece recieved '%s'\n", recv(message_PC_MA));
	return 0;
}
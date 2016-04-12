#include "superviseur.h"
#include "piece.h"

void fonc_evenementielle_USER1 (list l)
{
	printf("fonc_evenementielle_USER1\n");
	pthread_t x;
	while( l != NULL)
	{
		x=teteListe(l);
		printf("%ld\n",(long)x);
		if(pthread_kill(x, SIGKILL))
		{
			printf("processus mort\n");
		}
		perror("fin anormale du systeme\n");
		l=l->next;
	}
}

void fonc_evenementielle_USER2 (list l, pthread_t sender)
{
	printf("fonc_evenementielle_USER2\n");

	l = supprimerElement(l,sender);

}



void *Th_Dialogue()
{
	while(1)
	{
		pthread_t Th_Piece;
		param para;
		int piece;
		list ListeThreadPiece = NULL;
		printf("je suis le superviseur\n");

		para.code_piece=0;
		para.numero_machine=Th_machine[0];

		piece = pthread_create(&Th_Piece, NULL,Th_piece, &para);
		if(!piece)
			printf("Creation thread piece reussi!\n");
	
		ListeThreadPiece = ajouterEnTete(ListeThreadPiece, Th_Piece);

		sleep(5);

		fonc_evenementielle_USER1 (ListeThreadPiece);
		if(pthread_join(Th_Piece,NULL))
			perror("join piece\n");
	}
	return 0;
}
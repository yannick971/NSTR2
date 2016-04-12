#include "predicat_liste.h"


list supprimerElementEnTete(list liste)
{
	if(liste != NULL)
	{
		list_thread* aRenvoyer = liste->next;
		free (liste);
		return aRenvoyer;
	}
	else
		return NULL;
}


list supprimerElement(list liste, pthread_t valeur)
{
	list_thread* tmp;
	list_thread* previous;
 
	if (liste == NULL) // si la liste est NULL on s'arrete tout de suite
  		return liste;

	previous = liste;
	if (previous->t == valeur) // Verifie la tete de liste, cas particulier
	{
  		liste = previous->next;
  		free(previous);
  		return liste;
	}

	tmp = previous->next; // le cas n est gere on se place donc sur le cas n+1
	while(tmp != NULL) // On Mouline est on supprime si on trouve l'element
	{
  		if (tmp->t == valeur)
  		{
    		previous->next = tmp->next;
    		free(tmp);
    		return liste;
  		}
  		previous = tmp; // pour ce souvenir dans la prochaine iteration du precedent
  		tmp = tmp->next;
	}
	return liste;
}


pthread_t teteListe(list liste)
{
	if(liste == NULL)
		return 0;
	else
		return liste->t;
}

list ajouterEnTete(list liste, pthread_t val)
{
	list_thread* nouvelElement = malloc(sizeof(list_thread));
	nouvelElement-> t = val;
	nouvelElement-> next = liste;
	printf("ajout reussi\n");
	return nouvelElement;
}

list ajouterEnQueue(list liste,pthread_t val)
{
	list_thread* nouvelElement = malloc(sizeof(list_thread));

	nouvelElement-> t = val;

	if(!nouvelElement) 
		exit(EXIT_FAILURE);
	
	if(liste == NULL)
		return nouvelElement;
	else
	{
		list_thread* temp = liste;
		while( temp -> next !=NULL)
		{
			temp = temp -> next;
		}
		
		temp -> next = nouvelElement;
	}	
		return liste;
}
	

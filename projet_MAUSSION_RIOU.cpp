
/*! \file projet_MAUSSION_RIOU.cpp
	\brief Optimisation de la deuxième version du problème de voyageur de commerce
	\author RIOU Matthieu, MAUSSION Damien
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glpk.h> /* Nous allons utiliser la bibliothèque de fonctions de GLPK */

#include <time.h>
#include <sys/time.h>
#include <sys/resource.h> /* Bibliothèques utilisées pour mesurer le temps CPU */

#include <math.h>
#include <list>
#include "donnees.h"
#include "AlgoEnumeration.h"
#include "PartitionnementEnsemble.h"

#include <iostream>

/* structures et fonctions de mesure du temps CPU */

struct timeval start_utime;	//!< Retient le temps de départ du crono
struct timeval stop_utime; 	//!< Retient le temps d'arrêt du crono

/*! \brief Démarre le crono
*/
void crono_start()
{
	struct rusage rusage;
	
	getrusage(RUSAGE_SELF, &rusage);
	start_utime = rusage.ru_utime;
}

/*! \brief Arrête le crono
*/
void crono_stop()
{
	struct rusage rusage;
	
	getrusage(RUSAGE_SELF, &rusage);
	stop_utime = rusage.ru_utime;
}

/*! \brief Donne le temps du crono
	\return Le temps en ms
*/
double crono_ms()
{
	return (stop_utime.tv_sec - start_utime.tv_sec) * 1000 +
    (stop_utime.tv_usec - start_utime.tv_usec) / 1000 ;
}



/*! \brief Lecture des données
	\param file Le chemin du fichier de données
	\param p Les données à remplir
*/
void lecture_data(char *file, donnees *p)
{
	int i,j;
	FILE *fin;
	
	int val;
	fin = fopen(file,"rt");
	
	/* Lecture du nombre de villes */
	
	fscanf(fin,"%d",&val);
	p->nblieux = val;

	/* Allocation mémoire pour la demande de chaque ville, et le distancier */
	
	p->demande = (int *) malloc (val * sizeof(int));
	p->C = (int **) malloc (val * sizeof(int *));
	for(i = 0;i < val;i++) p->C[i] = (int *) malloc (val * sizeof(int));
	
	/* Lecture de la capacité */
	
	fscanf(fin,"%d",&val);
	p->capacite = val;
	
	/* Lecture des demandes des clients */
	
	for(i = 1;i < p->nblieux;i++)
	{
		fscanf(fin,"%d",&val);
		p->demande[i] = val;
	}
	
	/* Lecture du distancier */

	for(i = 0; i < p->nblieux; i++)
		for(j = 0; j < p->nblieux; j++)
		{
			fscanf(fin,"%d",&val);
			p->C[i][j] = val;
		}
		
	fclose(fin);
}

/*! \brief Libère les données en mémoire
	\param p Les données à détruire
*/
void free_data(donnees *p)
{
	int i;
	for(i = 0;i < p->nblieux;i++) free(p->C[i]);
	free(p->C);
	free(p->demande);	
}


/*! \brief Fonction main
	Elle résout le problème d'optimisation de Blade Flyer en le décomposant en trois parties distinctes. Elle affiche ensuite son temps d'exécution.
	\param argc Le nombre d'argument
	\param argv Les arguments. Le nom du fichier de données est attendu en premier argument.
*/
int main(int argc, char *argv[])
{	
	/* Déclarations des variables */

	donnees d; 
	double temps;
		
	/* Chargement des données à partir d'un fichier */
	
	lecture_data(argv[1],&d);
	
	/* Lancement de la résolution... */

	crono_start(); // .. et donc du chronomètre


	/* Partie 1 : Calcul des regroupements de clients 
	 * 	Problème d'énumération
	 */
	
	std::list<Tournee*> t = enumTournee(d);


	/* Partie 2 : Calcul de la longueur minimum de chaque tournée
	 * 	Problème du Voyageur de Commerce
	 */
	 
	std::list<Tournee*>::iterator it;
	 
	for(it = t.begin(); it != t.end(); ++it)
	{
		(*it)->calculLongueurMin(d);
	}

	/* Partie 3 : Calcul du meilleure ensemble de tournée
 	 * 	Problème de partitionnement d'ensemble
 	 */
	partitionnementEnsemble(t, d.nblieux);




	/* Problème résolu, arrêt du chrono */
	
	crono_stop();
	temps = crono_ms()/1000,0;
	
	/* Affichage des résultats */
	
	printf("Temps : %f\n",temps);	
	
	/* libération mémoire */

	free_data(&d);

	for(it = t.begin(); it != t.end(); ++it)
	{
		delete (*it);
	}
	
	/* J'adore qu'un plan se déroule sans accroc! (Moi aussi !) */
	return 0;
}

#ifndef DONNEES_H
#define DONNEES_H

/*! \file donnees.h
	\brief Définie les données du problème
	\author RIOU Matthieu, MAUSSION Damien
*/

/*! \struct donnees
	\brief Structure définissant les données du problème
*/
typedef struct {
	int nblieux; 	//!< Nombre de lieux (incluant le dépôt)
	int capacite; 	//!< Capacité du véhicule de livraison
	int *demande; 	//!< Demande de chaque lieu (la case 0 est inutilisée car le dépôt n'a aucune demande à voir satisfaire)
	int **C; 		//!< distancier (les lignes et colonnes 0 correspondent au dépôt)
} donnees;

#endif //DONNEES_H

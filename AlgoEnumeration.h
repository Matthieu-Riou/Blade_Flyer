#ifndef PROJET_H
#define PROJET_H

/*! \file AlgoEnumeration.h
	\brief Les algorithmes pour l'énumération des regroupements de clients
	\author RIOU Matthieu, MAUSSION Damien
*/

#include <list>
#include "donnees.h"
#include "Tournee.h"
#include "Enumeration.h"

std::list<Tournee*> enumTournee(donnees const& d);
void algoRecursif(Enumeration &e, std::list<Tournee*> &t, donnees const& d);

#endif //PROJET_H

#ifndef PARTITIONNEMENT_ENSEMBLE_H
#define PARTIONNEMENT_ENSEMBLE_H

/*! \file PartitionnementEnsemble.h
	\brief Résolution du problème de partitionnement d'ensemble
	\author RIOU Matthieu, MAUSSION Damien
*/

#include <vector>
#include <list>
#include "Tournee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glpk.h>

void partitionnementEnsemble(std::list<Tournee*> const& tournee, int nbLieux);

#endif //PARTITIONNEMENT_ENSEMBLE_H

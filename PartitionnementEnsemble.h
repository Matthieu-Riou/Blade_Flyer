#ifndef PARTITIONNEMENT_ENSEMBLE_H
#define PARTIONNEMENT_ENSEMBLE_H

#include <vector>
#include "Tournee.h"
#include <glpk.h>

void partitionnementEnsemble(std::vector<Tournee*> const& tournee, int nbLieux);

#endif //PARTITIONNEMENT_ENSEMBLE_H

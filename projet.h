#ifndef PROJET_H
#define PROJET_H

#include <vector>
#include "donnees.h"
#include "Tournee.h"
#include "Enumeration.h"

std::vector<Tournee*> algoGlouton(donnees const& d);
void algoRecursif(Enumeration &e, std::vector<Tournee*> &t, donnees const& d);

#endif //PROJET_H

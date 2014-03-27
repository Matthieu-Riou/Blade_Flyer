#ifndef TOURNEE_H
#define TOURNEE_H

#include <vector>
#include <list>
#include <utility> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glpk.h>
#include "Enumeration.h"

struct Variable
{
	int depart;
	int arrivee;
	char nom[4];
	int valeur;
};

class Tournee
{
	private: 
		std::vector<int> clients;
		std::vector<int> permutationMin;
		int longueurMin;
	
	public:
		Tournee(Enumeration const& e);
		std::vector<int> const& getClients() const;

		int getLongueurMin() const;

		int calculLongueurMin(donnees const& d);
};


#endif //TOURNEE_H

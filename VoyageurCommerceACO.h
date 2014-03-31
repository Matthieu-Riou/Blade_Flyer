#ifndef VOYAGEUR_COMMERCE_ACO_H
#define VOYAGEUR_COMMERCE_ACO_H

#include "donnees.h"
#include <vector>
#include <utility>

class VoyageurCommerceACO
{
	private:
		std::vector<int> const& clients;
		std::vector<int> permutationMin;
		int longueurMin;

		std::vector<std::vector<int> > intensite;

		int aleatoire(int villeDepart, std::vector<int> const& villes, donnees const& d);
		int rechercheDicho(int const& random, std::vector<int> const& proba, int deb, int fin);

	public:
		VoyageurCommerceACO(std::vector<int> const& client);
		
		std::pair<int, std::vector<int>& > execute(donnees const& d);
};

#endif //VOYAGEUR_COMMERCE_FOURMI_H

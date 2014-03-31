#ifndef VOYAGEUR_COMMERCE_H	
#define VOYAGEUR_COMMERCE_H

#include "donnees.h"
#include "Tournee.h"
#include <vector>
#include <utility>

class VoyageurCommerce{

	private:
		std::vector<int> const& clients;
		std::vector<int> permutationMin;
		int longueurMin;
		
		void recursifLongueurMin(std::vector<int>& permut, int nextClient, donnees const& d);
		int calculLongueur(std::vector<int> const& permut, donnees const& d) const;


	public:
		VoyageurCommerce(std::vector<int> const& client);
		
		std::pair<int, std::vector<int>& > execute(donnees const& d);
};

#endif //VOYAGEUR_COMMERCE_H



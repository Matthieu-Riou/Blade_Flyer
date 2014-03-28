#ifndef VOYAGEUR_COMMERCE2OPTI_H	
#define VOYAGEUR_COMMERCE2OPTI_H

#include "donnees.h"
#include "Tournee.h"
#include <vector>
#include <list>
#include <utility>

class VoyageurCommerce2opti
{
	private:
		std::vector<int> const& clients;
		std::vector<int> permutationMin;
		int longueurMin;
		
		void recursifLongueurMin(std::vector<int>& permut, std::vector<int>& index, donnees const& d, int longueurCourante);
		int calculLongueur(std::vector<int> const& permut, donnees const& d) const;


	public:
		VoyageurCommerce2opti(std::vector<int> const& client);
		
		std::pair<int, std::vector<int>& > execute(donnees const& d);
};

#endif //VOYAGEUR_COMMERCE2OPTI_H



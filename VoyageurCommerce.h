#ifndef VOYAGEUR_COMMERCE_H	
#define VOYAGEUR_COMMERCE_H

/*! \file VoyageurCommerce.h
	\brief Première version du problème de voyageur de commerce
	\author RIOU Matthieu, MAUSSION Damien
*/

#include "donnees.h"
#include "Tournee.h"
#include <vector>
#include <utility>
#include <limits>

/*! \class VoyageurCommerce
	\brief Classe résolvant le problème du voyageur de commerce
*/
class VoyageurCommerce
{
	private:
		std::vector<int> const& clients;	//!< Tableau des clients
		std::vector<int> permutationMin;	//!< La permutation offrant une longueur minimum
		int longueurMin;					//!< La longueur minimum
		
		void recursifLongueurMin(std::vector<int>& permut, int nextClient, donnees const& d);
		int calculLongueur(std::vector<int> const& permut, donnees const& d) const;

	public:
		VoyageurCommerce(std::vector<int> const& client);
		
		std::pair<int, std::vector<int>& > execute(donnees const& d);
};

#endif //VOYAGEUR_COMMERCE_H



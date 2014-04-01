#ifndef VOYAGEUR_COMMERCE2_H	
#define VOYAGEUR_COMMERCE2_H

/*! \file VoyageurCommerce2.h
	\brief Deuxième version du problème de voyageur de commerce
	\author RIOU Matthieu, MAUSSION Damien
*/

#include "donnees.h"
#include "Tournee.h"
#include <vector>
#include <utility>
#include <limits>

/*! \class VoyageurCommerce2
	\brief Classe résolvant le problème du voyageur de commerce
*/
class VoyageurCommerce2
{
	private:
		std::vector<int> const& clients;	//!< Tableau des clients
		std::vector<int> permutationMin;	//!< La permutation offrant une longueur minimum
		int longueurMin;					//!< La longueur minimum
		
		void recursifLongueurMin(std::vector<int>& permut, std::vector<int>& index, donnees const& d);
		int calculLongueur(std::vector<int> const& permut, donnees const& d) const;


	public:
		VoyageurCommerce2(std::vector<int> const& client);
		
		std::pair<int, std::vector<int>& > execute(donnees const& d);
};

#endif //VOYAGEUR_COMMERCE2_H



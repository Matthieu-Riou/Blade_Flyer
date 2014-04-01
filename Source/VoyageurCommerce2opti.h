#ifndef VOYAGEUR_COMMERCE2OPTI_H	
#define VOYAGEUR_COMMERCE2OPTI_H

/*! \file VoyageurCommerce2opti.h
	\brief Optimisation de la deuxième version du problème de voyageur de commerce
	\author RIOU Matthieu, MAUSSION Damien
*/

#include "donnees.h"
#include "Tournee.h"
#include <vector>
#include <utility>
#include <limits>


/*! \class VoyageurCommerce2opti
	\brief Classe résolvant le problème du voyageur de commerce
*/
class VoyageurCommerce2opti
{
	private:
		std::vector<int> const& clients;	//!< Tableau des clients
		std::vector<int> permutationMin;	//!< La permutation offrant une longueur minimum
		int longueurMin;					//!< La longueur minimum
		
		void recursifLongueurMin(std::vector<int>& permut, std::vector<int>& index, donnees const& d, int longueurCourante);

	public:
		VoyageurCommerce2opti(std::vector<int> const& client);
		
		std::pair<int, std::vector<int>& > execute(donnees const& d);
};

#endif //VOYAGEUR_COMMERCE2OPTI_H



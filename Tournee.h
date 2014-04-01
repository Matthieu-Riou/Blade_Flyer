#ifndef TOURNEE_H
#define TOURNEE_H

/*! \file Tournee.h
	\brief Définie une Tournée
	\author RIOU Matthieu, MAUSSION Damien
*/

#include <vector>
#include <utility> 
#include "Enumeration.h"

/*! \class Tournee
	\brief Classe définissant une Tournée
*/
class Tournee
{
	private: 
		std::vector<int> clients;			//!< Tableau des clients
		std::vector<int> permutationMin;	//!< La permutation offrant une longueur minimum
		int longueurMin;					//!< La longueur minimum
	
	public:
		Tournee(Enumeration const& e);
		std::vector<int> const& getClients() const;

		int getLongueurMin() const;
		std::vector<int> getPermutationMin() const;

		void calculLongueurMin(donnees const& d);
};


#endif //TOURNEE_H

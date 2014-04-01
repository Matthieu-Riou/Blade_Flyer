#include "VoyageurCommerce2.h"

/*! \file VoyageurCommerce2.cpp
	\brief Deuxième version du problème de voyageur de commerce
	\author RIOU Matthieu, MAUSSION Damien
*/


/*! \brief Constructeur de VoyageurCommerce2
	\param client Le tableau des clients
*/
VoyageurCommerce2::VoyageurCommerce2(std::vector<int> const& client): clients(client)
{}


/*! \brief Fonction résolvant le problème du voyageur de commerce
	\param d Les données du problème
 	\return Paire (longueurMin, permutationMin)
*/
std::pair<int, std::vector<int>& > VoyageurCommerce2::execute(donnees const& d)
{
	longueurMin = std::numeric_limits<int>::max();
	std::vector<int> permut;
	permut.reserve(clients.size());
	std::vector<int> copieClient(clients);
	
	recursifLongueurMin(permut, copieClient, d);
		
	std::pair<int, std::vector<int>& > retour(longueurMin, permutationMin);
	
	return retour;
}	


/*! \brief Fonction récursive résolvant le problème du voyageur de commerce
	Cette version place à chaque itération tous les clients possibles dans l'emplacement suivant de la permutation
	\param permut La permutation courante
	\param copieClient Le tableau des clients restants
	\param d Les données du problème
*/
void VoyageurCommerce2::recursifLongueurMin(std::vector<int>& permut, std::vector<int>& copieClient, donnees const& d)
{
	if(permut.size() < copieClient.size()) //On a pas fini
	{
		for(int i = 0; i < copieClient.size(); i++)
		{
			if(copieClient[i] != -1)
			{
				int tmp = copieClient[i];
				permut.push_back(tmp);
				copieClient[i] = -1;
			
				recursifLongueurMin(permut, copieClient, d);
			
				permut.pop_back();
				copieClient[i] = tmp;
			}
		}
	}
	else //On a fini
	{
		int min = calculLongueur(permut, d);
		
		if(min < longueurMin)
		{
			longueurMin = min;	
			permutationMin = permut;
		}
	}
}

/*! \brief Fonction calculant la longueur d'une permutation
	\param permut La permutation courante
	\param d Les données du problème
	\return La longueur de la permutation
	\pre permut n'est pas vide
*/
int VoyageurCommerce2::calculLongueur(std::vector<int> const& permut, donnees const& d) const
{
	int min(d.C[0][permut[0]]);
	
	for(int i = 1; i < permut.size(); i++)
	{
		min += d.C[permut[i-1] ] [permut[i] ];
	}
	
	min += d.C[permut[permut.size()-1] ][0];
	
	return min;
}

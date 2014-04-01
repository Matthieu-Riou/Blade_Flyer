#include "VoyageurCommerce.h"

/*! \file VoyageurCommerce.cpp
	\brief Première version du problème de voyageur de commerce
	\author RIOU Matthieu, MAUSSION Damien
*/



/*! \brief Constructeur de VoyageurCommerce
	\param client Le tableau des clients
*/
VoyageurCommerce::VoyageurCommerce(std::vector<int> const& client): clients( client)
{}

/*! \brief Fonction résolvant le problème du voyageur de commerce
	\param d Les données du problème
 	\return Paire (longueurMin, permutationMin)
*/
std::pair<int, std::vector<int>& > VoyageurCommerce::execute(donnees const& d)
{
	longueurMin = std::numeric_limits<int>::max();
	std::vector<int> permut(clients.size(), -1);
	
	recursifLongueurMin(permut, 0, d);
		
	std::pair<int, std::vector<int>& > retour(longueurMin, permutationMin);
	
	return retour;
}	

/*! \brief Fonction récursive résolvant le problème du voyageur de commerce
	Cette version place à chaque itération le client suivant dans tous les emplacements possibles du tableau de permutation
	\param permut La permutation courante
	\param nextClient Le client suivant
	\param d Les données du problème
*/
void VoyageurCommerce::recursifLongueurMin(std::vector<int>& permut, int nextClient, donnees const& d)
{
	if(nextClient == clients.size())
	{
		int min = calculLongueur(permut, d);
		
		if(min < longueurMin)
		{
			longueurMin = min;	
			permutationMin = permut;
		}
	}
	else
	{
		for(int i = 0; i < permut.size(); i++)
		{
			if(permut[i] == -1)
			{
				permut[i] = clients[nextClient];
				recursifLongueurMin(permut, nextClient+1, d);
				permut[i] = -1;
			}
		}
	}
}

/*! \brief Fonction calculant la longueur d'une permutation
	\param permut La permutation courante
	\param d Les données du problème
	\return La longueur de la permutation
	\pre permut n'est pas vide
*/
int VoyageurCommerce::calculLongueur(std::vector<int> const& permut, donnees const& d) const
{
	int min(d.C[0][permut[0]]);
	
	for(int i = 1; i < permut.size(); i++)
	{
		min += d.C[permut[i-1]] [permut[i]];
	}
	
	min += d.C[permut[permut.size()-1]][0];
	
	return min;
}

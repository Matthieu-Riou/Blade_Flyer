#include "VoyageurCommerce2opti.h"

/*! \file VoyageurCommerce2opti.cpp
	\brief Optimisation de la deuxième version du problème de voyageur de commerce
	\author RIOU Matthieu, MAUSSION Damien
*/


/*! \brief Constructeur de VoyageurCommerce2opti
	\param client Le tableau des clients
*/
VoyageurCommerce2opti::VoyageurCommerce2opti(std::vector<int> const& client): clients(client)
{}


/*! \brief Fonction résolvant le problème du voyageur de commerce
	\param d Les données du problème
 	\return Paire (longueurMin, permutationMin)
*/
std::pair<int, std::vector<int>& > VoyageurCommerce2opti::execute(donnees const& d)		 //Problème du voyageur de commerce
{
	longueurMin = std::numeric_limits<int>::max();
	std::vector<int> permut;
	permut.reserve(clients.size());
	std::vector<int> copieClient(clients);
	
	recursifLongueurMin(permut, copieClient, d, 0);
		
	std::pair<int, std::vector<int>& > retour(longueurMin, permutationMin);
	
	return retour;
}	


/*! \brief Fonction récursive résolvant le problème du voyageur de commerce
	Cette version place à chaque itération tous les clients possibles dans l'emplacement suivant de la permutation
	De plus, elle optimise l'algorithme en calculant la longueur à chaque itération, et pas seulement à la fin, pour couper plus tôt le déroulement de l'algorithme
	\param permut La permutation courante
	\param copieClient Le tableau des clients restants
	\param d Les données du problème
	\param longueurCourante La longueur de la permutation courante
*/
void VoyageurCommerce2opti::recursifLongueurMin(std::vector<int>& permut, std::vector<int>& copieClient, donnees const& d, int longueurCourante)
{
	if(permut.size() == 1)
		longueurCourante = d.C[0][permut[0]];
	else if(permut.size() != 0)
		longueurCourante += d.C[permut[permut.size()-2]][permut[permut.size()-1]];

	if(longueurCourante < longueurMin)
	{
		if(permut.size() < copieClient.size())
		{
			for(int i = 0; i < copieClient.size(); i++)
			{
				if(copieClient[i] != -1)
				{
					int tmp = copieClient[i];
					permut.push_back(tmp);
					copieClient[i] = -1;
			
					recursifLongueurMin(permut, copieClient, d, longueurCourante);
			
					permut.pop_back();
					copieClient[i] = tmp;
				}
			}
		}
		else
		{
			int min = longueurCourante + d.C[permut[permut.size()-1]][0];
		
			if(min < longueurMin)
			{
				longueurMin = min;	
				permutationMin = permut;
			}
		}
	}
}

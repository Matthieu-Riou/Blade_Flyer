#include "VoyageurCommerce2opti.h"
#include <iostream>
#include <limits>

VoyageurCommerce2opti::VoyageurCommerce2opti(std::vector<int> const& client): clients(client)
{}

std::pair<int, std::vector<int>& > VoyageurCommerce2opti::execute(donnees const& d)		 //Problème du voyageur de commerce
{
	longueurMin = std::numeric_limits<int>::max();
	std::vector<int> permut;
	permut.reserve(clients.size());
	std::vector<int> index;

	for(int i = 0; i < clients.size(); i++)
	{
		index.push_back(clients[i]);
	}
	
	recursifLongueurMin(permut, index, d, 0);
		
	std::pair<int, std::vector<int>& > retour(longueurMin, permutationMin);
	
	return retour;
}	

void VoyageurCommerce2opti::recursifLongueurMin(std::vector<int>& permut, std::vector<int>& index, donnees const& d, int longueurCourante)
{
	if(permut.size() == 1)
		longueurCourante = d.C[0][permut[0]];
	else if(permut.size() != 0)
		longueurCourante += d.C[permut[permut.size()-2]][permut[permut.size()-1]];

	if(longueurCourante < longueurMin)
	{
		bool fini = true;

		for(int i = 0; i < index.size(); i++)
		{
			if(index[i] != -1)
			{
				fini = false;

				int tmp = index[i];
				permut.push_back(tmp);
				index[i] = -1;
			
				recursifLongueurMin(permut, index, d, longueurCourante);
			
				permut.pop_back();
				index[i] = tmp; //Fais le it++
			}
		}
	
		if(fini)
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

int VoyageurCommerce2opti::calculLongueur(std::vector<int> const& permut, donnees const& d) const
{
	int min(d.C[0][permut[0]]);
	
	for(int i = 1; i < permut.size(); i++)
	{
		min += d.C[permut[i-1] ] [permut[i] ];
	}
	
	min += d.C[permut[permut.size()-1] ][0];
	
	return min;
}

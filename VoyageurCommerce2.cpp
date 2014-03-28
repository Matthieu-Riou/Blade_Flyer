#include "VoyageurCommerce2.h"
#include <iostream>
#include <limits>

void afficheListe(std::vector<int> const& l)
{
	for(int i = 0; i < l.size(); i++)
	{
		std::cout << l[i] << ", ";
	}

	std::cout << std::endl;
}

VoyageurCommerce2::VoyageurCommerce2(std::vector<int> const& client): clients(client)
{}

std::pair<int, std::vector<int>& > VoyageurCommerce2::execute(donnees const& d)		 //Problème du voyageur de commerce
{
	longueurMin = std::numeric_limits<int>::max();
	std::vector<int> permut;
	permut.reserve(clients.size());
	std::vector<int> index;

	for(int i = 0; i < clients.size(); i++)
	{
		index.push_back(clients[i]);
	}
	
	recursifLongueurMin(permut, index, d);
		
	std::pair<int, std::vector<int>& > retour(longueurMin, permutationMin);
	
	return retour;
}	

void VoyageurCommerce2::recursifLongueurMin(std::vector<int>& permut, std::vector<int>& index, donnees const& d)
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
			
			recursifLongueurMin(permut, index, d);
			
			permut.pop_back();
			index[i] = tmp; //Fais le it++
		}
	}
	
	if(fini)
	{
		int min = calculLongueur(permut, d);
		
		if(min < longueurMin)
		{
			longueurMin = min;	
			permutationMin = permut;
		}
	}
}

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

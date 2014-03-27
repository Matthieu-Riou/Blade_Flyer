#include "VoyageurCommerce.h"
#include <iostream>
#include <limits>


VoyageurCommerce::VoyageurCommerce(std::vector<int> const& client): clients( client)
{}

std::pair<int, std::vector<int>& > VoyageurCommerce::execute(donnees const& d)		 //Problème du voyageur de commerce
{
	longueurMin = std::numeric_limits<int>::max();
	std::vector<int> permut(clients.size(), -1);
	
	recursifLongueurMin(permut, 0, d);
		
	std::pair<int, std::vector<int>& > retour(longueurMin, permutationMin);
	
	return retour;
}	

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
				permut[i] = nextClient;
				recursifLongueurMin(permut, nextClient+1, d);
				permut[i] = -1;
			}
		}
	}
}

int VoyageurCommerce::calculLongueur(std::vector<int> const& permut, donnees const& d) const
{
	int min(d.C[0][clients[permut[0]]]);
	
	for(int i = 1; i < permut.size(); i++)
	{
		min += d.C[ clients[permut[i-1]] ] [ clients[permut[i]] ];
	}
	
	min += d.C[ clients[permut[permut.size()-1]] ][0];
	
	return min;
}

#include "VoyageurCommerceACO.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>

VoyageurCommerceACO::VoyageurCommerceACO(std::vector<int> const& client) : clients(client), intensite(clients.size(), std::vector<int>(clients.size(), 0))
{
	std::cout << "coucou";
	srand(time(NULL));
	std::cout << intensite[0][0];
}

std::pair<int, std::vector<int>& > VoyageurCommerceACO::execute(donnees const& d)
{
	int tmax = 1;
	int m = 1;
	int nbVille = clients.size();

	for(int t = 0; t < tmax; t++)
	{
		for(int k = 0; k < m; k++)
		{
			std::vector<int> villes(clients);
			std::vector<int> chemin;

			int random = rand() % nbVille;

			chemin.push_back(random);	
			villes[random] = -1;		

			for(int i = 0; i < nbVille -1; i++)
			{
				random = aleatoire(clients[chemin.back()], villes, d);

				chemin.push_back(random);
				villes[random] = -1;
			}

			for(int i = 0; i < chemin.size(); i++)
			{
				std::cout << chemin[i] << " - ";
			}

			//std::swap(chemin, permutationMin);

			std::cout << std::endl << std::endl;
		}
	}
	
	//std::pair<int, std::vector<int>& > retour(5, permutationMin);
	
	//return retour;
}

int VoyageurCommerceACO::aleatoire(int villeDepart, std::vector<int> const& villes, donnees const& d)
{
	std::vector<int> proba;

	int total = 0;

	for(int i = 0; i < villes.size(); i++)
	{
		if(villes[i] == -1)
		{
			proba.push_back(total);
		}
		else
		{
			proba.push_back(total);
			total += (intensite[villeDepart][villes[i]] * (1/d.C[villeDepart][villes[i]]));
		}
	}

	int random = rand() % total;

	return rechercheDicho(random, proba, 0, proba.size()-1);
}

int VoyageurCommerceACO::rechercheDicho(int const& random, std::vector<int> const& proba, int deb, int fin)
{
	int index((fin-deb) / 2 + deb);

	if(proba[index] <= random)
	{
		if(index == fin)
		{
			return index;
		}
		else if(proba[index +1] > random)
		{
			return index;
		}
		else
		{
			return rechercheDicho(random, proba, index +1, fin);
		}
	}
	else
	{
		if(proba[index-1] <= random)
		{
			return index-1;
		}
		else
		{
			return rechercheDicho(random, proba, deb, index-2);
		}
	}
}

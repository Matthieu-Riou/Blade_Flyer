#include "Tournee.h"
#include "VoyageurCommerceACO.h"
#include <iostream>
#include <limits>

Tournee::Tournee(Enumeration const& e) : clients(e.getTab())
{}

std::vector<int> const& Tournee::getClients() const
{
	return clients;
}

int Tournee::getLongueurMin() const
{
	return longueurMin;
}

int Tournee::calculLongueurMin(donnees const& d) //Problème du voyageur de commerce
{
	VoyageurCommerceACO v(clients);
	//std::pair<int, std::vector<int>& > res = 
	v.execute(d);
	//longueurMin = res.first;
	//permutationMin = res.second;
}	



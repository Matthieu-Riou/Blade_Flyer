#include "Enumeration.h"

Enumeration::Enumeration(donnees const& don) : d(don), capaciteRestante(don.capacite)
{}

std::vector<int> const& Enumeration::getTab() const
{
	return tab;
}

int Enumeration::getCapaciteRestante() const
{
	return capaciteRestante;
}

int Enumeration::getNextClient() const
{
	if(!tab.empty())
		return tab.back()+1;
	else
		return 1;
}

//Condition : demande <= capaciteRestante
void Enumeration::add(int client)
{
	tab.push_back(client);
	capaciteRestante -= d.demande[client];
}

//!empty
void Enumeration::removeLast()
{
	capaciteRestante += d.demande[tab.back()];
	tab.pop_back();
}

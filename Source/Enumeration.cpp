#include "Enumeration.h"

/*! \file Enumeration.cpp
	\brief Définie une Enumeration de clients
	\author RIOU Matthieu, MAUSSION Damien
*/


/*! \brief Constructeur de Enumeration
	\param don Les données du problèmes
*/
Enumeration::Enumeration(donnees const& don) : d(don), capaciteRestante(don.capacite)
{}

/*! \brief Getter sur le tableau de clients
 	\return tab
*/
std::vector<int> const& Enumeration::getTab() const
{
	return tab;
}

/*! \brief Getter sur la capacité restante
 	\return capaciteRestante
*/
int Enumeration::getCapaciteRestante() const
{
	return capaciteRestante;
}

/*! \brief Getter sur le client suivant
 	\return 1 si c'est le premier client, le dernier client + 1 sinon
*/
int Enumeration::getNextClient() const
{
	if(!tab.empty())
		return tab.back()+1;
	else
		return 1;
}

/*! \brief Ajoute un client à l'énumératio
 	\param client Le client a ajouté
 	\pre demande du client <= capaciteRestante
*/
void Enumeration::add(int client)
{
	tab.push_back(client);
	capaciteRestante -= d.demande[client];
}

//!empty
/*! \brief Enlève le dernier client de l'énumération
 	\pre tab n'est pas vide
*/
void Enumeration::removeLast()
{
	capaciteRestante += d.demande[tab.back()];
	tab.pop_back();
}

#include "Tournee.h"
#include "VoyageurCommerce.h"

/*! \file Tournee.cpp
	\brief Définie une Tournée
	\author RIOU Matthieu, MAUSSION Damien
*/


/*! \brief Constructeur de Tournee
	\param e Une énumération complète
*/
Tournee::Tournee(Enumeration const& e) : clients(e.getTab())
{}

/*! \brief Getter sur le tableau de clients
 	\return clients
*/
std::vector<int> const& Tournee::getClients() const
{
	return clients;
}

/*! \brief Getter sur la longueur minimum
	\pre Avoir appelé calculLongueurMin
 	\return longueurMin
*/
int Tournee::getLongueurMin() const
{
	return longueurMin;
}

/*! \brief Getter sur la permutation de longueur minimum
	\pre Avoir appelé calculLongueurMin
 	\return permutationMin
*/
std::vector<int> Tournee::getPermutationMin() const
{
	return permutationMin;
}

/*! \brief Lance le calcul de la longueur minimum
	\param d Les données du problème
*/
void Tournee::calculLongueurMin(donnees const& d) //Problème du voyageur de commerce
{
	VoyageurCommerce v(clients);
	std::pair<int, std::vector<int>& > res = v.execute(d);
	longueurMin = res.first;
	permutationMin = res.second;
}	



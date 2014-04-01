#ifndef ENUMERATION_H
#define ENUMERATION_H

/*! \file Enumeration.h
	\brief Définie une Enumeration de clients
	\author RIOU Matthieu, MAUSSION Damien
*/

#include <vector>
#include "donnees.h"

/*! \class Enumeration
	\brief Classe définissant une énumération de clients
*/
class Enumeration
{
	private:
		std::vector<int> tab;	//!< Tableau des clients
		int capaciteRestante;	//!< Capacité restante du drône
		donnees const& d;		//!< Données du problème

	public:
		Enumeration(donnees const& don);
		std::vector<int> const& getTab() const;
		int getCapaciteRestante() const;
		int getNextClient() const;
		void add(int client);
		void removeLast();
};

#endif //ENUMERATION_H

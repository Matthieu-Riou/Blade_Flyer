#ifndef ENUMERATION_H
#define ENUMERATION_H

#include <vector>
#include "donnees.h"

class Enumeration
{
	private:
		std::vector<int> tab;
		int capaciteRestante;
		donnees const& d;

	public:
		Enumeration(donnees const& don);
		std::vector<int> const& getTab() const;
		int getCapaciteRestante() const;
		int getNextClient() const;
		void add(int client);
		void removeLast();
};

#endif //ENUMERATION_H

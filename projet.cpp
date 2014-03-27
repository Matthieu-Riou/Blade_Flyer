#include "projet.h"

#include <iostream>

std::vector<Tournee*> algoGlouton(donnees const& d)
{
	std::vector<Tournee*> t;
	
	Enumeration e(d);
		
	algoRecursif(e, t, d);

	return t;
	
}	




void algoRecursif(Enumeration &e, std::vector<Tournee*> &t, donnees const& d)
{
	if(!e.getTab().empty())
		t.push_back(new Tournee(e));
	
	for(int i = e.getNextClient(); i < d.nblieux; i++)
	{
		if(d.demande[i] <= e.getCapaciteRestante())
		{
			e.add(i);
			
			algoRecursif(e, t, d);
			
			e.removeLast(); //On annule pour le client suivant
		}
	}
}

	
			


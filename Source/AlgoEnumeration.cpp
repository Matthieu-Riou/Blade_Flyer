#include "AlgoEnumeration.h"

/*! \file AlgoEnumeration.cpp
	\brief Les algorithmes pour l'énumération des regroupements de clients
	\author RIOU Matthieu, MAUSSION Damien
*/

/*! \brief Initialise et appelle l'algorithme récursif d'énumuration
	\param d Les données du problème
*/
std::list<Tournee*> enumTournee(donnees const& d)
{
	std::list<Tournee*> t;
	
	Enumeration e(d);
		
	algoRecursif(e, t, d);

	return t;
	
}	


/*! \brief Algorithme récursif qui énumère les regroupements de clients possibles
	\param e L'énumeration courante
	\param t Le vector des tounées trouvées
	\param d Les données du problème
*/
void algoRecursif(Enumeration &e, std::list<Tournee*> &t, donnees const& d)
{
	if(!e.getTab().empty())
		t.push_back(new Tournee(e));
	
	for(int i = e.getNextClient(); i < d.nblieux; i++)
	{
		if(d.demande[i] <= e.getCapaciteRestante())
		{
			e.add(i); //On ajoute pour le client suivant
			
			algoRecursif(e, t, d);
			
			e.removeLast(); //On annule pour le client suivant
		}
	}
}

	
			


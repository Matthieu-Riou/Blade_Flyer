#include "PartitionnementEnsemble.h"

/*! \file PartitionnementEnsemble.cpp
	\brief Résolution du problème de partitionnement d'ensemble
	\author RIOU Matthieu, MAUSSION Damien
*/

/*! \brief Fonction utilisant glpk pour résoudre le problème de partitionnement d'ensemble
	\param tournee Le tableau des tournées, qui sont tous les ensembles du problème
	\param nbLieux Le nombre de lieux du problème
*/
void partitionnementEnsemble(std::list<Tournee*> const& tournee, int nbLieux)
{
	//Déclaration du problème
	glp_prob *prob;
	
	//Données

	int nbVar(tournee.size());
	int nbContr(nbLieux -1);

	//ia, ja, ar
	std::vector<int> ia;
	std::vector<int> ja;
	std::vector<double> ar;
	
	//Variables
	int i;
	int j;
	bool fini;
	double z;
	double x[nbVar+1];
	std::list<Tournee*>::const_iterator it;
	
	
	//Tableau des noms
	char nomVar[nbVar+1][10];
	char nomContr[nbContr+1][13];
	
	
	//Création du problème
	prob = glp_create_prob();
	glp_set_prob_name(prob, "Partionnement d'ensemble : choix des tournees");
	glp_set_obj_dir(prob, GLP_MIN);
	
	
	//Déclaration des contraintes
	
	glp_add_rows(prob, nbContr);
	
	for(i = 1; i <= nbContr; i++)
	{
		sprintf(nomContr[i], "Contrainte %d", i);
		
		glp_set_row_name(prob, i, nomContr[i]);
		
		glp_set_row_bnds(prob, i, GLP_FX, 1.0, 0.0);
	}
	
	
	//Déclaration des variables
	
	glp_add_cols(prob, nbVar); //On met à suivre les variables x puis les variables y
	
	for(i = 1; i <= nbVar; i++)
	{
		sprintf(nomVar[i],"x%d",i);
		
		glp_set_col_name(prob, i , nomVar[i]);
			
		glp_set_col_bnds(prob, i, GLP_DB, 0.0, 1.0); //Variables entre 0 et 1
		glp_set_col_kind(prob, i, GLP_BV); //Variables binaires
	}
	
	//Fonction objectif
	
	
	i = 1;
	for(it = tournee.begin(); it != tournee.end(); ++it)
	{
		glp_set_obj_coef(prob,i,(*it)->getLongueurMin());
		i++;
	}
	
	//Matrice creuse

	//ia : le numero de la contrainte
	//ja : le numero de la variable
	//ar : le coefficient de la variable
	ia.push_back(0);
	ja.push_back(0);
	ar.push_back(0.);

	//Pour chaque contrainte
	i = 1;
	for(it = tournee.begin(); it != tournee.end(); ++it)
	{
		std::vector<int> const& clients = (*it)->getClients();

		for(int j = 0; j < clients.size(); j++)
		{
			ia.push_back(clients[j]); //Le numero de la contrainte
			ja.push_back(i); //Le numero de la variable
			ar.push_back(1.0);
		}
		
		i++;
	}

	glp_load_matrix(prob,ia.size()-1,ia.data(),ja.data(),ar.data()); 


	//Pour le debug
	
	glp_write_lp(prob,NULL,"Exo1.lp");


	//Résolution

	glp_simplex(prob,NULL);
	glp_intopt(prob,NULL);

	z = glp_mip_obj_val(prob); // on récupère la solution de la fonction objectif

	//On récupère les variables solutions
	for(int i = 0; i < nbVar; i++) 
		x[i] = glp_mip_col_val(prob,i+1);


	//Affichage

	printf("\n\nz = %lf\n",z);

	it = tournee.begin(); //On va itérer sur les tournées en même temps qu'on parcourt le tableau des variables correspondantes

	for(int i = 0; i < nbVar; i++) //Affichage des x
	{
		if((int)(x[i] + 0.5) == 1)
		{
			printf("%s = %d  :  ",nomVar[i+1],(int)(x[i] + 0.5)); /* un cast est ajouté, x[i] pourrait être égal à 0.99999... */ 
			
			printf("[%d", (*it)->getPermutationMin()[0]);
			for(int j = 1; j < (*it)->getPermutationMin().size(); j++)
			{
				printf(", %d", (*it)->getPermutationMin()[j]);
			}
			
			printf("] de longueur %d\n", (*it)->getLongueurMin());
		}
		
		++it;
	}
	

	puts("");

	
	//Libération de la mémoire

	glp_delete_prob(prob);

}

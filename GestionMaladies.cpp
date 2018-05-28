/*
 * GestionMaladies.cpp
 *
 *  Created on: 24 mai 2018
 *      Author: lsilvestri
 */

#include "Valeur.h"
#include "ValeurId.h"
#include "ValeurDouble.h"
#include "ValeurString.h"
#include "GestionMaladies.h"

bool GestionMaladies::insererDonnees(Empreinte aAjouter,string maladie){

	ensembleReference.insert(ensembleReference.end(),aAjouter);
	map<string,vector<int>>::iterator mapMaladieItr= ensembleMaladies.find(maladie);
	if(mapMaladieItr != ensembleMaladies.end()){

		vector<int>index = mapMaladieItr->second;
		index.insert(index.end(), ensembleReference.size()-1);

	}else{

		vector<int> index;
		index.insert(index.end(),ensembleReference.size()-1);
		const pair<string,vector<int>> element = make_pair(maladie,index);
		ensembleMaladies.insert(ensembleMaladies.end(),element);
	}

	return true;
}

bool GestionMaladies::initialiserApplication(string nomFichierref, string nomFichierMaladies){

	return true;
}

list<pair<string,double>> GestionMaladies::diagnostiquerEmpreinte(Empreinte aAnalyser){


}

Empreinte GestionMaladies::caracteriserMaladie(string nomMaladie){

	map<string,vector<int>>::iterator mapMaladieItr= ensembleMaladies.find(nomMaladie);
	if(mapMaladieItr != ensembleMaladies.end()){
		//TODO : gerer le cas ou la maladie n'a pas d'empreintes associées
		vector<int> indexEmpreintes = mapMaladieItr->second;

		Empreinte resultat = usineEmpreinte.creerEmpreinte();
		list<Valeur*> *valeurResult = resultat.getValeurs();
		for(unsigned int i = 0 ; i < indexEmpreintes.size() ; i++){
			Empreinte empreinteCourante = ensembleReference[indexEmpreintes[i]];
			list<Valeur*>*valeursCourantes = empreinteCourante.getValeurs();
			list<Valeur*>::iterator parcours;
			for(parcours = valeursCourantes->begin();parcours!= valeursCourantes->end();parcours++){
				if(ValeurDouble* vd = dynamic_cast<ValeurDouble*>(*parcours))
				{

				}

				if(ValeurId* vi = dynamic_cast<ValeurId*>(*parcours))
				{
					}

				if(ValeurString* vs = dynamic_cast<ValeurString*>(valeur))
				{
				}

			}


		}

	}

}

list<string> GestionMaladies::decouperString(string elementFichier){


}


GestionMaladies::GestionMaladies() {
	//TODO : Faire une classe abstraite.

}


GestionMaladies::~GestionMaladies() {
	// TODO Auto-generated destructor stub
}


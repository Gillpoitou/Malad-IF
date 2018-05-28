/*
 * GestionMaladies.cpp
 *
 *  Created on: 24 mai 2018
 *      Author: lsilvestri
 */

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

			vector<int> indexEmpreintes = mapMaladieItr->second;


			for(unsigned int i = 0 ; i < indexEmpreintes.size() ; i++){
				Empreinte empreinteCourante = ensembleReference[indexEmpreintes[i]];

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


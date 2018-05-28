/*
 * GestionMaladies.h
 *
 *  Created on: 24 mai 2018
 *      Author: lsilvestri
 */

using namespace std;

#ifndef GESTIONMALADIES_H_
#define GESTIONMALADIES_H_
#include "UsineEmpreinte.h"
#include <string>
#include <map>
#include <vector>
#include <list>
#include <list>


class GestionMaladies {

public:

	bool insererDonnees(Empreinte aAjouter,string maladie);

	bool initialiserApplication(string nomFichierref, string nomFichierMaladies);

	list<pair<string,double>> diagnostiquerEmpreinte(Empreinte aAnalyser);

	Empreinte caracteriserMaladie(string nomMaladie);

	list<string> decouperString(string elementFichier);


	//Constructeurs, destructeurs
	GestionMaladies();
	GestionMaladies(list<string> elementsFichier);
	virtual ~GestionMaladies();

private:
	vector<Empreinte>ensembleReference;
	map<string,vector<int>> ensembleMaladies;
	UsineEmpreinte usineEmpreinte;

};

#endif /* GESTIONMALADIES_H_ */

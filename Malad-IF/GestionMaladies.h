/*
 * GestionMaladies.h
 *
 *  Created on: 24 mai 2018
 *      Author: lsilvestri
 */

using namespace std;

#ifndef GESTIONMALADIES_H_
#define GESTIONMALADIES_H_
#include "Empreinte.h"
#include <string>
#include <map>
#include <vector>
#include <list>


class GestionMaladies {

public:

	bool insereDonnees(Empreinte aAjouter);

	bool initialiserApplication(string nomFichierref, string nomFichierMaladies);

	list<string,double> diagnostiquerEmpreinte(Empreinte aAnalyser);

	Empreinte caracteriserMaladie(string nomMaladie);

	list<string> decouperString(string elementFichier);


	//Constructeurs, destructeurs
	GestionMaladies();
	virtual ~GestionMaladies();

private:
	vector<Empreinte>ensembleReference;
	map<string,vector<int>> ensembleMaladies;

};

#endif /* GESTIONMALADIES_H_ */

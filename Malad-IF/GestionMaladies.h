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



class GestionMaladies {

public:

	bool insererDonnees(Empreinte aAjouter,string maladie);

	bool initialiserApplication(string nomFichierref, string nomFichierMaladies);

	list<pair<string,double>> diagnostiquerEmpreinte(Empreinte aAnalyser);

	Empreinte caracteriserMaladie(string nomMaladie);

	list<string> decouperString(string elementFichier);
	
	list<string> listerMaladies();


	//Constructeurs, destructeurs
	GestionMaladies();
	GestionMaladies(list<string> elementsFichier);
	virtual ~GestionMaladies();

protected:
	vector<Empreinte>ensembleReference;
	map<string,vector<unsigned int>> ensembleMaladies;
	UsineEmpreinte usineEmpreinte;
	
	//methodes privees
	vector<vector<string>> readValues(string filename, unsigned int fieldCount, bool skipFirstLine);
	vector<pair<string, string>> readDescription(string filename, bool skipFirstLine);

};

#endif /* GESTIONMALADIES_H_ */

/*************************************************************************
 GestionMaladies  -  description
 -------------------
 start                : 25 mai 2018
 copyright            : (C) 2018 by lsterner
 *************************************************************************/

//---------- Réalisation of the class <GestionMaladies> (fichier GestionMaladies.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- System include
using namespace std;
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "Attribut.h"
#include "AttributDouble.h"
#include "AttributId.h"
#include "AttributString.h"
#include "ValeurId.h"
#include "ValeurDouble.h"
#include "ValeurString.h"
#include "UsineEmpreinte.h"

//------------------------------------------------------ Personal include
#include "GestionMaladies.h"

//--------------------------------------------------------------  Constants

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Public methods

bool GestionMaladies::insererDonnees(Empreinte aAjouter, string maladie)
{
	ensembleReference.insert(ensembleReference.end(), aAjouter);
	map<string, vector<unsigned int>>::iterator mapMaladieItr = ensembleMaladies.find(maladie);
	if (mapMaladieItr != ensembleMaladies.end())
	{

		vector<unsigned int> index = mapMaladieItr->second;
		index.insert(index.end(), ensembleReference.size() - 1);

	}
	else
	{

		vector<int> index;
		index.insert(index.end(), ensembleReference.size() - 1);
		const pair<string, vector<int>> element = make_pair(maladie, index);
		ensembleMaladies.insert(ensembleMaladies.end(), element);
	}

	return true;

}

bool GestionMaladies::initialiserApplication(string nomFichierRef, string nomFichierMeta)
{
	vector<pair<string, string>> desc = readDescription(nomFichierRef, true);

	if (desc.empty()) return false;

	vector<vector<string>> vals = readValues(nomFichierMeta, desc.size() + 1 /* disease */, true);

	if (vals.empty()) return false;

	for (pair<string, string>& paire : desc)
		UsineEmpreinte.creerAttribut(paire);


	for (vector<string> vec : vals)
	{
		vector<string> attr(vec.begin(), vec.end() - 1);
		string maladie = vec[desc.size()];

//		for (unsigned int i = 0; i < desc.size(); i++)
//			em.push_back(attributs[i]->creerValeur(vec[i]));

		Empreinte em = UsineEmpreinte.creerEmpreinte(attr);

		insererDonnees(em, maladie);
	}

//	for (list<Valeur*> em : empreintes)
//	{
//		int i = 0;
//		for (Valeur* valeur : em)
//		{
//
//			// https://stackoverflow.com/questions/500493/c-equivalent-of-instanceof
//			if(ValeurDouble* vd = dynamic_cast<ValeurDouble*>(valeur))
//				cout << attributs[i]->getNom() << "=" <<  *((double*) (vd->getValeur())) << endl;
//
//			if(ValeurId* vi = dynamic_cast<ValeurId*>(valeur))
//				cout << attributs[i]->getNom() << "=" << *((unsigned int*) (vi->getValeur())) << " : " << endl;
//
//			if(ValeurString* vs = dynamic_cast<ValeurString*>(valeur))
//				cout << attributs[i]->getNom() << "=" <<  *((string*) (vs->getValeur())) << endl;
//
//			i++;
//		}
//	}

	for (list<Valeur*> em : empreintes)
	{
		int i = 0;
		for (Valeur* valeur : em)
		{

			i++;
		}
	}

	return true;
}

list<pair<string, double>> GestionMaladies::diagnostiquerEmpreinte(Empreinte aAnalyser)
{
	list<pair<string, double>> l;
	return l; // TODO
}

Empreinte GestionMaladies::caracteriserMaladie(string nomMaladie)
{
//	map<string, vector<int>>::iterator mapMaladieItr = ensembleMaladies.find(nomMaladie);
//	if (mapMaladieItr != ensembleMaladies.end())
//	{
//
//		vector<int> indexEmpreintes = mapMaladieItr->second;
//
//		for (unsigned int i = 0; i < indexEmpreintes.size(); i++)
//		{
//			Empreinte empreinteCourante = ensembleReference[indexEmpreintes[i]];
//
//		}
//
//	}
	list<string> v;
	Empreinte e(v);
	return e; // TODO
}

list<string> GestionMaladies::decouperString(string elementFichier)
{

	list<string> champsLigne;
	string elementCourant;

	stringstream elementFichierStream(elementFichier);

	while (getline(elementFichierStream, elementCourant, ';'))
		champsLigne.push_back(elementCourant);

	return champsLigne;
}

//-------------------------------------------- Constructors - destructor
GestionMaladies::GestionMaladies(const GestionMaladies & unGestionMaladies)
// Algorithme :
//
{
#ifdef MAP
	cout << "Calling copy constructor of <GestionMaladies>" << endl;
#endif
} //----- Fin de GestionMaladies (constructeur de copie)

GestionMaladies::GestionMaladies()
// Algorithme :
//
{
#ifdef MAP
	cout << "Calling constructor of <GestionMaladies>" << endl;
#endif
} //----- Fin de GestionMaladies

GestionMaladies::~GestionMaladies()
// Algorithme :
//
{
#ifdef MAP
	cout << "Calling destructor of <GestionMaladies>" << endl;
#endif
} //----- End of ~GestionMaladies

//----------------------------------------------------------------- PRIVATE

//----------------------------------------------------- Protected methods

vector<pair<string, string>> GestionMaladies::readDescription(string filename, bool skipFirstLine)
{
	ifstream fs;

	vector<pair<string, string>> fileList;
	vector<pair<string, string>> error; // empty vector for error

	fs.open(filename.c_str());
	if (!fs)
	{
		cerr << "Ce fichier de metadonnees est inaccessible." << endl;
		return error;
	}

	string line;

	if (skipFirstLine)
	{
		getline(fs, line);

		if (line != "AttributeName;AttributeType")
		{
			cerr << "Ce fichier de metadonnes est malforme." << endl;
			return error;
		}
	}

	istringstream ss(line);

	pair<string, string> lineFields;
	string current;

	while (fs)
	{
		getline(fs, current, ';');
		lineFields.first = current;

		getline(fs, current, '\r'); // YAY windows shitty CRLF
		lineFields.second = current;

		if (current.find(";"))
		{
			cerr << "Ce fichier de metadonnees contient un \";\" innatendu au vu du format normal." << endl;
			return error;
		}

		getline(fs, current, '\n');

		if (lineFields.first.empty() ^ lineFields.second.empty())
		{
			cerr << "Ce fichier de metadonnees ne peut contenir de champ vide." << endl;
			return error;
		}

		if (lineFields.first.empty() && lineFields.second.empty()) // FIXME : && or || ??
		break; // TODO : test for EOF and if too early, show error accordingly

		fileList.push_back(lineFields);

		lineFields.first.clear();
		lineFields.second.clear();
	}

	return fileList;
}

vector<vector<string>> GestionMaladies::readValues(string filename, unsigned int fieldCount, bool skipFirstLine)
{
	ifstream fs;

	vector<vector<string>> fileList;
	vector<vector<string>> error; // empty vector for error

	fs.open(filename.c_str());
	if (!fs)
	{
		cerr << "Ce fichier de reference est inaccessible." << endl;
		return error;
	}
	string line;

	if (skipFirstLine)
	{
		getline(fs, line);
		if (!line.find(";Disease"))
		{
			cerr << "Ce fichier de reference est malforme." << endl;
			return error;
		}
	}

	istringstream ss(line);

	vector<string> lineFields(fieldCount);
	lineFields.clear();

	string currentLine;

	string currentElement;

	unsigned int i;

//	 https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
	while (fs)
	{
		i = 0;
		while (getline(fs, currentLine, '\r'))
		{
			stringstream currentLineStream(currentLine);

//			while (getline(currentLineStream, currentElement, ';'))
			for (i = 0; i < fieldCount; i++)
			{
				getline(currentLineStream, currentElement, ';');
				lineFields.push_back(currentElement);
				if (currentElement.empty())
				{
					if (i != 0)
						cerr << "Il manque une donnee dans le fichier de reference." << endl;
					else
						cerr << "Il manque un identifiant dans le fichier de reference." << endl;

					return error;
				}

			}

			fileList.push_back(lineFields);

			getline(fs, currentLine);
			lineFields.clear();
		}
	}

	return fileList;
}

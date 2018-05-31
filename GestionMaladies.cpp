/*
 * GestionMaladies.cpp
 *
 *  Created on: 24 mai 2018
 *      Author: lsilvestri
 */
 using namespace std;
#include "GestionMaladies.h"
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


bool GestionMaladies::insererDonnees(Empreinte aAjouter,string maladie){

	ensembleReference.insert(ensembleReference.end(),aAjouter);
	map<string,vector<unsigned int>>::iterator mapMaladieItr= ensembleMaladies.find(maladie);
	if(mapMaladieItr != ensembleMaladies.end()){

		vector<unsigned int>index = mapMaladieItr->second;
		index.insert(index.end(), ensembleReference.size()-1);

	}else{

		vector<unsigned int> index;
		index.insert(index.end(),ensembleReference.size()-1);
		const pair<string,vector<unsigned int>> element = make_pair(maladie,index);
		ensembleMaladies.insert(ensembleMaladies.end(),element);
	}

	return true;
}

bool GestionMaladies::initialiserApplication(string nomFichierRef, string nomFichierMeta)
{
	vector<pair<string, string>> desc = readDescription(nomFichierRef, true);

	if (desc.empty())
		return false;

	vector<vector<string>> vals = readValues(nomFichierMeta, desc.size() + 1 /* disease */, true);

	if (vals.empty())
		return false;

	for (pair<string, string>& paire : desc)
		UsineEmpreinte::creerAttribut(paire);


	for (vector<string> vec : vals)
	{
		list<string> attr(vec.begin(), vec.end() - 1);
		string maladie = vec[desc.size()];

		Empreinte em = UsineEmpreinte::creerEmpreinte(attr);

		insererDonnees(em, maladie);
	}

	return true;
}


Empreinte GestionMaladies::caracteriserMaladie(string nomMaladie){

	map<string,vector<unsigned int>>::iterator mapMaladieItr= ensembleMaladies.find(nomMaladie);
	Empreinte resultat = usineEmpreinte.creerEmpreinte();
	if(mapMaladieItr != ensembleMaladies.end()){
		//TODO : gerer le cas ou la maladie n'a pas d'empreintes associées
		vector<unsigned int> indexEmpreintes = mapMaladieItr->second;


		list<Valeur*> *valeurResult = resultat.getValeurs();
		list<Valeur*>::iterator parcoursResult;
		for(unsigned int i = 0 ; i < indexEmpreintes.size() ; i++){
			Empreinte empreinteCourante = ensembleReference[indexEmpreintes[i]];
			list<Valeur*>*valeursCourantes = empreinteCourante.getValeurs();
			list<Valeur*>::iterator parcours;
			parcoursResult = (*valeurResult).begin();
			for(parcours = valeursCourantes->begin();parcours!= valeursCourantes->end();parcours++){
				//Creation d'un iterateur sur l'empreinte de resultat

				if(ValeurDouble* vd = dynamic_cast<ValeurDouble*>(*parcours))
				{
					//ajout de la valeur à l'empreinte resultat
					double a = *(double*)((*parcoursResult)->getValeur()) + *(double*)((vd)->getValeur());
					void* b = &a;
					(*parcoursResult)->setValeur(b);
				}

				if(ValeurId* vi = dynamic_cast<ValeurId*>(*parcours))
				{
					int a = *(int*)((*parcoursResult)->getValeur())+ *(int*)((vi)->getValeur());
					void* b = &a;
					(*parcoursResult)->setValeur(b);
				}

				if(dynamic_cast<ValeurString*>(*parcours))
				{
					//TODO faire les string
				}
				parcoursResult++;

			}
		}
		//division des valeurs de Result pour avoir une moyenne
		for(parcoursResult = (*valeurResult).begin();parcoursResult!=(*valeurResult).end();parcoursResult++){
			if(dynamic_cast<ValeurId*>(*parcoursResult)){

					int a = (*(int*)((*parcoursResult)->getValeur()))/ensembleReference.size();
					void* b = &a;
					(*parcoursResult)->setValeur(b);
				//**parcoursResult = **parcoursResult/(ensembleReference.size());//On considère que tous les cahamps d'une empreinte sont toujours remplis
			}
			if(dynamic_cast<ValeurDouble*>(*parcoursResult))
				{
					double a = (*(double*)((*parcoursResult)->getValeur()))/ensembleReference.size();
					void* b = &a;
					(*parcoursResult)->setValeur(b);
				}
		}
		return resultat;
	}
	else{
		return resultat;
	}

}

list<pair<string,double>> GestionMaladies::diagnostiquerEmpreinte(Empreinte aAnalyser){
	list<Valeur*> *listeRef = ensembleReference[0].getValeurs();
	int taille = listeRef->size();//TODO verifier EnsRef pas vide
	void* min[taille];
	void* max[taille];
	//initialisation des tableaux min et max
	list<Valeur*>::iterator parcoursVal;
	int j =0;
	for(parcoursVal = listeRef->begin();parcoursVal!=listeRef->end();parcoursVal++)
			{
				min[j] = (*parcoursVal)->getValeur();
				max[j] = (*parcoursVal)->getValeur();
				j++;
			}

	for(unsigned int i=1;i<ensembleReference.size();i++)
	{
		list<Valeur*> * valeurs = ensembleReference[i].getValeurs();
		j=0;
		for(parcoursVal = valeurs->begin();parcoursVal!=valeurs->end();parcoursVal++)
		{
			if(*min[j]> *(*parcoursVal)->getValeur()){
				min[j] = (*parcoursVal)->getValeur();
			}
			if(*max[j]< *(*parcoursVal)->getValeur()){
				max[j] = (*parcoursVal)->getValeur();
			}
		}

	}
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
list<string> GestionMaladies::listerMaladies()
{
//	https://stackoverflow.com/questions/110157/how-to-retrieve-all-keys-or-values-from-a-stdmap-and-put-them-into-a-vector

	list<string> cles;
	for (pair<string,vector<unsigned int>> p : ensembleMaladies)
		cles.push_back(p.first);
	return cles;
}


GestionMaladies::GestionMaladies() {
	//TODO : Faire une classe abstraite.

}


GestionMaladies::~GestionMaladies() {
	// TODO Auto-generated destructor stub
}

// des méthodes privées
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

		if (line.find("AttributeName;AttributeType"))
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

		if (! current.find(";"))
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
//	while (fs)
//	{
		while (getline(fs, currentLine, '\r'))
		{
			stringstream currentLineStream(currentLine);

//			while (getline(currentLineStream, currentElement, ';'))
			for (i = 0; i < fieldCount; i++)
			{
				getline(currentLineStream, currentElement, ';');
				lineFields.push_back(currentElement);

				if (currentElement.empty() && i < (fieldCount-1))
				{
					if (i == 0)
						cerr << "Il manque un identifiant dans le fichier de reference." << endl;
					else
						cerr << "Il manque une donnee dans le fichier de reference." << endl;

					return error;
				}

			}

			fileList.push_back(lineFields);

			getline(fs, currentLine);
			lineFields.clear();
		}
//	}

	return fileList;
}

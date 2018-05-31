/*************************************************************************
UsineEmpreinte permet de construire des empreintes � partir des donn�es fichier.
-------------------
d�but                : 04/2018
copyright            : (C) 2018 par B3344
*************************************************************************/

//---------- R�alisation de la classe <UsineEmpreinte> (fichier UsineEmpreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <list>
#include <array>
#include <string>

//------------------------------------------------------ Include personnel
#include "UsineEmpreinte.h"
#include "Valeur.h"
#include "Attribut.h"
#include "AttributDouble.h"
#include "AttributString.h"
#include "AttributId.h"
#include "stdio.h"
#include <iostream>

using namespace std;

//----------------------------------------------------------------- PUBLIC

vector<Attribut*> UsineEmpreinte::formatEmpreinte;



//----------------------------------------------------- M�thodes publiques
string UsineEmpreinte::recupererIntituleAttribut(int numAttribut) {
	return formatEmpreinte[numAttribut]->getNom();
}

Empreinte UsineEmpreinte::creerEmpreinte(list<string> elementsFichier) {

	list<Valeur*> listVal;
	list<string>::iterator parcours = elementsFichier.begin();
	for (unsigned int i = 0; i < elementsFichier.size(); i++) {

		Valeur* val = formatEmpreinte[i]->creerValeur(*parcours);
		listVal.insert(listVal.end(),val);
		parcours++;
	}

	Empreinte em = Empreinte(listVal);
	return em;
}

Empreinte UsineEmpreinte::creerEmpreinte(){
	list<Valeur*> listVal;
	for(unsigned int i =0;i<formatEmpreinte.size();i++){
		Valeur* val = formatEmpreinte[i]->creerValeur(0);
		listVal.insert(listVal.end(),val);
	}
	Empreinte em = Empreinte(listVal);
	return em;
}
void UsineEmpreinte::creerAttribut(pair<string, string> elementsFichier) {

	if(elementsFichier.second == "int") {

		Attribut* att = new AttributId(elementsFichier.first);
		formatEmpreinte.insert(formatEmpreinte.end(),att);

	}else if(elementsFichier.second == "double"){

		Attribut* att = new AttributDouble(elementsFichier.first);
		formatEmpreinte.insert(formatEmpreinte.end(),att);

	}else if(elementsFichier.second == "string"){

		Attribut* att = new AttributString(elementsFichier.first);
		formatEmpreinte.insert(formatEmpreinte.end(),att);

	}else if(elementsFichier.second == "ID"){

		Attribut* att =  new AttributId(elementsFichier.first);
		formatEmpreinte.insert(formatEmpreinte.end(),att);

	}

}


Empreinte UsineEmpreinte::moyenner(list<Empreinte> empreintes)
{
	list<list<Valeur*>> valeursParAttribut;
	for (unsigned int i = 0; i < formatEmpreinte.size(); i++)
	{
		list<Valeur*> l;
		valeursParAttribut.push_back(l);
	}

	list<Valeur*> valeurMoyennees;

	list<Empreinte>::iterator itEmpreintes;
	list<list<Valeur*>>::iterator itValeursParAttribut;



	for (itEmpreintes = empreintes.begin(); itEmpreintes != empreintes.end(); itEmpreintes++)
	{
		list<Valeur*> valeurs = *(itEmpreintes->getValeurs());
		list<Valeur*>::iterator itValeurs = valeurs.begin();

		itValeursParAttribut = valeursParAttribut.begin();

		for(unsigned int i = 0; i < formatEmpreinte.size(); i++, itValeurs++, itValeursParAttribut++)
			itValeursParAttribut->push_back(*itValeurs);
	}

	itValeursParAttribut = valeursParAttribut.begin();

	for(unsigned int i = 0; i < formatEmpreinte.size(); i++, itValeursParAttribut++)
		valeurMoyennees.push_back(formatEmpreinte[i]->moyenner(*itValeursParAttribut));

	Empreinte e(valeurMoyennees);






	int at = 0;
	for (Valeur* valeur : *(e.getValeurs()))
	{

		// https://stackoverflow.com/questions/500493/c-equivalent-of-instanceof
		if(ValeurDouble* vd = dynamic_cast<ValeurDouble*>(valeur))
			cout << formatEmpreinte[at]->getNom() << "=" <<  *((double*) (vd->getValeur())) << endl;

		if(ValeurId* vi = dynamic_cast<ValeurId*>(valeur))
			cout << formatEmpreinte[at]->getNom() << "=" << *((unsigned int*) (vi->getValeur())) << " : " << endl;

		if(ValeurString* vs = dynamic_cast<ValeurString*>(valeur))
			cout << formatEmpreinte[at]->getNom() << "=" <<  *((string*) (vs->getValeur())) << endl;

		at++;
	}



	return e;
}




//-------------------------------------------- Constructeurs - destructeur
UsineEmpreinte::UsineEmpreinte() {
	
}

UsineEmpreinte::~UsineEmpreinte()
{
	
}
//----- Fin de ~UsineEmpreinte

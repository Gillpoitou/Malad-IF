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
#include <string>

//------------------------------------------------------ Include personnel
#include "UsineEmpreinte.h"
#include "Valeur.h"
#include "Attribut.h"
#include "AttributDouble.h"
#include "AttributString.h"
#include "AttributId.h"
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
string UsineEmpreinte::recupererIntituleAttribut(int numAttribut) {
	return formatEmpreinte[numAttribut]->getNom();

}
void UsineEmpreinte::creerAttribut(pair<string, string> elementsFichier) {
	switch (elementsFichier.first) {
	case "int": 
		Attribut* att = new AttributId(elementsFichier.second);
		formatEmpreinte.insert(formatEmpreinte.end(),att);
		break;
	case "double":
		Attribut* att = new AttributDouble(elementsFichier.second);
		formatEmpreinte.insert(formatEmpreinte.end(),att);
		break;
	case "string":
		Attribut* att = new AttributString(elementsFichier.second);
		formatEmpreinte.insert(formatEmpreinte.end(),att);
		break;
	case "ID":
		Attribut* att =  new AttributId(elementsFichier.second);
		formatEmpreinte.insert(formatEmpreinte.end(),att);
		break;
	}

}
Empreinte UsineEmpreinte::creerEmpreinte(list<string> elementsFichier) {

	list<Valeur> listVal;

	for (int i = 0; i < elementsFichier.size(); i++) {

		Valeur val = formatEmpreinte[i]->creerValeur(elementsFichier[i]);
		listVal.insert(listVal.end(),val);
	}

	Empreinte em = Empreinte(listVal);
	return em;
}

//-------------------------------------------- Constructeurs - destructeur
UsineEmpreinte::UsineEmpreinte() {
	
}
UsineEmpreinte::~UsineEmpreinte()
{
	
}
//----- Fin de ~UsineEmpreinte

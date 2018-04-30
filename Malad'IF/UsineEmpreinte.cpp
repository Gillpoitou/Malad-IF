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
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
string UsineEmpreinte::recupererIntituleAttribut(int numAttribut) {
	return formatEmpreinte[numAttribut].nom;
}
void UsineEmpreinte::creerAttribut(pair<string, string> elementsFichier) {
	switch (elementsFichier.first) {
	case "int": 
		Attribut att = Attribut<int>(elementsFichier.second);
		formatEmpreinte.add(att);
		break;
	case "double":
		Attribut att = Attribut<double>(elementsFichier.second);
		formatEmpreinte.add(att);
		break;
	case "string":
		Attribut att = Attribut<string>(elementsFichier.second);
		formatEmpreinte.add(att);
		break;
	case "ID":
		Attribut att =  Attribut<int>(elementsFichier.second);
		formatEmpreinte.add(att);
		break;
	}

}
Empreinte UsineEmpreinte::creerEmpreinte(list<string> elementsFichier) {

	list<Valeur> listVal;

	for (int i = 0; i < elementsFichier.size(); i++) {

		Valeur val = formatEmpreinte[i].creerValeur(elementsFichier[i]);
		listVal.add(val);
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

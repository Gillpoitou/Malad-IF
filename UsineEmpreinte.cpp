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

	if(elementsFichier.first == "int") {

		Attribut* att = new AttributId(elementsFichier.second);
		formatEmpreinte.insert(formatEmpreinte.end(),att);

	}else if(elementsFichier.first == "double"){

		Attribut* att = new AttributDouble(elementsFichier.second);
		formatEmpreinte.insert(formatEmpreinte.end(),att);

	}else if(elementsFichier.first == "string"){

		Attribut* att = new AttributString(elementsFichier.second);
		formatEmpreinte.insert(formatEmpreinte.end(),att);

	}else if(elementsFichier.first == "ID"){

		Attribut* att =  new AttributId(elementsFichier.second);
		formatEmpreinte.insert(formatEmpreinte.end(),att);

	}

}


//-------------------------------------------- Constructeurs - destructeur
UsineEmpreinte::UsineEmpreinte() {
	
}

UsineEmpreinte::~UsineEmpreinte()
{
	
}
//----- Fin de ~UsineEmpreinte

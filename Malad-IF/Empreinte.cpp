/*************************************************************************
Empreinte contenant une liste d'attributs.
-------------------
d�but                : 04/2018
copyright            : (C) 2018 par B3344
*************************************************************************/

//---------- R�alisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------
using namespace std;
//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <list>

//------------------------------------------------------ Include personnel
#include "Empreinte.h"

//----------------------------------------------------------------- PUBLIC


//----------------------------------------------------- M�thodes publiques

//-------------------------------------------- Constructeurs - destructeur

Empreinte::Empreinte(list<Valeur*> desvaleurs)
{
	list<Valeur*>::iterator parcours ;
	for(parcours= desvaleurs.begin(); parcours != desvaleurs.end(); parcours++){
		valeurs.insert(valeurs.end(),*parcours);
	}
}
Empreinte::Empreinte(const Empreinte &uneEmpreinte)
{
	list <Valeur*>desvaleurs = uneEmpreinte.valeurs;
	list<Valeur*>::iterator parcours ;
	for(parcours= desvaleurs.begin(); parcours != desvaleurs.end(); parcours++){
		valeurs.insert(valeurs.end(),*parcours);
	}
}
Empreinte::~Empreinte()
{
} //----- Fin de ~Empreinte

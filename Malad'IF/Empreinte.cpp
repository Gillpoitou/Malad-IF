/*************************************************************************
Empreinte contenant une liste d'attributs.
-------------------
d�but                : 04/2018
copyright            : (C) 2018 par B3344
*************************************************************************/

//---------- R�alisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <list>
using namespace std
//------------------------------------------------------ Include personnel
#include "Empreinte.h"
#include "Valeur"
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

//-------------------------------------------- Constructeurs - destructeur

Empreinte::Empreinte(list<Valeur> desvaleurs)
{
	valeurs = desvaleurs;
}
Empreinte::Empreinte(Empreinte &uneEmpreinte)
{
	valeurs = uneEmpreinte.valeurs;
}
Empreinte::~Empreinte()
{
} //----- Fin de ~Empreinte
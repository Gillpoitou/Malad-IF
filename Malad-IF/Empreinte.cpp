/*************************************************************************
Empreinte contenant une liste d'attributs.
-------------------
début                : 04/2018
copyright            : (C) 2018 par B3344
*************************************************************************/

//---------- Réalisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <list>
using namespace std
//------------------------------------------------------ Include personnel
#include "Empreinte.h"
#include "Valeur"
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

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
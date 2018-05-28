/*************************************************************************
Empreinte contenant une liste d'attributs.
-------------------
d�but                : 04/2018
copyright            : (C) 2018 par B3344
*************************************************************************/

//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( EMPREINTE_H )
#define Empreinte_H
using namespace std;
//--------------------------------------------------- Interfaces utilis�es
#include <list>
#include "Valeur.h"


class Empreinte
{
	//----------------------------------------------------------------- PUBLIC

public:	
	//----------------------------------------------------- M�thodes publiques
	//Contrat
	//
	//mode d'emploi

	
	//-------------------------------------------- Constructeurs - destructeurs
	Empreinte(list <Valeur*> desValeurs);

	Empreinte(const Empreinte &uneEmpreinte);
	
	virtual ~Empreinte();
	//------------------------------------------PROTECTED
protected:
	list <Valeur*> valeurs;
};
#endif // Empreinte_H

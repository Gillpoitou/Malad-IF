/*************************************************************************
UsineUsineEmpreinte contenant une liste d'attributs.
-------------------
d�but                : 04/2018
copyright            : (C) 2018 par B3344
*************************************************************************/

//---------- Interface de la classe <UsineEmpreinte> (fichier UsineEmpreinte.h) ----------------
#if ! defined ( USINEEMPREINTE_H )
#define USINEEMPREINTE_H

//--------------------------------------------------- Interfaces utilis�es
using namespace std;
#include <vector>
#include <string>
#include "Attribut.h"
#include "Empreinte.h"

class UsineEmpreinte
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	static void creerAttribut(pair<string,string> elementsFichier);
	//Ajoute un attribut du type ElementsFichier.first et dont le nom est ElementsFichier.second

	static Empreinte creerEmpreinte(list<string> elementsFichier);
	//Cr�er une empreinte � partir d'une liste de valeurs
	static string recupererIntituleAttribut(int numAttribut);
	//Permet de r�cup�rer le nom d'un attribut en utilisant son index
	//----------------------------------------------------Constructeurs-Destructeur
	UsineEmpreinte();
	virtual ~UsineEmpreinte();

	//------------------------------------------PROTECTED
protected:
	static vector<Attribut*> formatEmpreinte;

};
#endif // USINEEMPREINTE_H

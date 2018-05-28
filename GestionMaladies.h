/*************************************************************************
 GestionMaladies  -  description
 -------------------
 start                : 25 mai 2018
 copyright            : (C) 2018 by lsterner
 *************************************************************************/

//---------- Interface of the class <GestionMaladies> (fichier GestionMaladies.h) ------
#if ! defined ( GESTIONMALADIES_H_ )
#define GESTIONMALADIES_H_

//--------------------------------------------------- Used interfaces
#include <list>
#include <map>
#include <vector>

#include "Empreinte.h"

using namespace std;


//------------------------------------------------------------- Constants 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle of the class <GestionMaladies>
//
//
//------------------------------------------------------------------------ 

class GestionMaladies
{
//----------------------------------------------------------------- PUBLIC
		
	public:
//----------------------------------------------------- Public methods
		bool insererDonnees(Empreinte aAjouter, string maladie);
		bool initialiserApplication(string nomFichierRef, string nomFichierMeta);
		list<pair<string, double>> diagnostiquerEmpreinte(Empreinte aAnalyser);
		Empreinte caracteriserMaladie(string nomMaladie);
		list<string> decouperString(string elementFichier);
		
		
//-------------------------------------------- Constructors - destructor
		GestionMaladies(const GestionMaladies & unGestionMaladies);
		// Mode d'emploi (constructeur de copie) :
		//
		// Contrat :
		//
		
		GestionMaladies();
		// Mode d'emploi :
		//
		// Contrat :
		//
		
		virtual ~GestionMaladies();
		// Mode d'emploi :
		//
		// Contrat :
		//
		
//------------------------------------------------------------------ PRIVATE 
		
	protected:
//----------------------------------------------------- Protected fields
		vector<Empreinte> ensembleReference;
		map<string, list<unsigned int>> ensembleMaladies;

//----------------------------------------------------- Private methods
		vector<vector<string>> readValues(string filename, unsigned int fieldCount, bool skipFirstLine);
		vector<pair<string, string>> readDescription(string filename, bool skipFirstLine);

};


//--------------------------- Other independant definitions for <GestionMaladies>

#endif // GESTIONMALADIES_H_

/*************************************************************************
                           StringValeur  -  description
                             -------------------
    start                : 24 mai 2018
    copyright            : (C) 2018 by lsterner
*************************************************************************/

//---------- Interface of the class <StringValeur> (fichier StringValeur.h) ------
#if ! defined ( VALEURSTRING_H_ )
#define VALEURSTRING_H_

//--------------------------------------------------- Used interfaces
#include <string>

#include "Valeur.h"


using namespace std;


//------------------------------------------------------------- Constants 


//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle of the class <StringValeur>
//
//
//------------------------------------------------------------------------ 

class ValeurString : public Valeur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public methods
	string* getValeur();
	// Mode d'emploi :
	//
	// Contrat :
	//



//-------------------------------------------- Constructors - destructor

	ValeurString(string val);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ValeurString ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVATE 

protected:
//----------------------------------------------------- Protected methods
    string* valeur;
//----------------------------------------------------- Private methods

};

//--------------------------- Other independant definitions for <StringValeur>

#endif // VALEURSTRING_H_

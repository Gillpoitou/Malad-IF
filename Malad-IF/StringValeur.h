/*************************************************************************
                           StringValeur  -  description
                             -------------------
    start                : 24 mai 2018
    copyright            : (C) 2018 by lsterner
*************************************************************************/

//---------- Interface of the class <StringValeur> (fichier StringValeur.h) ------
#if ! defined ( STRINGVALEUR_H_ )
#define STRINGVALEUR_H_

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

class StringValeur : public Valeur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public methods
	void* getValeur();
	// Mode d'emploi :
	//
	// Contrat :
	//



//-------------------------------------------- Constructors - destructor

	StringValeur(string val);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~StringValeur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVATE 

protected:
//----------------------------------------------------- Protected methods

//----------------------------------------------------- Private methods

};

//--------------------------- Other independant definitions for <StringValeur>

#endif // STRINGVALEUR_H_

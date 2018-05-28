/*************************************************************************
                           Id  -  description
                             -------------------
    start                : 24 mai 2018
    copyright            : (C) 2018 by lsterner
*************************************************************************/

//---------- Interface of the class <Id> (fichier Id.h) ------
#if ! defined ( ATTRIBUTID_H_ )
#define ATTRIBUTID_H_

//--------------------------------------------------- Used interfaces
#include <string>

#include "Attribut.h"

using namespace std;
//------------------------------------------------------------- Constants 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle of the class <Id>
//
//
//------------------------------------------------------------------------ 

class AttributId : public Attribut
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public methods
	Valeur* creerValeur(string);
	// Mode d'emploi :
	//
	// Contrat :
	//




//-------------------------------------------- Constructors - destructor


	AttributId(string name);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AttributId ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVATE 

protected:
//----------------------------------------------------- Protected methods

//----------------------------------------------------- Private methods

};

//--------------------------- Other independant definitions for <Id>

#endif // ATTRIBUTID_H_

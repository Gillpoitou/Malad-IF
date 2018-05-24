/*************************************************************************
                           Id  -  description
                             -------------------
    start                : 24 mai 2018
    copyright            : (C) 2018 by lsterner
*************************************************************************/

//---------- Interface of the class <Id> (fichier Id.h) ------
#if ! defined ( ID_H_ )
#define ID_H_

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

class Id : public Attribut
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public methods
	Valeur* convert(string);
	// Mode d'emploi :
	//
	// Contrat :
	//




//-------------------------------------------- Constructors - destructor


	Id(string name);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Id ( );
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

#endif // ID_H_

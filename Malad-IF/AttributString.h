/*************************************************************************
                           String  -  description
                             -------------------
    start                : 24 mai 2018
    copyright            : (C) 2018 by lsterner
*************************************************************************/

//---------- Interface of the class <String> (fichier String.h) ------
#if ! defined ( ATTRIBUTSTRING_H_ )
#define ATTRIBUTSTRING_H_

//--------------------------------------------------- Used interfaces
#include <string>

#include "Attribut.h"
#include "ValeurString.h"

using namespace std;
//------------------------------------------------------------- Constants 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle of the class <String>
//
//
//------------------------------------------------------------------------ 

class AttributString : public Attribut
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public methods
	Valeur* creerValeur(string);
	// Mode d'emploi :
	//
	// Contrat :
	//

	ValeurString* moyenner(list<Valeur*>);

//------------------------------------------------- Operator overload


//-------------------------------------------- Constructors - destructor

	AttributString(string name);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AttributString ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVATE 

protected:
//----------------------------------------------------- Protected methods

//----------------------------------------------------- Private methods

};

//--------------------------- Other independant definitions for <String>

#endif // ATTRIBUTSTRING_H_

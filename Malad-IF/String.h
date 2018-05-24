/*************************************************************************
                           String  -  description
                             -------------------
    start                : 24 mai 2018
    copyright            : (C) 2018 by lsterner
*************************************************************************/

//---------- Interface of the class <String> (fichier String.h) ------
#if ! defined ( STRING_H_ )
#define STRING_H_

//--------------------------------------------------- Used interfaces
#include <string>

#include "Attribut.h"
#include "StringValeur.h"

using namespace std;
//------------------------------------------------------------- Constants 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle of the class <String>
//
//
//------------------------------------------------------------------------ 

class String : public Attribut
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public methods
	Valeur* convert(string);
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------- Operator overload


//-------------------------------------------- Constructors - destructor

	String(string name);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~String ( );
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

#endif // STRING_H_

/*************************************************************************
                           Double  -  description
                             -------------------
    start                : 24 mai 2018
    copyright            : (C) 2018 by lsterner
*************************************************************************/

//---------- Interface of the class <Double> (fichier Double.h) ------
#if ! defined ( ATTRIBUTDOUBLE_H_ )
#define ATTRIBUTDOUBLE_H_

//--------------------------------------------------- Used interfaces

#include <string>

#include "Attribut.h"
#include "DoubleValeur.h"

using namespace std;

//------------------------------------------------------------- Constants 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle of the class <Double>
//
//
//------------------------------------------------------------------------ 

class AttributDouble : public Attribut
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


	AttributDouble(string name);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AttributDouble ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVATE 

protected:
//----------------------------------------------------- Protected methods

//----------------------------------------------------- Private methods

};

//--------------------------- Other independant definitions for <Double>

#endif // ATTRIBUTDOUBLE_H_

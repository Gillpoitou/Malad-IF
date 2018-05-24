/*************************************************************************
                           Double  -  description
                             -------------------
    start                : 24 mai 2018
    copyright            : (C) 2018 by lsterner
*************************************************************************/

//---------- Interface of the class <Double> (fichier Double.h) ------
#if ! defined ( DOUBLE_H_ )
#define DOUBLE_H_

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

class Double : public Attribut
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


	Double(string name);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Double ( );
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

#endif // DOUBLE_H_

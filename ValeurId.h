/*************************************************************************
                           IdValeur  -  description
                             -------------------
    start                : 24 mai 2018
    copyright            : (C) 2018 by lsterner
*************************************************************************/

//---------- Interface of the class <IdValeur> (fichier IdValeur.h) ------
#if ! defined ( VALEURID_H_ )
#define VALEURID_H_

//--------------------------------------------------- Used interfaces
#include <string>

#include "Valeur.h"


using namespace std;

//------------------------------------------------------------- Constants 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle of the class <IdValeur>
//
//
//------------------------------------------------------------------------ 

class ValeurId : public Valeur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public methods
	unsigned int* getValeur();
	// Mode d'emploi :
	//
	// Contrat :
	//




//-------------------------------------------- Constructors - destructor
    ValeurId ( const ValeurId & unIdValeur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ValeurId(unsigned int valeur);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ValeurId ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVATE 

protected:
//----------------------------------------------------- Protected methods
    unsigned int* valeur;
//----------------------------------------------------- Private methods

};

//--------------------------- Other independant definitions for <IdValeur>

#endif // VALEURID_H_

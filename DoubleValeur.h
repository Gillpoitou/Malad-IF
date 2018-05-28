/*************************************************************************
                           DoubleValeur  -  description
                             -------------------
    start                : 24 mai 2018
    copyright            : (C) 2018 by lsterner
*************************************************************************/

//---------- Interface of the class <DoubleValeur> (fichier DoubleValeur.h) ------
#if ! defined ( DOUBLEVALEUR_H_ )
#define DOUBLEVALEUR_H_

//--------------------------------------------------- Used interfaces
#include "Valeur.h"
//------------------------------------------------------------- Constants 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle of the class <DoubleValeur>
//
//
//------------------------------------------------------------------------ 

class DoubleValeur : public Valeur
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

	DoubleValeur(double val);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~DoubleValeur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVATE 

protected:

//----------------------------------------------------- Protected methods

//----------------------------------------------------- Private methods

};

//--------------------------- Other independant definitions for <DoubleValeur>

#endif // DOUBLEVALEUR_H_

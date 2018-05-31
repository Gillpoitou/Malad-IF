/*************************************************************************
                           DoubleValeur  -  description
                             -------------------
    start                : 24 mai 2018
    copyright            : (C) 2018 by lsterner
*************************************************************************/

//---------- Interface of the class <DoubleValeur> (fichier DoubleValeur.h) ------
#if ! defined ( VALEURDOUBLE_H_ )
#define VALEURDOUBLE_H_

//--------------------------------------------------- Used interfaces
#include "Valeur.h"
//------------------------------------------------------------- Constants 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle of the class <DoubleValeur>
//
//
//------------------------------------------------------------------------ 

class ValeurDouble : public Valeur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public methods
    void* getValeur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void setValeur(void* val);



//-------------------------------------------- Constructors - destructor

	ValeurDouble(double val);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ValeurDouble ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVATE 

protected:
//----------------------------------------------------- Protected fields
    double* valeur;

//----------------------------------------------------- Private methods

};

//--------------------------- Other independant definitions for <DoubleValeur>

#endif // VALEURDOUBLE_H_

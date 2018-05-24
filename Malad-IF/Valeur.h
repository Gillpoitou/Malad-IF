/*************************************************************************
                           Valeur  -  description
                             -------------------
    start                : 24 mai 2018
    copyright            : (C) 2018 by lsterner
*************************************************************************/

//---------- Interface of the class <Valeur> (fichier Valeur.h) ------
#if ! defined ( VALEUR_H_ )
#define VALEUR_H_

//--------------------------------------------------- Used interfaces

#include <string>

using namespace std;

//------------------------------------------------------------- Constants 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle of the class <Valeur>
//
//
//------------------------------------------------------------------------ 

class Valeur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public methods
	virtual void* getValeur() = 0;
	// Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Operator overload
//    Valeur & operator = ( const Valeur & unValeur );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructors - destructor
//    Valeur ( const Valeur & unValeur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

//    Valeur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //



    virtual ~Valeur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVATE 

protected:
//----------------------------------------------------- Protected fields
    void* valeur;

//----------------------------------------------------- Private methods

};

//--------------------------- Other independant definitions for <Valeur>

#endif // VALEUR_H_

/*************************************************************************
                           Attribut  -  description
                             -------------------
    start                : 24 mai 2018
    copyright            : (C) 2018 by lsterner
*************************************************************************/

//---------- Interface of the class <Attribut> (fichier Attribut.h) ------
#if ! defined ( ATTRIBUT_H_ )
#define ATTRIBUT_H_

//--------------------------------------------------- Used interfaces
#include <string>

#include "Valeur.h"
//------------------------------------------------------------- Constants 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle of the class <Attribut>
//
//
//------------------------------------------------------------------------ 

class Attribut
{
//----------------------------------------------------------------- PUBLIC

public:
// ------------------------------------------------------------- Methods

	virtual Valeur* creerValeur(string) = 0;

	string getNom();
//-------------------------------------------- Constructors - destructor
    Attribut ( const Attribut & unAttribut );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

	Attribut(string nom);

//    Attribut ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Attribut ( ) = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVATE 

protected:
//----------------------------------------------------- Protected methods
    string nom;

//----------------------------------------------------- Private methods

};

//--------------------------- Other independant definitions for <Attribut>

#endif // ATTRIBUT_H_

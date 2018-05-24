/*************************************************************************
                           IdValeur  -  description
                             -------------------
    start                : 24 mai 2018
    copyright            : (C) 2018 by lsterner
*************************************************************************/

//---------- Interface of the class <IdValeur> (fichier IdValeur.h) ------
#if ! defined ( IDVALEUR_H_ )
#define IDVALEUR_H_

//--------------------------------------------------- Used interfaces

//------------------------------------------------------------- Constants 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle of the class <IdValeur>
//
//
//------------------------------------------------------------------------ 

class IdValeur : public Valeur
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
    IdValeur ( const IdValeur & unIdValeur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    IdValeur(unsigned int valeur);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~IdValeur ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVATE 

protected:
//----------------------------------------------------- Protected methods

//----------------------------------------------------- Private methods

};

//--------------------------- Other independant definitions for <IdValeur>

#endif // IDVALEUR_H_

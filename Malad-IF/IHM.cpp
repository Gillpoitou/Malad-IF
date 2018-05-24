/*************************************************************************
                           IHM  -  description
                             -------------------
    debut                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Realisation du module <IHM> (fichier IHM.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

//------------------------------------------------------ Include personnel
#include "IHM.h"


//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

IHM::IHM()
{
}

IHM::~IHM()
{
}

void IHM::Menu ()
{
	string saisieUtilisateur;

	/*** Initialisation ***/

	cout << "/*** Initialisation de l'application ***/" << endl;
    cout << endl;
	cout << "Veuillez indiquez le nom du fichier de metadonnees souhaite : " << endl;
    cout << endl;
	cout << "Veuillez indiquez le nom du fichier de reference souhaite : " << endl;
    cout << endl;
	cout << "/*** Initialisation des donnees en cours, merci de patienter ... ***/" << endl;
    cout << endl;
	/*** Connexion ***/

	cout << "/*** Connexion de l'utilisateur ***/" << endl;
    cout << endl;
	cout << "Veuillez saisir votre nom d'utilisateur : " << endl;
    cout << endl;
	cout << "Veuillez saisir votre mot de passe : " << endl;
    cout << endl;
	/*** Menu Principal ***/

    cout << "/*** Menu ***/" << endl;
    cout << endl;
    cout << setw(45) << left << "Pour analyser des empreintes:" << setw(10) << right << "saisir 1." << endl;
    cout << setw(45) << left << "Pour caracteriser une maladie:" <<  setw(10) << right << "saisir 2." << endl;
    cout << setw(45) << left << "Pour vous deconnecter:" <<  setw(10) << right << "saisir 3." << endl;
    cout << setw(45) << left << "Pour afficher le manuel d'utilisation :" <<  setw(10) << right << "saisir 4." << endl;
    cout << setw(45) << left << "Pour quitter l'application:" << setw(10) << right << "saisir 5." << endl;
    cout << endl;
	getline(cin, saisieUtilisateur);
	cout << endl;

	while(saisieUtilisateur.compare("5")!=0)// la saisie de 5 ferme le menu
	{
		if ((saisieUtilisateur.compare("1")!=0) && (saisieUtilisateur.compare("2")!=0)&& (saisieUtilisateur.compare("3")!=0)&& (saisieUtilisateur.compare("4")!=0))
		{ // On verifie que la saisie de l'utilisateur est un sens pour l'application.
			cout << "Votre saisie n'a pas ete comprise, merci de la reeffectuer (1:Analyser des empreintes, 2:Caracteriser une maladie, 3:Deconnecter l'utilisateur, 4:Afficher le manuel, 5:Quitter)." << endl;
			getline(cin, saisieUtilisateur);
		}
		else
		{
			if (saisieUtilisateur.compare("1")==0)
			{
				cout << "/*** Analyse d'empreinte(s) ***/" << endl;
			}
			if (saisieUtilisateur.compare("2")==0)
			{
				cout << "/*** Caracterisation d'une maladie ***/" << endl;
			}
			if (saisieUtilisateur.compare("3")==0)
			{
				cout << "/*** Deconnexion de l'utilisateur ***/" << endl;
			}
			if (saisieUtilisateur.compare("4")==0)
			{
				cout << "/*** Affichage du manuel ***/" << endl;
			}
			cout << endl;
			cout << "/*** Menu ***/" << endl;
			cout << endl;
            cout << setw(45) << left << "Pour analyser des empreintes:" << setw(10) << right << "saisir 1." << endl;
            cout << setw(45) << left << "Pour caracteriser une maladie:" <<  setw(10) << right << "saisir 2." << endl;
            cout << setw(45) << left << "Pour vous deconnecter:" <<  setw(10) << right << "saisir 3." << endl;
            cout << setw(45) << left << "Pour afficher le manuel d'utilisation :" <<  setw(10) << right << "saisir 4." << endl;
            cout << setw(45) << left << "Pour quitter l'application:" << setw(10) << right << "saisir 5." << endl;
            cout << endl;
			getline(cin, saisieUtilisateur);
			cout << endl;
		}

	}

	/*** Fermeture de l'application ***/

	cout << "/*** Fermeture de l'application ***/" << endl;
}

int main()
{
	IHM interface;
	interface.Menu();
	return 1;
}

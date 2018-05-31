
#include "AttributId.h"

#include <string>
#include <iostream>
#include "ValeurId.h"
using namespace std;


AttributId::AttributId(string name): Attribut(name)
{}

Valeur* AttributId::creerValeur(string valeur)
{
	unsigned int i = stoi(valeur);
	return new ValeurId(i);
}

AttributId::~AttributId()
{}

ValeurId* AttributId::moyenner(list<Valeur*> valeurs)
{
	unsigned int sum = 0;

	for (Valeur* valeur : valeurs)
	{
		ValeurId* vi = dynamic_cast<ValeurId*>(valeur);

		sum += *(vi->getValeur());
	}

	sum /= valeurs.size();

	return new ValeurId(sum); // TODO
}

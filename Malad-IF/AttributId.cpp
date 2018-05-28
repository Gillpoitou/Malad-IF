
#include "AttributId.h"

#include <string>

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

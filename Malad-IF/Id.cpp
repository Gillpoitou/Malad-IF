
#include <string>

#include "Id.h"
#include "IdValeur.h"
using namespace std;


Id::Id(string name): Attribut(name)
{}

Valeur* Id::convert(string valeur)
{
	unsigned int i = stoi(valeur);
	return new IdValeur(i);
}

Id::~Id()
{}

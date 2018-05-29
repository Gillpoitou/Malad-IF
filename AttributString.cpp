#include "AttributString.h"
#include "ValeurString.h"


using namespace std;

AttributString::AttributString(string name): Attribut(name)
{}

Valeur* AttributString::creerValeur(string val)
{
	return new ValeurString(val);
}

AttributString::~AttributString()
{}

#include "Double.h"


Double::Double(string name): Attribut(name)
{}

Valeur* Double::convert(string val)
{
	double d = stod(val);
	return new DoubleValeur(d);
}

Double::~Double()
{}

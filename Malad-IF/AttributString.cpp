#include "AttributString.h"

using namespace std;

AttributString::AttributString(string name): Attribut(name)
{}

Valeur* AttributString::convert(string val)
{
	return new StringValeur(val);
}

AttributString::~AttributString()
{}

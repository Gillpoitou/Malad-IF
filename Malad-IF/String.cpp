#include "String.h"

using namespace std;

String::String(string name): Attribut(name)
{}

Valeur* String::convert(string val)
{
	return new StringValeur(val);
}

String::~String()
{}

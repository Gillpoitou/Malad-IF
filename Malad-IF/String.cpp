
#include <string>

#include "Attribute.cpp"
#include "StringValeur.cpp"

using namespace std;

#if ! defined ( STRING_H_ )
#define STRING_H_


class String : public Attribut
{
	public:

		String(string name): Attribut(name)
		{
			;
		}

		Valeur* convert(string val)
		{
			return new StringVal(val);
		}

		virtual ~String()
		{
			;
		}
};

#endif // STRING_H_

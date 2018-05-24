#include <string>

#include "Valeur.cpp"

using namespace std;

#if ! defined ( HANDLEDTYPE_H_ )
#define HANDLEDTYPE_H_


class Attribut
{
	public:
		Attribut(string name)
		{
			this->name = name;
		}

		virtual ~Attribut()
		{
		}

		virtual Valeur* convert(string) = 0;

	protected:
		string name;
};

#endif // HANDLEDTYPE_H_

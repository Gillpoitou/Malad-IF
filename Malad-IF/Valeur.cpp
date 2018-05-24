#include <string>

using namespace std;

#if ! defined ( VALUE_H_ )
#define VALUE_H_


class Valeur
{

	public:
		virtual ~Valeur()
		{
		}

		void* value()
		{
			return val;
		}

	protected:
		void* val;

};

#endif // VALUE_H_

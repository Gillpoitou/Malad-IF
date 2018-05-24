#include "Attribute.cpp"

#if ! defined ( STRINGVAL_H_ )
#define STRINGVAL_H_


class StringVal : public Valeur
{
	public:

		StringVal(string val)
		{
			this->val = new string(val);
		}

		virtual ~StringVal()
		{
			;
		}

		void* value()
		{
			return val;
		}

};

#endif // STRINGVAL_H_

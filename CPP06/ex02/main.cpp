#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Foo.cpp
Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
	Base	*tmp;

	for (int i=0; i<5; i++)
	{
		tmp = generate();
		identify(tmp);
		identify(*tmp);
		delete tmp;
		PRINT("")
	}

	PRINT("Test with Base class")
	tmp = new Base();
	identify(tmp);
	identify(*tmp);
	delete tmp;
	PRINT("")

	PRINT("Test with Null ptr")
	identify(NULL);

	return 0;
}
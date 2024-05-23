#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/*
It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation
*/
Base * generate(void)
{
	int n = std::rand() % 3;
	if (n == 0)
	{
		PRINT("Generated A")
		return (dynamic_cast<Base *>(new A()));
	}
	if (n == 1)
	{
		PRINT("Generated B")
		return (dynamic_cast<Base *>(new B()));
	}
	PRINT("Generated C")
	return (dynamic_cast<Base *>(new C()));
}

/*
	dynamic_cast on pointers return NULL is it failed
	so you can juste use it as a boolean comparaison
*/
void identify(Base* p)
{
	if (!p){
		PRINT("Bad Input: Pointer is Null")
		return ;
	}
	if (dynamic_cast<A *>(p)){
		PRINT("Original ptr type was: A")
		return ;
	}
	if (dynamic_cast<B *>(p)){
		PRINT("Original ptr type was: B")
		return ;
	}
	if (dynamic_cast<C *>(p)){
		PRINT("Original ptr type was: C")
		return ;
	}
	PRINT("Bad Input: Pointer Does not corespond to any type")
}

/*
	dynamic_cast on non-pointers does not return anything you can use
	in a comparaison ... (Very sad indeed)
*/
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		PRINT("Original reference type was: A")
		return ;
	}
	catch (std::exception &e){;}

	try
	{
		(void)dynamic_cast<B &>(p);
		PRINT("Original reference type was: B")
		return ;
	}
	catch (std::exception &e){;}

	try
	{
		(void)dynamic_cast<C &>(p);
		PRINT("Original reference type was: C")
		return ;
	}
	catch (std::exception &e){;}

	PRINT("Bad Input: Reference does not corespond to any type")
}
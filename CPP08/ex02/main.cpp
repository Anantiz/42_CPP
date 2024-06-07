#include "MutantStack.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::cout << "Test 1, using a default deque" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Stack top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout <<"Stack size: " <<  mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	/*
		All overloads work because we inherit from std::stack
		So these tests are pointless
	*/

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	// Try to copy a MutantStack into a std::stack, it should work, because MutantStack inherits from std::stack
	// even tho it's terrible design and you should never do that, it works :shrug:
	std::stack<int> s(mstack);




	// test 2, using a vector
	std::cout << "\n\nTest 2, using a vector" << std::endl;


	MutantStack<int, std::vector<int> > mstack2;

	mstack2.push(5);
	mstack2.push(17);

	std::cout << "Stack top: " << mstack2.top() << std::endl;
	mstack2.pop();
	std::cout << "Stack size: " << mstack2.size() << std::endl;
	mstack2.push(3);
	mstack2.push(5);
	mstack2.push(737);


	// Watch that return type ;)
	// c++98 compliant, so no `auto`, life's tough man
	MutantStack<int, std::vector<int> >::iterator it2 = mstack2.begin();
	MutantStack<int, std::vector<int> >::iterator ite2 = mstack2.end();
	++it2;
	--it2;

	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	return 0;
}
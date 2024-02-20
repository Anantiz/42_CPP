#include <string>
#include <iostream>

int	main()
{
	std::string name = "HI THIS IS BRAIN";
	std::string *strinPTR = &name;
	std::string &strinREF = name;

	std::cout << "Address of the string: " << &name << std::endl;
	std::cout << "Address of the string using the pointer: " << strinPTR << std::endl;
	std::cout << "Address of the string using the reference: " << &strinREF << std::endl;

	std::cout << "String: " << name << std::endl;
	std::cout << "String using the pointer: " << *strinPTR << std::endl;
	std::cout << "String using the reference: " << strinREF << std::endl;

	return 0;
}
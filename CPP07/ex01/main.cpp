#include "iter.hpp"

int main( void )
{
	int			list_a[] = {1, 2, 3};
	float		list_b[] = {0.0, 0.1, 0.2, 0.3, 0.4};
	std::string	list_c[] = {"Hey", "mom", "<3", "!"};

	std::cout << "Int list: " << std::endl;
	InternationalThermonuclearExperimentalReactor<int>(list_a, 3, test<int>);

	std::cout << "\nFloat list:" << std::endl;
	InternationalThermonuclearExperimentalReactor<float>(list_b, 5, test<float>);

	std::cout << "\nString list:" << std::endl;
	InternationalThermonuclearExperimentalReactor<std::string>(list_c, 4, test<std::string>);

	return (0);
}
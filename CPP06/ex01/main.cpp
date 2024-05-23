#include "Serializer.hpp"

int main()
{
	Data	*var = new Data("I Lived !");
	Data	*var2 = NULL;

	uintptr_t	serialized_ptr;

	if (!var)
		return (EXIT_FAILURE);

	serialized_ptr = Serializer::serialize(var);
	var2 = Serializer::deserialize(serialized_ptr);

	std::cout << "Base ptr:       " << var << std::endl;
	std::cout << "Serialized ptr: 0x" << std::hex << serialized_ptr << " (Yeah! It's the same value, but it has a different name now)" << std::endl;
	std::cout << var2->content << std::endl;

	delete	var2;
	return (EXIT_SUCCESS);
}
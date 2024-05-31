#include "easyfind.hpp"
#include <list>
#include <map>

int main()
{
	std::list<int> list(5);

	for (int i = 0; i < 5; i++)
		list.push_back(i);

	easyfind(list, 3);
	easyfind(list, 42);


// Cannot compile
	// std::map<int, std::string> map;
	// map.insert(std::pair<int, std::string>(1, "one"));
	// map.insert(std::pair<int, std::string>(2, "two"));
	// map.insert(std::pair<int, std::string>(3, "three"));
	// easyfind(map, 2);


	return 0;
}
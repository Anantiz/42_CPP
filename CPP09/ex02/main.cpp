#include "PmergeMe.hpp"

constexpr size_t g_treshold = 100 / 2;

int main(int ac, char **av)
{
	std::vector<size_t>	v;
	std::list<size_t>	l;

	for (int i = 1; i < ac; i++)
	{
		int n = atoi(av[i]);
		v.push_back(n);
		l.push_back(n);
	}


	t_time_point start = std::chrono::high_resolution_clock::now();

	PmergeMe(v);

	t_time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;

	return 0;
}
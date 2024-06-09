#include "PmergeMe.hpp"

template <typename T, template<class, class> class C, class Alloc>
void print_container(const C<T, Alloc> &c)
{
	for (typename C<T, Alloc>::const_iterator it = c.begin(); it != c.end(); ++it)
	{
	std::cout << *it << "  ";
	}
	std::cout << std::endl;
}

std::list<size_t>	fill_vector(std::vector<size_t> &v, size_t size)
{
	std::list<size_t>    l(size);
	std::srand( time ( NULL ) );// Seed rng

	// Apply rand to each element of the list
	std::generate( l.begin(), l.end(), std::rand );
	v.insert(v.end(), l.begin(), l.end());
	return l;
}


int main(int ac, char **av)
{
	std::vector<size_t>	vec;
	std::list<size_t>	lst;

	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			long long n = atoll(av[i]);
			if (n < 0)
			{
				std::cerr << "Only positive numbers are allowed" << std::endl;
				return 1;
			}
			vec.push_back((size_t)n);
			lst.push_back((size_t)n);
		}
	}
	else
	{
		std::cout << "No input, generating random numbers instead\n" << std::endl;
		lst = fill_vector(vec, 10000);
	}

	std::cout << "Before: ";
	if (vec.size() < 50)
		print_container(vec);
	else
		std::cout << "Too many elements to print (" << vec.size() << ")" << std::endl;


	std::clock_t start = std::clock();
	PmergeMe(lst);
	std::clock_t end = std::clock();
	double duration_lst = double(end - start) / CLOCKS_PER_SEC;

	start = std::clock();
	PmergeMe(vec);
	end = std::clock();
	double duration_vec = double(end - start) / CLOCKS_PER_SEC;

	std::cout << "After: ";
	if (vec.size() < 50)
		print_container(lst);
	else
		std::cout << "Too many elements to print (" << vec.size() << ")" << std::endl;
	std::cout << std::endl;
	std::cout << "Time to process a range of: " << lst.size() \
	<< " elements with std::vector :" << duration_vec << " seconds" << std::endl;
	std::cout << "Time to process a range of: " << lst.size() \
	<< " elements with std::list :" << duration_lst << " seconds\n" << std::endl;

	std::cout << "Final note:\n\t`std::list` is faster, but only because of the implementation of the algorithm." << std::endl;
	std::cout << "\tBecause `std::vector` creates temporary copies while `td::list` uses iterators \n\tover a shared memory buffer, making it more efficient.\n" << std::endl;

	std::cout << "\n\nSo like, Yeah, I'm an idiot.\nBut the subject never said the vectors had to be sorted in place.\n\t¯\\_(ツ)_/¯" << std::endl;
	return 0;
}
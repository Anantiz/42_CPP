#include "PmergeMe.hpp"

void insert_sort(std::vector<size_t> &v, size_t low, size_t high)
{
	size_t	tmp;

	for (size_t i = low; i <= high; i++)
	{
	}
}

void merge(std::vector<size_t> &v, size_t low, size_t high, size_t mid)
{
	std::vector<size_t> left;
	std::vector<size_t> right;

	// Merge
	size_t i = 0, j = 0;
	while (left.size() != 0 || right.size() != 0)
	{
		if (left[i] < right[j])
			v.push_back(left[i++]);
		else
			v.push_back(right[j++]);
	}

	// Push remaining elements
	while (left.size())
		v.push_back(left[i++]);
	while (right.size())
		v.push_back(right[j++]);
}

void merge_sort(std::vector<size_t> &v, size_t low, size_t high)
{
	size_t	mid = (high - low) / 2;

	if ((high - low) < g_treshold)
	{
		merge_sort(v, low, mid);
		merge_sort(v, mid + 1, high);
	}
	else
		insert_sort(v, low, high);
	merge(v , low, high, mid);
}

/*
	Merge-Insertion sort
*/
void	PmergeMe(std::vector<size_t> v)
{
	merge_sort(v, 0, v.size() - 1);
}

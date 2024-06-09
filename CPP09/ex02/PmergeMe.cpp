#include "PmergeMe.hpp"

void insert_sort(std::vector<size_t> &v, size_t low, size_t high)
{
	for (size_t i = low + 1; i < high; i++)
	{
		size_t tmp = v[i];
		long j = i - 1;

		while (j >= (long long)low && v[j] > tmp)
		{
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = tmp;
	}
}

void merge(std::vector<size_t> &v, size_t low, size_t high, size_t mid)
{
	std::vector<size_t> left(v.begin() + low, v.begin() + mid + 1);
	std::vector<size_t> right(v.begin() + mid + 1, v.begin() + high + 1);

	// Merge
	size_t i = 0, j = 0, k = low;
	while (i < left.size() && j < right.size())
	{
		if (left[i] < right[j])
			v[k++] = left[i++];
		else
			v[k++] = right[j++];
	}

	// Push remaining elements
	while (i < left.size())
		v[k++] = left[i++];
	while (j < right.size())
		v[k++] = right[j++];
}

void merge_sort(std::vector<size_t> &v, size_t low, size_t high)
{
	if (low < high)
	{
		size_t	mid = low + ((high - low) / 2);

		if ((high - low) < THRESHOLD)
		{
			merge_sort(v, low, mid);
			merge_sort(v, mid + 1, high);
			merge(v, low, high, mid);
		}
		else
			insert_sort(v, low, high + 1);
	}
}

/*
	Merge-Insertion sort
*/
void	PmergeMe(std::vector<size_t> &v)
{
	merge_sort(v, 0, v.size() - 1);
}


////////////////////////////////
////////////////////////////////
////////////////////////////////
////////////////////////////////
////////////////////////////////
////////////////////////////////
////////////////////////////////

/*
++ +++ + + ++ + ++
everywhere cuz iterators are syntactic abominations
*/

void insert_sort(t_list_iter low, t_list_iter high)
{
	bool negative = false;
	t_list_iter	i = low;
	++i; // Start at one
	while(i != high)
	{
		size_t tmp		= *i;
		t_list_iter j	= i;
		--j;

		while (*j > tmp)
		{
			*(++j) = *j;
			--j;
			if (j == low)
			{
				negative = true;
				break;
			}
			--j;
		}
		if (negative != true) // BEcause iterators can't go to -1 I gotta protect this shit that way
			++j;
		else
			negative = false;
		*j = tmp;
		++i;
	}
}

void merge(std::list<size_t>& l, t_list_iter low, t_list_iter mid, t_list_iter high)
{
	(void)l;
	std::list<size_t> left(low, mid);
	std::list<size_t> right(mid, high);

	t_list_iter i = left.begin();
	t_list_iter j = right.begin();
	t_list_iter k = low;

	while (i != left.end() && j != right.end())
	{
		if (*i <= *j)
			*(k++) = *(i++);
		else
			*(k++) = *(j++);
	}

	while (i != left.end())
		*(k++) = *(i++);

	while (j != right.end())
		*(k++) = *(j++);
}

void merge_sort(std::list<size_t>& l, t_list_iter low, t_list_iter high)
{
	static const std::ptrdiff_t threshold = THRESHOLD;
	if (std::distance(low, high) > 1)
	{
		t_list_iter mid = low;
		std::advance(mid, std::distance(low, high) / 2); // Increment the iterator mid by n positions

		if (std::distance(low, high) > threshold)
		{
			merge_sort(l, low, mid);
			merge_sort(l, mid, high);
			merge(l, low, mid, high);
		}
		else
			insert_sort(low, high);
	}
}

void	PmergeMe(std::list<size_t> &l)
{
	merge_sort(l, l.begin(), l.end());
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <chrono>
#include <numeric>
#include <tuple>

void print_v(std::vector<size_t> &v, int end)
{
	for (int i=0; i < end;i++)
	{
		std::cout << v[i] << "  ";
	}
	std::cout << std::endl;
}

void insert_sort(std::vector<size_t> &v, int start, int end)
{
	for (int i = start + 1; i < end; i++)
	{
		size_t tmp = v[i];
		int j = i - 1;

		while (j >= start && v[j] > tmp)
		{
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = tmp;
	}
}

void slect_sort(std::vector<size_t> &v, int start, int end)
{
	size_t	swap;
	int		insert_index = 0;

	for (int iter_index = start; iter_index < end; iter_index++)
	{
		size_t	lowest = -1;
		int		lowest_index;

		for (int j = iter_index; j < end; j++)
		{
			if (v[j] < lowest)
			{
				lowest = v[j];
				lowest_index = j;
			}
		}
		swap = v[insert_index];
		v[insert_index] = v[lowest_index];
		v[lowest_index] = swap;
		insert_index++;
	}

}

void fill_vector(std::vector<size_t> &v, size_t size)
{

	std::list<ssize_t>    l(size);	// Create list with remaining space
	std::srand( time ( NULL ) );				// Seed rng

	// Apply rand to each element of the list
	std::generate( l.begin(), l.end(), std::rand );

	v.insert(v.end(), l.begin(), l.end());
}

std::tuple<std::chrono::duration<double>, std::chrono::duration<double>, std::chrono::duration<double>>
calculate_worst_average_best(const std::vector<std::chrono::duration<double>>& durations) {
    if (durations.empty()) {
        throw std::invalid_argument("The duration vector is empty");
    }

    auto min_max = std::minmax_element(durations.begin(), durations.end());
    std::chrono::duration<double> best = *min_max.first;
    std::chrono::duration<double> worst = *min_max.second;

    std::chrono::duration<double> sum = std::accumulate(durations.begin(), durations.end(), std::chrono::duration<double>(0));
    std::chrono::duration<double> average = sum / durations.size();

    return std::make_tuple(worst, average, best);
}

typedef std::chrono::high_resolution_clock::time_point	t_time_point;
int main()
{
	std::vector<std::chrono::duration<double> >	durations_a;
	std::vector<std::chrono::duration<double> >	durations_b;

	size_t	vector_sizes[] = {30, 500, 5000, 50000};
	size_t	sample_size = 5000;
	int		v_size = 0;
	int		v_size_max = 1;


	while (v_size < v_size_max)
	{
		for (size_t epoch = 0; epoch < sample_size; epoch++)
		{
			std::vector<size_t> og;
			fill_vector(og, vector_sizes[v_size]);
			std::vector<size_t> v1 = og;
			std::vector<size_t> v2 = og;

			t_time_point start_a = std::chrono::high_resolution_clock::now();
			insert_sort(v1, 0, og.size());
			t_time_point end_a = std::chrono::high_resolution_clock::now();
			durations_a.push_back(end_a - start_a);

			t_time_point start_b = std::chrono::high_resolution_clock::now();
			slect_sort(v2, 0, og.size());
			t_time_point end_b = std::chrono::high_resolution_clock::now();
			durations_b.push_back(end_b - start_b);
		}

		std::cout << "Vector size: " << vector_sizes[v_size] << std::endl;
		std::cout << "Insert sort: " << std::endl;
		auto [worst_a, average_a, best_a] = calculate_worst_average_best(durations_a);

    	std::cout << "\tWorst: " << worst_a.count() << " seconds\n";
    	std::cout << "\tAverage: " << average_a.count() << " seconds\n";
    	std::cout << "\tBest: " << best_a.count() << " seconds\n" << std::endl;

		std::cout << "My algorythm sort: " << std::endl;
		auto [worst_b, average_b, best_b] = calculate_worst_average_best(durations_b);

    	std::cout << "\tWorst: " << worst_b.count() << " seconds\n";
    	std::cout << "\tAverage: " << average_b.count() << " seconds\n";
    	std::cout << "\tBest: " << best_b.count() << " seconds\n" << std::endl;

		durations_a.clear();
		durations_b.clear();
		v_size++;
	}
}


/*
Vector size: 30
Insert sort:
	Worst: 2.066e-05 seconds
	Average: 1.74347e-06 seconds
	Best: 1.605e-06 seconds

My algorythm sort:
	Worst: 1.7214e-05 seconds
	Average: 1.65661e-06 seconds
	Best: 1.519e-06 seconds

Vector size: 500
Insert sort:
	Worst: 0.000600855 seconds
	Average: 0.000377729 seconds
	Best: 0.000361766 seconds

My algorythm sort:
	Worst: 0.000557841 seconds
	Average: 0.000338625 seconds
	Best: 0.000325953 seconds

Vector size: 5000
Insert sort:
	Worst: 0.0471514 seconds
	Average: 0.0359536 seconds
	Best: 0.0345145 seconds

My algorythm sort:
	Worst: 0.0382086 seconds
	Average: 0.0308045 seconds
	Best: 0.0295504 seconds



*/
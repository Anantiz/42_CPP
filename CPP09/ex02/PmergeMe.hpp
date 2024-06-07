#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>

typedef std::chrono::high_resolution_clock::time_point	t_time_point;

void PmergeMe(std::vector<size_t> v);
void PmergeMe(std::list<size_t> v);

extern constexpr size_t g_treshold = 100 / 2;
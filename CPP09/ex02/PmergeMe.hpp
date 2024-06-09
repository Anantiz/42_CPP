#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>

// Actually 20 because we compare mid to the thresold
#define THRESHOLD 10

void PmergeMe(std::vector<size_t> &v);
void PmergeMe(std::list<size_t> &l);

typedef std::list<size_t>::iterator t_list_iter;
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <omp.h>

void withLocks(const int N, std::vector<int>, std::vector<int>);
#pragma once
#include <vector>
#include <map>
#include <list>

size_t countPebbles(std::vector<int> pebbles);

size_t oneblink(size_t pebble_num, long long int step);

size_t count_num(size_t n, size_t num_iters,
    std::map<std::pair<size_t, size_t>, size_t>& vals);

size_t blink(size_t n, const std::list<size_t>& st);
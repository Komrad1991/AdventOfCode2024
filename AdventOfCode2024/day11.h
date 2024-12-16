#pragma once
#include <vector>
#include <map>

long long int countPebbles(std::vector<int> pebbles);

void oneblink(long long int pebble_num, int step,std::vector<int>& pebbles);

int sum(int x, int y);

void calculateZero(int pebble_num, std::map<int, int>& pebbles, int step, std::map<int, std::vector<int>>& concretePebbles);
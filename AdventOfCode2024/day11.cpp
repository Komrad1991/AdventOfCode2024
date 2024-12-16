#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "day11.h"
#include <map>


std::map<int, std::map<int,std::vector<int>>> numfromStep;

long long int countPebbles(std::vector<int> pebbles)
{
	
}

void oneblink(long long int pebble_num,int step,std::vector<int>& pebbles)
{
	std::string str;
	int len = 0;
	if (step >= 26)
	{
		
		return;
	}
	if (pebble_num == 0)
	{
		
	}
	else if ((len = (str = std::to_string(pebble_num)).length()) % 2 == 0) {
		auto left = pebble_num / ((int)std::pow(10,len/2));
		auto right = pebble_num % ((int)std::pow(10,len/2));
		oneblink(left, step + 1, pebbles);
		oneblink(right, step + 1, pebbles);
	}
	else oneblink(pebble_num * 2024, step + 1,pebbles)
}

int sum(int x, int y)
{
	return x + y;
}

void calculateZero(int pebble_num,std::map<int,int>& pebbles,int step,std::map<int,std::vector<int>>& concretePebbles)
{
	std::string str;
	int len = 0;
	pebbles[step] += 1;
	concretePebbles[step].push_back(pebble_num);
	if (step >= 26)
	{
		return;
	}
	if (pebble_num == 0)
	{
		calculateZero(1, pebbles, step + 1,concretePebbles);
	}
	else if ((len = (str = std::to_string(pebble_num)).length()) % 2 == 0) {
		auto left = pebble_num / ((int)std::pow(10, len / 2));
		auto right = pebble_num % ((int)std::pow(10, len / 2));
		calculateZero(left, pebbles, step + 1,concretePebbles);
		calculateZero(right, pebbles, step + 1,concretePebbles);
	}
	else calculateZero(pebble_num * 2024, pebbles, step+1,concretePebbles);
}
#include "day9.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

long double defrag(std::string path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("no file");
	std::string disc;
	std::getline(file, disc);
	int ins = 0;
	int ind = 0;
	int even = 1;
	std::vector<std::string> vec;
	while(ind < disc.size())
	{
		int count = disc[ind] - '0';
			if (even % 2 == 0)
			{
				for (int i = 0; i < count; i++)
				{
					vec.push_back("*");
				}
				++ind;
				++even;
			}
			else
			{
				auto str = std::to_string(ins);
				auto push = std::string();
				for (int i = 0; i < count; i++)
				{
					vec.push_back(std::to_string(ins));
				}
				++ind;
				++even;
				++ins;
			}
	}
	swap_nums(vec);
	long double result = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i][0] == '*') break;
		result += std::stoi(vec[i]) * i;
	}

	return result;
}

void swap_nums(std::vector<std::string>& s)
{
	size_t j{ s.size() - 1 };

	for (size_t i{}; i < j; ++i)
	{
		if (s[i] == "*")
		{
			while (s[j] == "*" && j != i) --j;
			s[i] = s[j];
			s[j] = '*';
		}
	}
}
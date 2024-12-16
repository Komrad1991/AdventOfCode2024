#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "day11.h"
#include <map>
#include <list>

std::map<std::pair<size_t,size_t>, size_t> numfromStep;

size_t countPebbles(std::vector<int> pebbles)
{
	size_t ret = 0;
	for (auto x : pebbles)
	{
		ret += oneblink(x, 75);
	}
	return ret;
}

size_t oneblink(size_t pebble_num, long long int step)
{
    if (numfromStep.contains({ pebble_num, step })) return numfromStep[{pebble_num, step}];

    size_t sum{};
    std::vector<size_t> st{ pebble_num };

    for (int i{}; i < step; ++i)
    {
        for (auto it{ st.begin() }; it != st.end(); ++it)
        {
            if (*it == 0) *it = 1;
            else if (std::to_string(*it).size() % 2 == 0)
            {
                auto num = std::to_string(*it);
                size_t left = std::stoull(num.substr(0, num.length() / 2));
                size_t right = std::stoull(num.substr(num.length() / 2));
                sum += oneblink(left, step - i - 1);
                sum += oneblink(right, step - i - 1);
                it = st.erase(it);
                if (it == st.end()) break;
            }
            else *it *= 2024;
        }
    }

    numfromStep[{pebble_num, step}] = st.size() + sum;

    return st.size() + sum;
}
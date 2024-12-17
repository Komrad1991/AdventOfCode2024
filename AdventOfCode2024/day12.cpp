#include "day12.h"
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iostream>
#include <set>

long int calculateFence(const std::string& path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("error: no file.");
	std::string line;
	std::vector<std::string> map;

	while (std::getline(file, line) && line.size() > 0)
	{
		map.push_back(line);
	}
	std::vector<std::pair<char, std::pair<int, int>>> sizes;
	std::set<std::pair<int, int>> set;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (!set.contains({ i,j }))
			{
				auto ch = map[i][j];
				sizes.push_back({ ch,calculateSides(i,j,ch,map,set)});
			}
		}
	}
	long int ret = 0;
	for (int i = 0; i < sizes.size(); i++)
	{
		//std::cout << ret << " += " << sizes[i].second.first << " * " << sizes[i].second.second << " ch: " << sizes[i].first << std::endl;
		std::cout << ret << " += " << sizes[i].second.first / 2 << " * " << sizes[i].second.second << " ch: " << sizes[i].first << std::endl;
		ret += (sizes[i].second.first / 2) * sizes[i].second.second;
	}
	return ret;
}

std::pair<int, int> calculateArea(int x, int y, char ch,std::vector<std::string>& map, std::set<std::pair<int,int>>& set)
{
	std::pair<int, int> ret = { 0,1 };
	if (!inBound(x - 1, 0, map.size()) || (inBound(x - 1, 0, map.size()) && (map[x - 1][y] != ch)))
	{
		ret.first++;
	}
	if (!inBound(x + 1, 0, map.size()) || (inBound(x + 1, 0, map.size()) && (map[x + 1][y] != ch)))
	{
		ret.first++;
	}
	if (!inBound(y -1, 0, map[x].size()) || (inBound(y - 1, 0, map[x].size()) && (map[x][y - 1] != ch)))
	{
		ret.first++;
	}
	if (!inBound(y + 1, 0, map[x].size()) || (inBound(y + 1, 0,map[x].size()) && (map[x][y + 1] != ch)))
	{
		ret.first++;
	}
	set.insert({ x,y });
	if (inBound(x + 1, 0, map.size()) && map[x + 1][y] == ch && !set.contains({ x + 1,y }))
	{
		auto temp = calculateArea(x + 1, y, ch, map,set);
		ret.first += temp.first;
		ret.second += temp.second;
	}
	if (inBound(x - 1, 0, map.size()) && map[x - 1][y] == ch && !set.contains({ x - 1,y }))
	{
		auto temp = calculateArea(x - 1, y, ch, map,set);
		ret.first += temp.first;
		ret.second += temp.second;
	}
	if (inBound(y + 1, 0, map[x].size()) && map[x][y + 1] == ch && !set.contains({ x,y + 1 }))
	{
		auto temp = calculateArea(x, y + 1, ch, map,set);
		ret.first += temp.first;
		ret.second += temp.second;
	}
	if (inBound(y - 1, 0, map[x].size()) && map[x][y - 1] == ch && !set.contains({ x,y - 1 }))
	{
		auto temp = calculateArea(x, y - 1, ch, map,set);
		ret.first += temp.first;
		ret.second += temp.second;
	}
	return ret;
}

bool inBound(int val, int zero, int size)
{
	return zero <= val && val < size;
}

std::pair<int, int> calculateSides(int x, int y, char ch, std::vector<std::string>& map, std::set<std::pair<int, int>>& set)
{
	std::pair<int, int> ret = { 0,1 };
	bool left, right, up, down = false;
	if (inBound(x + 1, 0, map.size()) && inBound(y + 1, 0, map[x + 1].size()))
	{
		if (map[x + 1][y] == ch && map[x][y + 1] == ch && map[x + 1][y + 1] != ch)
		{
			ret.first += 2;
		}
		else if (map[x + 1][y] != ch && map[x][y + 1] != ch)
		{
			ret.first += 2;
		}
	}
	else if (!(inBound(x + 1, 0, map.size()) && inBound(y + 1, 0, map[x + 1].size())))
	{
		if ((!inBound(x + 1, 0, map.size()) || (inBound(x + 1, 0, map.size()) && map[x + 1][y] != ch))
			&& (!inBound(y + 1, 0, map[x].size()) || (inBound(y + 1, 0, map.size()) && map[x][y + 1] != ch)))
		{
			ret.first += 2;
		}
	}

	if (inBound(x + 1, 0, map.size()) && inBound(y - 1, 0, map[x + 1].size()) )
	{
		if (map[x + 1][y] == ch && map[x][y - 1] == ch && map[x + 1][y - 1] != ch)
		{
			ret.first += 2;
		}
		else if (map[x + 1][y] != ch && map[x][y - 1] != ch)
		{
			ret.first += 2;
		}
	}
	else if (!(inBound(x + 1, 0, map.size()) && inBound(y - 1, 0, map[x + 1].size())))
	{
		if ((!inBound(x + 1, 0, map.size()) || (inBound(x + 1, 0, map.size()) && map[x + 1][y] != ch))
			&& (!inBound(y - 1, 0, map[x].size()) || (inBound(y - 1, 0, map.size()) && map[x][y - 1] != ch)))
		{
			ret.first += 2;
		}
	}

	if (inBound(x - 1, 0, map.size()) && inBound(y + 1, 0, map[x - 1].size()) )
	{
		if (map[x - 1][y] == ch && map[x][y + 1] == ch && map[x - 1][y + 1] != ch)
		{
			ret.first += 2;
		}
		else if (map[x - 1][y] != ch && map[x][y + 1] != ch)
		{
			ret.first += 2;
		}
	}
	else if (!(inBound(x - 1, 0, map.size()) && inBound(y + 1, 0, map[x - 1].size())))
	{
		if ((!inBound(x - 1, 0, map.size()) || (inBound(x - 1, 0, map.size()) && map[x - 1][y] != ch))
			&& (!inBound(y + 1, 0, map[x].size()) || (inBound(y - 1, 0, map.size()) && map[x][y + 1] != ch)))
		{
			ret.first += 2;
		}
	}

	if (inBound(x - 1, 0, map.size()) && inBound(y - 1, 0, map[x - 1].size()) )
	{
		if (map[x - 1][y] == ch && map[x][y - 1] == ch && map[x - 1][y - 1] != ch)
		{
			ret.first += 2;
		}
		else if (map[x - 1][y] != ch && map[x][y - 1] != ch)
		{
			ret.first += 2;
		}
	}
	else if (!(inBound(x - 1, 0, map.size()) && inBound(y - 1, 0, map[x - 1].size())))
	{
		if ((!inBound(x - 1, 0, map.size()) || (inBound(x - 1, 0, map.size()) && map[x - 1][y] != ch))
			&& (!inBound(y - 1, 0, map[x].size()) || (inBound(y - 1, 0, map.size()) && map[x][y - 1] != ch)))
		{
			ret.first += 2;
		}
	}
	set.insert({ x,y });
	if (inBound(x + 1, 0, map.size()) && map[x + 1][y] == ch && !set.contains({ x + 1,y }))
	{
		auto temp = calculateSides(x + 1, y, ch, map, set);
		ret.first += temp.first;
		ret.second += temp.second;
	}
	if (inBound(x - 1, 0, map.size()) && map[x - 1][y] == ch && !set.contains({ x - 1,y }))
	{
		auto temp = calculateSides(x - 1, y, ch, map, set);
		ret.first += temp.first;
		ret.second += temp.second;
	}
	if (inBound(y + 1, 0, map[x].size()) && map[x][y + 1] == ch && !set.contains({ x,y + 1 }))
	{
		auto temp = calculateSides(x, y + 1, ch, map, set);
		ret.first += temp.first;
		ret.second += temp.second;
	}
	if (inBound(y - 1, 0, map[x].size()) && map[x][y - 1] == ch && !set.contains({ x,y - 1 }))
	{
		auto temp = calculateSides(x, y - 1, ch, map, set);
		ret.first += temp.first;
		ret.second += temp.second;
	}
	//ret.first = ret.first / 2;
	return ret;
}
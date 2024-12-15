#include "day10.h"
#include <string>
#include <fstream>
#include <vector>

int countTrailHeads(std::string path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("no file");
	std::string temp_line;
	std::vector<std::string> map;
	while (std::getline(file, temp_line) && temp_line.size() > 0)
	{
		map.push_back(temp_line);
	}
	int res = 0;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == '0')
			{
				std::set<std::pair<int, int>> set;
				calculatePath(i, j, set, 0,map);
				res += set.size();
			}
		}
	}
	return res;
}

int countTrailHeads2(std::string path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("no file");
	std::string temp_line;
	std::vector<std::string> map;
	while (std::getline(file, temp_line) && temp_line.size() > 0)
	{
		map.push_back(temp_line);
	}
	int res = 0;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == '0')
			{
				std::vector<std::pair<int, int>> set;
				calculatePath2(i, j, set, 0, map);
				res += set.size();
			}
		}
	}
	return res;
}

void calculatePath(int x, int y, std::set<std::pair<int, int>>& sets, int value, std::vector<std::string> map)
{
	if (value == 9)
	{
		sets.insert({ x,y });
		return;
	}
	else
	{
		if (x - 1 >= 0 && (map[x - 1][y] - '0')-1 == value)
		{
			calculatePath(x - 1, y, sets, value + 1, map);
		}
		if (x + 1 < map.size() && (map[x + 1][y] - '0') - 1 == value)
		{
			calculatePath(x + 1, y, sets, value + 1, map);
		}
		if (y - 1 >= 0 && (map[x][y-1] - '0') - 1 == value)
		{
			calculatePath(x, y - 1, sets, value + 1, map);
		}
		if (y + 1 < map[x].size() && (map[x][y + 1] - '0') - 1 == value)
		{
			calculatePath(x, y + 1, sets, value + 1, map);
		}
	}
}

void calculatePath2(int x, int y, std::vector<std::pair<int, int>>& trails, int value, std::vector<std::string> map)
{
	if (value == 9)
	{
		trails.push_back({ x,y });
		return;
	}
	else
	{
		if (x - 1 >= 0 && (map[x - 1][y] - '0') - 1 == value)
		{
			calculatePath2(x - 1, y, trails, value + 1, map);
		}
		if (x + 1 < map.size() && (map[x + 1][y] - '0') - 1 == value)
		{
			calculatePath2(x + 1, y, trails, value + 1, map);
		}
		if (y - 1 >= 0 && (map[x][y - 1] - '0') - 1 == value)
		{
			calculatePath2(x, y - 1, trails, value + 1, map);
		}
		if (y + 1 < map[x].size() && (map[x][y + 1] - '0') - 1 == value)
		{
			calculatePath2(x, y + 1, trails, value + 1, map);
		}
	}
}


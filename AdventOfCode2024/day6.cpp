#include "day6.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
int x = 0;
int y = 0;
std::vector<std::pair<int, int>> poses;

int howLongPath(std::string path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("no file");
	std::vector<std::string> map;
	std::string line;
	while (std::getline(file, line) && line.size() > 0)
	{
		map.push_back(line);
	}
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == '^')
			{
				x = i;
				y = j;
			}
			else if (map[i][j] == '>')
			{
				x = i;
				y = j;
			}
			else if (map[i][j] == 'v')
			{
				x = i;
				y = j;
			}
			else if (map[i][j] == '<')
			{
				x = i;
				y = j;
			}
		}
	}
	while (move(map));
	int count = 0;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == '+') ++count;
		}
	}
	return count + 1;
}

bool move(std::vector<std::string>& map)
{

	if (map[x][y] == '^')
	{
		if (x - 1 >= 0)
		{
			if (map[x - 1][y] == '#')
			{
				map[x][y] = '>';
			}
			else
			{
				map[x][y] = '+';
				std::pair<int, int> pair = { x,y };
				if (std::find(poses.begin(),poses.end(), pair) == poses.end()) poses.push_back(pair);
				map[x - 1][y] = '^';
				--x;
			}
		}
		else {
			std::pair<int, int> pair = { x,y };
			if (std::find(poses.begin(), poses.end(), pair) == poses.end()) poses.push_back(pair);
			return false;
		}
	}
	else if (map[x][y] == '>')
	{
		if (y + 1 < map[x].size())
		{
			if (map[x][y + 1] == '#')
			{
				map[x][y] = 'v';
			}
			else
			{
				map[x][y] = '+';
				std::pair<int, int> pair = { x,y };
				if (std::find(poses.begin(), poses.end(), pair) == poses.end()) poses.push_back(pair);
				map[x][y + 1] = '>';
				++y;
			}
		}
		else {
			std::pair<int, int> pair = { x,y };
			if (std::find(poses.begin(), poses.end(), pair) == poses.end()) poses.push_back(pair);
			return false;
		}
	}
	else if (map[x][y] == 'v')
	{
		if (x + 1 < map.size())
		{
			if (map[x + 1][y] == '#')
			{
				map[x][y] = '<';
			}
			else
			{
				map[x][y] = '+';
				std::pair<int, int> pair = { x,y };
				if (std::find(poses.begin(), poses.end(), pair) == poses.end()) poses.push_back(pair);
				map[x + 1][y] = 'v';
				++x;
			}
		}
		else {
			std::pair<int, int> pair = { x,y };
			if (std::find(poses.begin(), poses.end(), pair) == poses.end()) poses.push_back(pair);
			return false;
		}
	}
	else if (map[x][y] == '<')
	{
		if (y - 1 >= 0)
		{
			if (map[x][y - 1] == '#')
			{
				map[x][y] = '^';
			}
			else
			{
				map[x][y] = '+';
				std::pair<int, int> pair = { x,y };
				if (std::find(poses.begin(), poses.end(), pair) == poses.end()) poses.push_back(pair);
				map[x][y - 1] = '<';
				--y;
			}
		}
		else
		{
			std::pair<int, int> pair = { x,y };
			if (std::find(poses.begin(), poses.end(), pair) == poses.end()) poses.push_back(pair);
			return false;
		}
	}
	return true;
}

void printMap(std::vector<std::string>& map)
{
	for (int i = 0; i < map.size(); i++)
	{
		std::cout << map[i] << std::endl;
	}
	std::cout << std::endl;
}

int howManyLoops(std::string path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("no file");
	std::vector<std::string> map;
	std::string line;
	while (std::getline(file, line) && line.size() > 0)
	{
		map.push_back(line);
	}
	std::vector<std::string> originMap = map;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == '^')
			{
				x = i;
				y = j;
			}
			else if (map[i][j] == '>')
			{
				x = i;
				y = j;
			}
			else if (map[i][j] == 'v')
			{
				x = i;
				y = j;
			}
			else if (map[i][j] == '<')
			{
				x = i;
				y = j;
			}
		}
	}
	int xOr = x;
	int yOr = y;
	while (move(map));
	int count = 0;
	for (int i = 0; i < poses.size(); i++)
	{
		auto cloneMap = originMap;
		if (poses[i].first == xOr && poses[i].second == yOr) continue;
		cloneMap[poses[i].first][poses[i].second] = 'A';
		x = xOr;
		y = yOr;
		if (loops(cloneMap))
		{
			
			++count;
		}
	}
	return count;
}

bool loops(std::vector<std::string>& map)
{
	while (true) {
		if (map[x][y] == '^')
		{
			if (x - 1 >= 0)
			{
				if (map[x - 1][y] == '#')
				{
					map[x][y] = '>';
					map[x - 1][y] = 'A';
				}
				else if (map[x - 1][y] >= 'A')
				{
					if (map[x - 1][y] == 'D')
					{
						//printMap(map);
						return true;
					}
					else ++map[x - 1][y];
					map[x][y] = '>';
				}
				else
				{
					map[x][y] = '+';
					map[x - 1][y] = '^';
					--x;
				}
			}
			else return false;
		}
		else if (map[x][y] == '>')
		{
			if (y + 1 < map[x].size())
			{
				if (map[x][y + 1] == '#' )
				{
					map[x][y] = 'v';
					map[x][y + 1] = 'A';
				}
				else if (map[x][y + 1] >= 'A')
				{
					if (map[x][y + 1] == 'D') {
						//printMap(map);
						return true;
					}
					else ++map[x][y + 1];
					map[x][y] = 'v';
				}
				else
				{
					map[x][y] = '+';
					map[x][y + 1] = '>';
					++y;
				}
			}
			else return false;
		}
		else if (map[x][y] == 'v')
		{
			if (x + 1 < map.size())
			{
				if (map[x + 1][y] == '#')
				{
					map[x][y] = '<';
					map[x + 1][y] = 'A';
				}
				else if (map[x + 1][y] >= 'A')
				{
					if (map[x + 1][y] == 'D') {
						//printMap(map);
						return true;
					}
					else ++map[x + 1][y];
					map[x][y] = '<';
				}
				else
				{
					map[x][y] = '+';
					map[x + 1][y] = 'v';
					++x;
				}
			}
			else return false;
		}
		else if (map[x][y] == '<')
		{
			if (y - 1 >= 0)
			{
				if (map[x][y - 1] == '#')
				{
					map[x][y] = '^'; 
					map[x][y - 1] = 'A';
				}
				else if (map[x][y - 1] >= 'A')
				{
					if (map[x][y - 1] == 'D') {
						//printMap(map);
						return true;
					}
					else ++map[x][y - 1];
					map[x][y] = '^';
				}
				else
				{
					map[x][y] = '+';
					map[x][y - 1] = '<';
					--y;
				}
			}
			else return false;
		}
		//printMap(map);
	}
}
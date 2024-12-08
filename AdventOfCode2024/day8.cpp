#include "day8.h"
#include <string>
#include <fstream>
#include <vector>
#include "day6.h"
#include <iostream>

int countAntidotes(std::string path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("no file");
	std::string temp;
	std::vector<std::string> map;
	while (std::getline(file, temp))
	{
		map.push_back(temp);
	}
	auto antidote_count = 0;
	std::vector<std::pair<int, int>> locs;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			
			if (map[i][j] != '.' && map[i][j] != '#')
			{
				for (int x = 0; x < map.size(); x++)
				{
					for (int y = 0; y < map[x].size(); y++)
					{
						if (x == i && y == j) continue;
						if (map[x][y] == map[i][j])
						{
							for (int xx = 0; xx < 100; xx++)
							{
								std::pair<int, int> posibl = { i + (i - x)*xx,j + (j - y)*xx };
								if (posibl.first >= 0 && posibl.first < map.size())
								{
									if (posibl.second >= 0 && posibl.second < map[posibl.first].size())
									{
									
										if (std::find(locs.begin(), locs.end(), posibl) == locs.end()) {
											if (map[posibl.first][posibl.second] == '.') map[posibl.first][posibl.second] = '#';
											++antidote_count;
											locs.push_back(posibl);
											//printMap(map);
											//std::cout << "x = " << posibl.first << " y = " << posibl.second << std::endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return antidote_count;
}
#include "day4.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

int countXMAS(std::string path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("no file");
	std::vector<std::string> matr;
	std::string temp;
	while (std::getline(file, temp))
	{
		matr.push_back(temp);
	}
	int count = 0;
	for (int i = 0; i < matr.size(); i++)
	{
		for (int j = 0; j < matr[i].size(); j++)
		{
			if (matr[i][j] == 'X')
			{
				for (int x = -1; x < 2; x++)
				{
					for (int y = -1; y < 2; y++)
					{
						std::string m = "";
						std::string a = "";
						std::string s = "";
						if (y == 0 && x == 0) continue;
						if (matr.size() > (i + x)&& (i + x) >= 0 && matr[i].size() > (j + y)&& (j + y) >= 0) {
							m = std::string() + matr[i + x][j + y];
						}
						else continue;
						if (matr.size() > (i + x*2) && (i + x*2) >= 0 && matr[i].size() > (j + y*2) && (j + y*2) >= 0) {
							a = std::string() + matr[i + x * 2][j + y * 2];
						}
						else continue;
						if (matr.size() > (i + x*3) && (i + x*3) >= 0 && matr[i].size() > (j + y*3) && (j + y*3) >= 0) {
							s = std::string() + matr[i + x * 3][j + y * 3];
						}
						else continue;
						if (("X" + m + a + s) == "XMAS") ++count;
					}
				}
			}
		}
	}
	return count;
}


int countX_MAS(std::string path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("no file");
	std::vector<std::string> matr;
	std::string temp;
	while (std::getline(file, temp))
	{
		matr.push_back(temp);
	}
	int count = 0;
	for (int i = 1; i < matr.size()-1; i++)
	{
		for (int j = 1; j < matr[i].size()-1; j++)
		{
			if (matr[i][j] == 'A')
			{
				bool left = false;
				if (matr[i - 1][j - 1] == 'S')
				{
					if (matr[i + 1][j + 1] == 'M') left = true;
				}
				if (matr[i - 1][j - 1] == 'M')
				{
					if (matr[i + 1][j + 1] == 'S') left = true;
				}
				bool right = false;
				if (matr[i + 1][j - 1] == 'S')
				{
					if (matr[i - 1][j + 1] == 'M') right = true;
				}
				if (matr[i + 1][j - 1] == 'M')
				{
					if (matr[i - 1][j + 1] == 'S') right = true;
				}
				if (left && right) ++count;
			}
		}
	}
	return count;
}
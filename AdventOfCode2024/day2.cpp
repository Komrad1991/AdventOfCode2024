#include "day2.h"
#include <fstream>
#include <vector>
#include <math.h>

int countSafeLevels(std::string path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("no file");
	int res = 0;
	while (!file.eof())
	{
		std::string currLine;
		std::getline(file, currLine);
		std::vector<int> curr = parseLine(currLine);
		bool allGood = true;
		int pred = curr[1] - curr[0];
		if (abs(pred) <= 3 && abs(pred) > 0)
		{
			for (int i = 2; i < curr.size(); i++)
			{
				int currStat = curr[i] - curr[i - 1];
				if (abs(currStat) <= 3 && abs(currStat) > 0)
				{
					if ((pred > 0 && currStat > 0) || (pred < 0 && currStat < 0))
					{
						pred = currStat;
					}
					else 
					{
						allGood = false;
						break;
					}
				}
				else
				{
					allGood = false;
					break;
				}
			}
		}
		else allGood = false;
		if (allGood) ++res;
	}
	return res;
}

std::vector<int> parseLine(std::string str)
{
	std::vector<int> ret;
	size_t pos = 0;
	while ((pos = str.find_first_not_of(' ', pos)) != str.npos)
	{
		size_t nextSpace = str.find_first_of(' ', pos) - pos;
		std::string temp = str.substr(pos, nextSpace);
		ret.push_back(std::stoi(temp));
		pos = str.find_first_of(' ', pos);
	}
	return ret;
}

int countSafeLevels2(std::string path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("no file");
	int res = 0;
	while (!file.eof())
	{
		std::string currLine;
		std::getline(file, currLine);
		std::vector<int> curr = parseLine(currLine);

		int allGoodCount = 0;
		for (int j = 0; j < curr.size(); j++)
		{
			bool allGood = true;
			std::vector<int> tempCurr = curr;
			tempCurr.erase(tempCurr.begin() + j);
			int pred = tempCurr[1] - tempCurr[0];
			if (abs(pred) <= 3 && abs(pred) > 0)
			{
				for (int i = 2; i < tempCurr.size(); i++)
				{
					int currStat = tempCurr[i] - tempCurr[i - 1];
					if (abs(currStat) <= 3 && abs(currStat) > 0)
					{
						if ((pred > 0 && currStat > 0) || (pred < 0 && currStat < 0))
						{
							pred = currStat;
						}
						else
						{
							allGood = false;
							break;
						}
					}
					else
					{
						allGood = false;
						break;
					}
				}
			}
			else allGood = false;
			if (allGood) ++allGoodCount;
		}
		if (allGoodCount > 0) ++res;
	}
	return res;
}
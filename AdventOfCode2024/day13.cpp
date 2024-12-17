#include "day13.h"
#include "day2.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

int countWinCombos(const std::string& path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("no file");
	std::string line;
	std::pair<int, int> buttonA;
	std::pair<int, int> buttonB;
	int result = 0;
	while (std::getline(file, line))
	{
		if (line.substr(0, 6) == "Button")
		{
			if (line[7] == 'A')
			{
				int first = std::stoi(line.substr(line.find_first_of("0123456789",7) , line.find_first_not_of("0123456789", 7)));
				int off = line.find_first_not_of("0123456789", line.find_first_of("0123456789", 7));
				int sec = std::stoi(line.substr(line.find_first_of("0123456789", off)));
				buttonA = { first,sec };
			}
			else if (line[7] == 'B')
			{
				int first = std::stoi(line.substr(line.find_first_of("0123456789", 7), line.find_first_not_of("0123456789", 7)));
				int off = line.find_first_not_of("0123456789", line.find_first_of("0123456789", 7));
				int sec = std::stoi(line.substr(line.find_first_of("0123456789", off)));
				buttonB = { first,sec };
			}
		}
		if (line.substr(0, 5) == "Prize")
		{
			int first = std::stoi(line.substr(9, line.find_first_not_of("0123456789", 9)));
			int sec = std::stoi(line.substr(line.find_first_of("0123456789", line.find_first_not_of("0123456789", 9))));
			std::pair<long long int, long long int> dest = { first + 10000000000000,sec + 10000000000000 };
			std::set<std::pair<int, int>> vars;
			int maxA = std::max(dest.first / buttonA.first, dest.second / buttonA.second);
			int maxB = std::max(dest.first / buttonB.first, dest.second / buttonB.second);
			for (int a = 0; a < maxA; a++)
			{
				for (int b = maxB; b >= 0; b--)
				{
					std::pair<long long int, long long int> curr = { buttonA.first * a + buttonB.first * b,buttonA.second * a + buttonB.second * b };
					if (curr == dest)
						vars.insert({ a,b });
				}
			}
			//foundPosVar(buttonA, 0, buttonB, 0, start, dest, vars);
			std::cout << vars.size() << std::endl;
			if (vars.size() > 0)
			{
				std::vector<int> tokens;
				for (auto i = vars.begin(); i != vars.end(); i++)
				{
					
					tokens.push_back((*i).first * 3 + (*i).second);
				}
				result += *std::min_element(tokens.begin(), tokens.end());
			}
		}
	}
	return result;
}

void foundPosVar(std::pair<int, int>& buttonA, int Acount, std::pair<int, int>& buttonB,int Bcount,std::pair<int,int>& currPos, std::pair<int,int>& winPos, std::set<std::pair<int, int>>& win)
{
	if (currPos == winPos)
	{
		if (!win.contains({ Acount,Bcount })) win.insert({ Acount,Bcount });
		return;
	}
	if (currPos.first > winPos.first || currPos.second > winPos.second)
	{
		return;
	}
	std::pair<int, int> Apos = { currPos.first + buttonA.first,currPos.second + buttonA.second };
	std::pair<int, int> Bpos = { currPos.first + buttonB.first,currPos.second + buttonB.second };
	foundPosVar(buttonA, Acount + 1, buttonB, Bcount, Apos, winPos, win);
	foundPosVar(buttonA, Acount, buttonB, Bcount + 1, Bpos, winPos, win);
}
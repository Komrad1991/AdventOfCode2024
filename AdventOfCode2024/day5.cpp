#include "day5.h"
#include <fstream>
#include <map>
#include <set>
#include <iostream>
#include <vector>

int sumOfMiddle(std::string path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("no file");
	std::string rule;
	std::map<int, std::set<int>> setOfRules;
	while (std::getline(file, rule) && rule.size() > 0)
	{
		int left = std::stoi(rule.substr(0, 2));
		int right = std::stoi(rule.substr(3, 2));
		if (!setOfRules.contains(left))
		{
			std::set temp = { right };
			setOfRules.insert({ left,temp });
		}
		else setOfRules[left].insert(right);
	}
	//for (auto& x : setOfRules)
	//{
	//	for (auto& y : x.second)
	//	{
	//		std::cout << x.first << "|" << y << std::endl;
	//	}
	//}
	std::string line;
	int res = 0;
	while (std::getline(file, line) && line.size() > 0)
	{
		std::vector<int> nums = parseLineComa(line);
		bool right = true;
		for (int i = 0; i < nums.size(); i++)
		{
			if (setOfRules.contains(nums[i]))
			{
				for (int j = i - 1; j >= 0; j--)
				{
					if (setOfRules[nums[i]].contains(nums[j])) right = false;
				}
			}
		}
		if (right)
		{
			res += nums[nums.size() / 2];
		}
		
	}
	return res;
}

std::vector<int> parseLineComa(std::string str)
{
	std::vector<int> ret;
	size_t pos = 0;
	while ((pos = str.find_first_not_of(", ", pos)) != str.npos)
	{
		size_t nextSpace = str.find_first_of(", ", pos) - pos;
		std::string temp = str.substr(pos, nextSpace);
		ret.push_back(std::stoi(temp));
		pos = str.find_first_of(", ", pos);
	}
	return ret;
}

int sumOfMiddle2(std::string path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("no file");
	std::string rule;
	std::map<int, std::set<int>> setOfRules;
	while (std::getline(file, rule) && rule.size() > 0)
	{
		int left = std::stoi(rule.substr(0, 2));
		int right = std::stoi(rule.substr(3, 2));
		if (!setOfRules.contains(left))
		{
			std::set temp = { right };
			setOfRules.insert({ left,temp });
		}
		else setOfRules[left].insert(right);
	}
	std::string line;
	int res = 0;
	while (std::getline(file, line) && line.size() > 0)
	{
		std::vector<int> nums = parseLineComa(line);
		bool right = true;
		
		if (!checkRight(nums,setOfRules))
		{
			while (!checkRight(nums, setOfRules)){}
			res += nums[nums.size() / 2];
		}

	}
	return res;
}

bool checkRight(std::vector<int>& nums,std::map<int, std::set<int>>& setOfRules)
{
	for (int i = 0; i < nums.size(); i++)
	{
		if (setOfRules.contains(nums[i]))
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (setOfRules[nums[i]].contains(nums[j]))
				{
					auto temp = nums[j];
					nums.erase(nums.begin() + j);
					nums.insert(nums.begin() + i, temp);
					return false;
				}
			}
		}
	}
	return true;
}
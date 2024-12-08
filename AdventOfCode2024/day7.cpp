#include "day7.h"
#include <iostream>
#include <fstream>
#include <string>
#include "day2.h"
#include <vector>

long long int tryAllPoses(std::string path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("no file");
	std::string temp;
	long long int count = 0;
	while (std::getline(file, temp))
	{
		auto substr = temp.substr(0, temp.find_first_of(':'));
		double sum = std::stod(substr);
		std::vector<long long int> nums = parseLineDouble(temp.substr(temp.find_first_of(':') + 1));
		if (possiblyTrueConcat(nums, nums[0], 1, sum)) 
		{
			count += sum;
		}
	}
	return count;
}

bool possiblyTrue(std::vector<double> nums, double sum, double index,double res)
{
	if (index >= nums.size() - 1) {
		if (sum + nums[index] == res) return true;
		else if (sum * nums[index] == res) return true;
		else return false;
	}
	else return possiblyTrue(nums, sum + nums[index], index + 1, res) || possiblyTrue(nums, sum * nums[index], index + 1, res);
}

bool possiblyTrueConcat(std::vector<long long int> nums, long long int sum, long long int index, long long int res)
{
	if (index >= nums.size() - 1) {
		if (sum + nums[index] == res) return true;
		else if (sum * nums[index] == res) return true;
		else if (std::stoll(std::to_string(sum) + std::to_string(nums[index])) == res) return true;
		else return false;
	}
	else return possiblyTrueConcat(nums, sum + nums[index], index + 1, res) ||
		possiblyTrueConcat(nums, sum * nums[index], index + 1, res) ||
		possiblyTrueConcat(nums, std::stoll(std::to_string(sum) + std::to_string(nums[index])), index + 1, res);
}


std::vector<long long int> parseLineDouble(std::string str)
{
	std::vector<long long int> ret;
	size_t pos = 0;
	while ((pos = str.find_first_not_of(' ', pos)) != str.npos)
	{
		size_t nextSpace = str.find_first_of(' ', pos) - pos;
		std::string temp = str.substr(pos, nextSpace);
		ret.push_back(std::stod(temp));
		pos = str.find_first_of(' ', pos);
	}
	return ret;
}
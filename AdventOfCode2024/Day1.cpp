#include "Day1.h"
#include <fstream>
#include "math.h"
#include <vector>
#include <iostream>

int mesureDist(std::string path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("no file");
	std::vector<int> vec1;
	std::vector<int> vec2;
	while (!file.eof())
	{
		std::string temp_str;
		std::getline(file, temp_str);
		std::vector<std::string> temp = split(temp_str);
		int first = std::stoi(temp[0]);
		int sec = std::stoi(temp[1]);
		std::cout << first << " " << sec << std::endl;
		vec1.push_back(first);
		vec2.push_back(sec);
	}
	int res = 0;
	int size = vec1.size();
	for (int i = 0; i < size; i++)
	{
		auto left_min = std::min_element(vec1.begin(), vec1.end());
		auto right_min = std::min_element(vec2.begin(), vec2.end());
		res += abs(*left_min - *right_min);
		vec1.erase(left_min);
		vec2.erase(right_min);
	}
	return res;

}

int mesureDist2(std::string path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("no file");
	std::vector<int> vec1;
	std::vector<int> vec2;
	while (!file.eof())
	{
		std::string temp_str;
		std::getline(file, temp_str);
		std::vector<std::string> temp = split(temp_str);
		int first = std::stoi(temp[0]);
		int sec = std::stoi(temp[1]);
		std::cout << first << " " << sec << std::endl;
		vec1.push_back(first);
		vec2.push_back(sec);
	}
	int res = 0;
	int size = vec1.size();
	for (int i = 0; i < size; i++)
	{
		auto left_min = std::min_element(vec1.begin(), vec1.end());
		auto right_ñount = std::count(vec2.begin(), vec2.end(), *left_min);
		res += abs(*left_min * right_ñount);
		vec1.erase(left_min);
	}
	return res;

}

std::vector<std::string> split(std::string str)
{
	std::vector<std::string> res;
	size_t pos;
	while ((pos = str.find_first_not_of(" ")) != std::string::npos) 
	{
		auto token = str.substr(pos, str.find_first_of(" ",pos));
		res.push_back(token);
		str.erase(pos, str.find_first_of(" ",pos));
	}
	return res;
}
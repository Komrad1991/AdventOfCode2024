#include "day14.h"
#include <string>
#include <fstream>
#include <vector>
#include <regex>
#include <iostream>
#include <algorithm>

long long int countRobotsInQuadrants(const std::string& input)
{
	std::fstream file;
	file.open(input);
	if (file.fail()) throw std::exception("no file");
	std::string line;
	std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> robots;
	long long int second = 0;
	long long int sec= INT_MAX;
	while (std::getline(file, line) && line.size() > 0)
	{
		robots.push_back(parseRobotLine(line));
	}
	for (int x = 0; x < 1000000; x++)
	{
		for (int i = 0; i < 1; i++)
		{
			simulate_robots(robots, 101, 103);
			int q1 = 0;
			int q2 = 0;
			int q3 = 0;
			int q4 = 0;
			for (auto& robot : robots)
			{
				if ((robot.first.first < 101 / 2) && (robot.first.second < 103 / 2)) q1++;
				if ((robot.first.first > 101 / 2) && (robot.first.second < 103 / 2)) q2++;
				if ((robot.first.first < 101 / 2) && (robot.first.second > 103 / 2)) q3++;
				if ((robot.first.first > 101 / 2) && (robot.first.second > 103 / 2)) q4++;
			}
			if (q1 * q2 * q3 * q4 < sec)
			{
				sec = q1 * q2 * q3 * q4;
				second = x;
				printRobots(robots, 101, 103);
				std::cout << "second: " << second << std::endl;
			}
		}
		
	}
	return second;
}


std::pair<std::pair<int, int>, std::pair<int, int>> parseRobotLine(std::string& line)
{
	std::regex r(R"(\-?\d+)");
	std::pair<std::pair<int, int>, std::pair<int, int>> out = { {0,0},{0,0} };
	std::smatch x;
	std::smatch y;
	std::smatch vx;
	std::smatch vy;
	std::regex_search(line, x, r);
	out.first.first = std::stoi(x.str());
	auto next = x.suffix().str();
	std::regex_search(next, y, r);
	out.first.second = std::stoi(y.str());
	next = y.suffix().str();
	std::regex_search(next, vx, r);
	out.second.first = std::stoi(vx.str());
	next = vx.suffix().str();
	std::regex_search(next, vy, r);
	out.second.second = std::stoi(vy.str());
	return out;
}

void simulate_robots(std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>& robots, int xBound,int yBound)
{
	for (auto& robot : robots)
	{
		int new_x = robot.first.first + robot.second.first;
		if (new_x >= xBound) robot.first.first = new_x - xBound;
		else if (new_x < 0) robot.first.first = xBound + new_x;
		else robot.first.first = new_x;
		int new_y = robot.first.second + robot.second.second;
		if (new_y >= yBound) robot.first.second = new_y - yBound;
		else if (new_y < 0) robot.first.second = yBound + new_y;
		else robot.first.second = new_y;
	}
}

void printRobots(std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>& robots, int xBound,int yBound)
{
	std::vector<std::string> field;
	for (int i = 0; i < xBound; i++)
	{
		field.push_back(std::string(yBound, '.'));
	}
	for (auto& x : robots)
	{
		field[x.first.first][x.first.second] = 'x';
	}
	for (int i = 0; i < field.size(); i++)
	{
		std::cout << field[i] << std::endl;
	}
}
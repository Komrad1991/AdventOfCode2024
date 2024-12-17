#pragma once
#include <string>
#include <vector>

std::pair<std::pair<int, int>, std::pair<int, int>> parseRobotLine(std::string& line);

long long int countRobotsInQuadrants(const std::string& input);

void simulate_robots(std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>& robots, int xBound, int yBound);

void printRobots(std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>& robots, int xBound, int yBound);
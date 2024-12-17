#pragma once
#include <string>
#include <vector>
#include <set>

std::pair<int, int> calculateArea(int x, int y, char ch, std::vector<std::string>& map, std::set<std::pair<int, int>>& set);

std::pair<int, int> calculateSides(int x, int y, char ch, std::vector<std::string>& map, std::set<std::pair<int, int>>& set);

long int calculateFence(const std::string& path);

bool inBound(int val, int zero, int size);
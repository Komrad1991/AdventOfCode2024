#pragma once
#include <string>
#include <vector>

int howLongPath(std::string path);

bool move(std::vector<std::string>& map);

void printMap(std::vector<std::string>& map);

int howManyLoops(std::string path);

bool loops(std::vector<std::string>& map);
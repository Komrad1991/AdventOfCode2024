#pragma once
#include <string>
#include <set>
#include <vector>

int countTrailHeads(std::string path);

void calculatePath(int x, int y, std::set<std::pair<int,int>>& sets,int value,std::vector<std::string> map);

void calculatePath2(int x, int y, std::vector<std::pair<int,int>>& trails, int value, std::vector<std::string> map);

int countTrailHeads2(std::string path);
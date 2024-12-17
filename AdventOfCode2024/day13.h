#pragma once
#include <string>
#include <set>

long long int countWinCombos(const std::string& path);

void foundPosVar(std::pair<int, int>& buttonA, int Acount, std::pair<int, int>& buttonB, int Bcount, std::pair<int, int>& currPos, std::pair<int, int>& winPos, std::set<std::pair<int, int>>& win);
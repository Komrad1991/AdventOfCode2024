#include "day3.h"
#include <fstream>
#include <regex>
#include <iostream>
#include <string>

int doMult(std::string path)
{
	std::fstream file;
	file.open(path);
	if (file.fail()) throw std::exception("no file");
	int res = 0;
	std::string temp;
	bool enable = true;
	while (std::getline(file, temp))
	{
		std::regex combined(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");
		std::regex dis(R"(don't\(\))");
		std::regex en(R"(do\(\))");
		std::regex reg(R"(mul\((\d+)+,(\d+)+\))");
		std::smatch sm;
		
		while (std::regex_search(temp, sm, combined))
		{
			if (std::regex_match(sm.str(), en)) {
				enable = true;
			}
			else if (std::regex_match(sm.str(), dis)) {
				enable = false;
			}
			else if (enable) {
				int f = std::stoi(sm[1].str());
				int s = std::stoi(sm[2].str());
				res += f * s;
			}
			temp = sm.suffix().str();
		}

	}

	return res;
}
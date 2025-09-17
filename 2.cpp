#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main() {
    std::ifstream infile("input.txt");
    std::string line;
    std::regex pattern(R"(\d+)");
    
    int safe_count = 0;
    while (std::getline(infile, line)) {
        std::vector<int> numbers_on_line;
        std::smatch match;
        if (std::regex_match(line, match, pattern)) {
            numbers_on_line.push_back(std::stoi(match[1]));
            numbers_on_line.push_back(std::stoi(match[2]));
        }
    }
    return 0;
}
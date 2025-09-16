
#include <fstream>
#include <vector>
#include <string>
#include <regex>

int main() {

    // Set up vectors to hold the numbers
	std::vector<int> left, right;

    // Create regex to extract numbers
	std::regex pattern(R"((\d+)\s+(\d+))");

    // Read and parse the input file
	std::ifstream infile("input.txt");

    // String to hold lines in file
    std::string line;
	
    // Read each line and extract numbers with regex
    while (std::getline(infile, line)) {
		std::smatch match;
		if (std::regex_match(line, match, pattern)) {
			left.push_back(std::stoi(match[1]));
			right.push_back(std::stoi(match[2]));
		}
	}

    return 0;
}

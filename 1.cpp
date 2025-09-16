
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <algorithm>

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

  // Sort vectors
  std::sort(left.begin(), left.end());
  std::sort(right.begin(), right.end());

  // Check if vectors are of equal size
  int n = std::min(left.size(), right.size());
  
  // Calculate the sum of absolute differences
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += std::abs(left[i] - right[i]);
  }

  std::cout << "Sum: " << sum << std::endl;

  return 0;
}

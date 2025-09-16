#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

// 2. For each number in the left vector, count how many times it appears in
// the right vector

std::vector<int> get_counts(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> counts;
    for (int value : left) {
        counts.push_back(std::count(right.begin(), right.end(), value));
    }
    return counts;
}

int main() {
  std::vector<int> left, right;
  std::regex pattern(R"((\d+)\s+(\d+))");
  std::ifstream infile("input.txt");
  std::string line;

  while (std::getline(infile, line)) {
    std::smatch match;
    if (std::regex_match(line, match, pattern)) {
      left.push_back(std::stoi(match[1]));
      right.push_back(std::stoi(match[2]));
    }
  }

  // 3. For each such number, multiply the left number by its count in the right
  // vector
  std::vector<int> counts = get_counts(left, right);
  std::vector<int> products;
  for (int i = 0; i < left.size(); ++i) {
    products.push_back(left[i] * counts[i]);
  }

  // 4. Sum all these products to get the similarity score

  // 5. Output the similarity score

  // 6. (Optional) Optimize counting with a hash map for the right vector
}
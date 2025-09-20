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
    int safe_reports = 0;

    // Read each line from the input file
    while (std::getline(infile, line)) {
        
        // Store all numbers found in the current line
        std::vector<int> numbers_on_line;
        
        // smatch will hold the result of each regex search
        std::smatch match;
        
        // s is a copy of the line, which we will shrink as we find matches
        std::string s = line;
        
        // Loop to find all numbers in the line using regex_search
        while (std::regex_search(s, match, pattern)) {
            // match[0] contains the matched number as a string
            numbers_on_line.push_back(std::stoi(match[0]));
            
            // match.suffix() gives the part of the string after the current match
            // We assign it to s to continue searching for more numbers
            s = match.suffix();
        }

        // If we found any numbers, check if the report is safe
        if (!numbers_on_line.empty()) {
            
            // Flags to track if the sequence is strictly increasing or decreasing
            bool is_increasing = true, is_decreasing = true;
            for (int i = 1; i < (int)numbers_on_line.size(); ++i) {
                int diff = numbers_on_line[i] - numbers_on_line[i-1];
                
                // If the difference is not between 1 and 3, it's not safe
                if (abs(diff) < 1 || abs(diff) > 3) {
                    is_increasing = false;
                    is_decreasing = false;
                    break;
                }
                
                // If any step is decreasing, it's not increasing
                if (diff < 0) is_increasing = false;
                // If any step is increasing, it's not decreasing
                if (diff > 0) is_decreasing = false;
            }

            // If the sequence is all increasing or all decreasing, count as safe
            if (is_increasing || is_decreasing) ++safe_reports;
        }
    }
    std::cout << safe_reports << std::endl;
    return 0;
}
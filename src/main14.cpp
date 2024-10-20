#include "main14.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    using namespace homework;

    // Test with integers
    std::vector<int> vint = {1, 2, 3, 4, 5};
    auto sum_ints = sum_elements(vint);
    std::cout << "Sum of integers: " << sum_ints << std::endl;

    // Test with doubles
    std::vector<double> vdouble = {1.1, 2.2, 3.3, 4.4, 5.5};
    auto sum_doubles = sum_elements(vdouble, 0.0);
    std::cout << "Sum of doubles: " << sum_doubles << std::endl;

    // Test with strings
    std::vector<std::string> vstring = {"hello", "world"};
    auto sum_strings = sum_elements(vstring, std::string());
    std::cout << "Concatenated string: " << sum_strings << std::endl;

    return 0;
}

#include "main15.h"
#include <iostream>
#include <cmath>    // For std::fabs
#include <cassert>  // For assert

int main() {
    using namespace homework;

    // Demonstrate Pair Class Template
    std::cout << "Demonstrating Pair class template:\n";

    Pair<int, int> intPair{1, 2};
    std::cout << "Pair<int, int>: (" << intPair.first << ", " << intPair.second << ")\n";

    Pair<double, double> doublePair{1.1, 2.2};
    std::cout << "Pair<double, double>: (" << doublePair.first << ", " << doublePair.second << ")\n";

    Pair<int, std::string> intStringPair{42, "Hello World"};
    std::cout << "Pair<int, std::string>: (" << intStringPair.first << ", " << intStringPair.second << ")\n\n";

    // Demonstrate Transform Function Template
    std::cout << "Demonstrating transform function:\n";

    // Transform a vector of integers by doubling each element
    std::vector<int> intVec{1, 2, 3, 4, 5};
    transform(intVec, [](int x) { return x * 2; });
    std::cout << "Transformed vector<int> (doubled): ";
    for (const auto& val : intVec) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Transform a vector of strings by reversing each string
    std::vector<std::string> stringVec{"Hello", "World"};
    transform(stringVec, [](std::string s) {
        std::reverse(s.begin(), s.end());
        return s;
    });
    std::cout << "Transformed vector<string> (reversed): ";
    for (const auto& val : stringVec) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Transform a list of integers by squaring each element
    std::list<int> intList{1, 2, 3};
    transform(intList, [](int x) { return x * x; });
    std::cout << "Transformed list<int> (squared): ";
    for (const auto& val : intList) {
        std::cout << val << " ";
    }
    std::cout << "\n\n";

    // Demonstrate IsRawPointer Class Template
    std::cout << "Demonstrating IsRawPointer class template:\n";

    // Check various types
    std::cout << "IsRawPointer<int>::value: " << IsRawPointer<int>::value << "\n";
    std::cout << "IsRawPointer<int*>::value: " << IsRawPointer<int*>::value << "\n";
    std::cout << "IsRawPointer<const int*>::value: " << IsRawPointer<const int*>::value << "\n";
    std::cout << "IsRawPointer<int&>::value: " << IsRawPointer<int&>::value << "\n";
    std::cout << "IsRawPointer<std::string>::value: " << IsRawPointer<std::string>::value << "\n";

    // Additional demonstration with double pointer
    std::cout << "IsRawPointer<double*>::value: " << IsRawPointer<double*>::value << "\n";

    // Pause the console (optional, for Windows users)
    // system("pause");

    return 0;
}

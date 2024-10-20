#include "main13.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace homework;

    // Test the split function
    std::string testStr = "  hello   world  hi prof ";
    std::vector<std::string> words = split(testStr);

    std::cout << "Testing split function:\n";
    std::cout << "Original string: \"" << testStr << "\"\n";
    std::cout << "Split words:\n";
    for (const auto& word : words) {
        std::cout << "\"" << word << "\"\n";
    }

    // Check if the split function works as expected
    if (words.size() == 4 &&
        words[0] == "hello" &&
        words[1] == "world" &&
        words[2] == "hi" &&
        words[3] == "prof") {
        std::cout << "Split function works correctly.\n\n";
    } else {
        std::cout << "Split function does not work correctly.\n\n";
    }

    // Test the MyType serialization
    MyType mt1(42, 3.14);
    std::string filename = "mytype.txt";

    try {
        // Write mt1 to a file
        writeToFile(mt1, filename);
        std::cout << "Serialized MyType object to file: " << filename << "\n";

        // Read mt2 from the file
        MyType mt2 = readFromFile(filename);
        std::cout << "Deserialized MyType object from file: " << filename << "\n";

        // Display the values
        std::cout << "Original MyType object: i = 42, d = 3.14\n";
        std::cout << "Deserialized MyType object: i = " << mt2.getI() << ", d = " << mt2.getD() << "\n";

        // Check if the objects are equal
        if (mt1 == mt2) {
            std::cout << "Serialization and deserialization work correctly.\n";
        } else {
            std::cout << "Serialization and deserialization do not work correctly.\n";
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}

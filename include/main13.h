#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

namespace homework {


    std::vector<std::string> split(const std::string& str) {
        std::vector<std::string> result;
        std::istringstream iss(str);  // Use istringstream to read from the string
        std::string word;
        while (iss >> word) {  // Extract words separated by whitespace
            result.push_back(word);
        }
        return result;
    }


    class MyType {
        private:
            int i;
            double d;

        public:
            MyType(int i = 0, double d = 0.0) : i(i), d(d) {
            }

            /**
             * @brief Equality operator
             */
            bool operator==(const MyType& other) const {
                return i == other.i && d == other.d;
            }

            // Friend declarations for stream operators
            friend std::ostream& operator<<(std::ostream& os, const MyType& mt);
            friend std::istream& operator>>(std::istream& is, MyType& mt);

            int getI() const { return i; }
            double getD() const { return d; }
    };


    std::ostream& operator<<(std::ostream& os, const MyType& mt) {
        os << mt.i << ' ' << mt.d;  // Write members separated by space
        return os;
    }


    std::istream& operator>>(std::istream& is, MyType& mt) {
        is >> mt.i >> mt.d;  // Read members from the stream
        return is;
    }


    void writeToFile(const MyType& mt, const std::string& filename) {
        std::ofstream ofs(filename);
        if (ofs) {
            ofs << mt;  // Use overloaded operator<<
        } else {
            throw std::runtime_error("Failed to open file for writing: " + filename);
        }
    }


    MyType readFromFile(const std::string& filename) {
        std::ifstream ifs(filename);
        if (ifs) {
            MyType mt;
            ifs >> mt;  // Use overloaded operator>>
            return mt;
        } else {
            throw std::runtime_error("Failed to open file for reading: " + filename);
        }
    }

} // namespace homework

#pragma once
#include <vector>
#include <numeric>
#include <type_traits>
#include <iostream>

namespace homework {


template<typename T>
T sum_elements(const std::vector<T>& vec, T init = T{}) {
    T sum = init;
    for (const auto& elem : vec) {
        if constexpr (std::is_same<T, std::string>::value) {
            std::cout << elem << std::endl;
        }
        sum += elem;
    }
    return sum;
}

} // namespace homework

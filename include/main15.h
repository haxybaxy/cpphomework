#pragma once

#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>

namespace homework {

    template<typename T1, typename T2>
    struct Pair {
        T1 first;
        T2 second;

        // Constructor
        Pair(const T1& first_val, const T2& second_val)
            : first(first_val), second(second_val) {}
    };


    template<typename Container, typename UnaryFunction>
    void transform(Container& container, UnaryFunction function) {
        for (auto& element : container) {
            element = function(element);
        }
    }


    template<typename T>
    struct IsRawPointer {
        static constexpr bool value = false;
    };

    // Partial specialization for pointer types
    template<typename T>
    struct IsRawPointer<T*> {
        static constexpr bool value = true;
    };

    // Partial specialization for const pointer types (redundant but explicit)
    template<typename T>
    struct IsRawPointer<const T*> {
        static constexpr bool value = true;
    };

} // namespace homework

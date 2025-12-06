#pragma once

#include <vector>
#include <algorithm>


enum class Keys {
    ENTER = 13,
    ARROW_UP = 72,
    ARROW_DOWN = 80,
    ARROW_LEFT = 75,
    ARROW_RIGHT = 77,
    ESCAPE = 27
};

namespace GeneralMethods {
    template <typename Container, typename T>
    static bool contains(const Container& c, const T& value) {
        return std::find(std::begin(c), std::end(c), value) != std::end(c);
    }
}

namespace GeneralConstants {

}

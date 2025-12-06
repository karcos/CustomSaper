#include "../../include/random/Random.h"


namespace 
{
    std::random_device rd;
    std::mt19937 gen(rd());
}

namespace Random
{
    int int_in_range(const int min, const int max) {
        std::uniform_int_distribution<> dist(min, max);
        return dist(gen);
    }

    float float_in_range(const float min, const float max) {
        std::uniform_real_distribution<float> dist(min, max);
        return dist(gen);
    }
}

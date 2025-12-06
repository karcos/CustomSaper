#pragma once
#include <random>


namespace Random
{
    [[nodiscard]] int int_in_range(int min, int max);
    [[nodiscard]] float float_in_range(float min, float max);
}

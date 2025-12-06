#pragma once


struct Coords final {
    int x, y;

    constexpr bool operator==(const Coords& other) const noexcept {
        return x == other.x and y == other.y;
    }
};

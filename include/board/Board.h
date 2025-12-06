#pragma once
#include <memory>
#include <vector>
#include <stdexcept>

#include "../coords/Coords.h"
#include "../tile/Tile.h"
#include "BoardConstants.h"


class Board final {
    Coords focused_tile_{ BoardConstants::focused_tile };

    const int width_{ BoardConstants::width };
    const int height_{ BoardConstants::height };
    std::vector<std::vector<std::unique_ptr<TileBase>>> board_;

    void open_req(const Coords& pos) noexcept;

public:
    Board() noexcept : board_(height_) {
        for (auto& row : board_) { row.resize(width_); }
    }

    Board(const int& width, const int& height) : width_(width), height_(height), board_(height_) {
        if (width_ <= 0 or height_ <= 0) throw std::invalid_argument("Board: width/height must be > 0");

        for (auto& row : board_) { row.resize(width_); }
    }

    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;
    Board(Board&&) = default;
    Board& operator=(Board&&) = delete;

    [[nodiscard]] int width() const noexcept { return width_; }
    [[nodiscard]] int height() const noexcept { return height_; }
    [[nodiscard]] TileBase& at(int x, int y);
    [[nodiscard]] const TileBase& at(int x, int y) const;
    [[nodiscard]] const Coords& focused_tile() const noexcept { return focused_tile_; }

    void mv_up() noexcept;
    void mv_down() noexcept;
    void mv_right() noexcept;
    void mv_left() noexcept;

    void generate(const float& chance_to_bomb = BoardConstants::d_chance_to_bomb);
    void open() noexcept;
    void toggle_flag() noexcept;
};











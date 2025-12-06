#pragma once

#include <memory>

#include "../board/Board.h"
#include "GameConstants.h"


class Game {
    Board board_;
    GameStatus status_{ GameConstants::status_ };

public:
    explicit Game() = default;

    const Board& board() const noexcept { return board_; }
    Board& board() noexcept { return board_; }
    GameStatus status() const noexcept { return status_; }
    void set_status(const GameStatus status) noexcept { status_ = status; }
};

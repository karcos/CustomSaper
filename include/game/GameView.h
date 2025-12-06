#pragma once

#include <memory>

#include "Game.h"


class GameView {
    std::weak_ptr<Game> game_;

public:
    explicit GameView(const std::shared_ptr<Game>& game) : game_(game) {}

    void print() const noexcept;
};
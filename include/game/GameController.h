#pragma once

#include <memory>
#include <string>

#include "../controller/Controller.h"
#include "../app_context/AppContext.h"
#include "Game.h"
#include "GameView.h"


class GameController final : public Controller {
    std::shared_ptr<Game> game_;
    std::shared_ptr<GameView> game_view_;

public:
    explicit GameController(const AppContext& ctx) :
        Controller(ctx),
        game_(std::make_shared<Game>()),
        game_view_(std::make_shared<GameView>(game_)) {}

    std::unique_ptr<Controller> run() override;
};
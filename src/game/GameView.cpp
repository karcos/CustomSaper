#include <iostream>
#include "../../include/game/GameView.h"
#include "../../include/coords/Coords.h"
#include "../../include/console_color/ConsoleColor.h"
#include "../../include/game/GameConstants.h"


void GameView::print() const noexcept {
    const auto game = game_.lock();

    if (game) {
        for (int i = 0; i < game->board().height(); i++) {
            for (int j = 0; j < game->board().width(); j++) {
                if (Coords({j, i}) == game->board().focused_tile()) {
                    ConsoleColor::set_text_color(GameViewConstants::focused_option_color);
                    std::cout << game->board().at(j, i);
                    ConsoleColor::reset();
                }
            }
        }
    }
}
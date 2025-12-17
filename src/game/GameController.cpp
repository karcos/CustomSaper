#include <memory>
#include <conio.h>
#include <string>

#include "../../include/controller/Controller.h"
#include "../../include/game/GameController.h"
#include "../../include/general_constants/GeneralConstants.h"


void GameController::handle_game_input(const int c) {
    switch (std::tolower(c)) {
        case 'w':
            game_->board().mv_up();
            break;

        case 's':
            game_->board().mv_down();
            break;

        case 'd':
            game_->board().mv_right();
            break;

        case 'a':
            game_->board().mv_left();
            break;

        case 'f':
            game_->board().toggle_flag();
            break;

        case static_cast<int>(Keys::ENTER):
            game_->board().open();
            break;

        case static_cast<int>(Keys::ESCAPE):
            game_->set_status(GameStatus::PAUSED);
            break;

        default:
            break;
    }
}

void handle_pause_input(const int c) {
    switch (std::tolower(c)) {
        case 'w':

            break;
        case 's':

            break;
        case 'd':

            break;
        case 'a':

            break;
    }
}

std::unique_ptr<Controller> GameController::run() {
    while (game_->status() == GameStatus::DURING) {
        system("cls");
        game_view_->print();

        const int c = _getch();


    }
    return nullptr;
}

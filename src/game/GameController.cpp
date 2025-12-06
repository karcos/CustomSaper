#include <memory>
#include <conio.h>
#include <string>

#include "../../include/controller/Controller.h"
#include "../../include/game/GameController.h"
#include "../../include/general_constants/GeneralConstants.h"


std::unique_ptr<Controller> GameController::run() {
    return nullptr;
    while (game_->status() == GameStatus::DURING) {
        system("cls");
        game_view_->print();

        const int c = std::tolower(_getch());

        switch (c) {
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

            case static_cast<int>(Keys::ENTER):
                game_->board().open();
                break;

            case 'f':
                game_->board().toggle_flag();
                break;

            default:
                break;
        }
    }
}
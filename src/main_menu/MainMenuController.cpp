#include <conio.h>
#include <memory>

#include "main_menu/MainMenuController.h"
#include "controller/Controller.h"
#include "general_constants/GeneralConstants.h"
#include "game/GameController.h"
#include "user_settings/UserSettingsController.h"


std::unique_ptr<Controller> MainMenuController::run() {
    while (true) {
        system("cls");
        main_menu_view_->print();

        const int c = _getch();

        switch (c) {
        case static_cast<int>(Keys::ARROW_UP):
        case 'w':
        case 'W':
            main_menu_->goto_previous_option();
            break;

        case static_cast<int>(Keys::ARROW_DOWN):
        case 's':
        case 'S':
            main_menu_->goto_next_option();
            break;

        case static_cast<int>(Keys::ENTER):
            switch (static_cast<MenuOptions>(main_menu_->get_focused_option())) {
            case MenuOptions::START:
                return std::make_unique<GameController>(ctx_);
            case MenuOptions::OPTIONS:
                return std::make_unique<UserSettingsController>(ctx_);
            case MenuOptions::EXIT:
                return nullptr;
            default:
                throw std::runtime_error("Unknown menu item");
            }

        default:
            break;
        }
    }
}

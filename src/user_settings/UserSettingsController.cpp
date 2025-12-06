#include <memory>
#include <conio.h>

#include "../../include/general_constants/GeneralConstants.h"
#include "../../include/user_settings/UserSettingsController.h"
#include "../../include/controller/Controller.h"
#include "../../include/main_menu/MainMenuController.h"


void UserSettingsController::run_resolution_editor() {
    int tmp_width = user_settings_->width(), tmp_height = user_settings_->height();
    bool error = false;

    while (true) {
        system("cls");

        if (error) { user_settings_view_->print_resolution_frame(tmp_width, tmp_height, "Wrong size of resolution!"); }
        else { user_settings_view_->print_resolution_frame(tmp_width, tmp_height); }

        error = false;

        const int c = _getch();

        switch (c) {
            case static_cast<int>(Keys::ARROW_UP):
            case 'w':
            case 'W':
                tmp_height--;
                break;

            case static_cast<int>(Keys::ARROW_DOWN):
            case 's':
            case 'S':
                tmp_height++;
                break;

            case static_cast<int>(Keys::ARROW_LEFT):
            case 'a':
            case 'A':
                tmp_width--;
                break;

            case static_cast<int>(Keys::ARROW_RIGHT):
            case 'd':
            case 'D':
                tmp_width++;
                break;

            case static_cast<int>(Keys::ENTER):
                if (user_settings_->set_height(tmp_height) and user_settings_->set_width(tmp_width)) { return; }
                error = true;
                break;
            case static_cast<int>(Keys::ESCAPE):
                return;

            default:
                break;
        }
    }
}

std::unique_ptr<Controller> UserSettingsController::run() {
    while (true) {
        system("cls");
        user_settings_view_->print();

        const int c = _getch();

        switch (c) {
            case 's':
            case 'S':
                user_settings_->goto_next_option();
                break;
            case 'w':
            case 'W':
                user_settings_->goto_previous_option();
                break;
            case static_cast<int>(Keys::ENTER):
                switch (static_cast<UserSettingsOptions>(user_settings_->get_focused_option())) {
                case UserSettingsOptions::APP_SIZE:
                    run_resolution_editor();
                    break;
                default:
                    break;
                }
            case 'a':
            case 'A':
                if (static_cast<UserSettingsOptions>(user_settings_->get_focused_option()) == UserSettingsOptions::VOLUME) {
                    user_settings_->volume_down();
                }
                break;
            case 'd':
            case 'D':
                if (static_cast<UserSettingsOptions>(user_settings_->get_focused_option()) == UserSettingsOptions::VOLUME) {
                    user_settings_->volume_up();
                }
            case static_cast<int>(Keys::ESCAPE):
                return std::make_unique<MainMenuController>(ctx_);
            default:
                break;
        }
    }
}

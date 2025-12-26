#include <iostream>

#include "MainMenuView.h"
#include "../../include/main_menu/MainMenuConstants.h"
#include "../console_color/ConsoleColor.h"

void MainMenuView::print() const noexcept {
    const std::shared_ptr<MainMenu> menu = main_menu_.lock();

    if (menu) {
        for (int i = 0; i < menu->options().size(); i++) {
            if (i == menu->get_focused_option()) { ConsoleColor::print_text(menu->options()[i], MainMenuConstants::focused_option_color); }
            else { std::cout << menu->options()[i]; }

            std::cout << std::endl;
        }
    }
}
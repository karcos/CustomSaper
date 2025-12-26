#include <iostream>

#include "../../include/console_color/ConsoleColor.h"
#include "../../include/user_settings/UserSettingsView.h"
#include "../../include/user_settings/UserSettingsConstants.h"


void UserSettingsView::print() const noexcept {
    const auto user_settings = user_settings_.lock();

    if (user_settings) {
        for (int i = 0; i < user_settings->options().size(); i++) {
            if (user_settings->get_focused_option() == i) { ConsoleColor::print_text(user_settings->options()[i], UserSettingsViewConstants::focused_option_color); }
            else { std::cout << user_settings->options()[i]; }

            std::cout << std::endl;
        }
    }
}

void UserSettingsView::print_resolution_frame(const int width, const int height, const std::string& message) const noexcept {
    const auto user_settings = user_settings_.lock();

    if (user_settings) {
        const std::string line_up = '+' + std::string(width - (message.size() / 2) - 1, '-') + message + std::string(width - (message.size() / 2) - 1, '-') + "+\n";
        const std::string middle = "|" + std::string(width - 2, ' ') + "|\n";
        const std::string line_down = '+' + std::string(width - 2, '-') + '+';

        std::cout << line_up;
        for (int i = 0; i < height; i++) {
            std::cout << middle;
        }
        std::cout << line_down;
    }

}

#pragma once

#include <memory>

#include "MainMenu.h"


class MainMenuView {
    const std::weak_ptr<MainMenu> main_menu_;
public:
    explicit MainMenuView(const std::shared_ptr<MainMenu>& main_menu) : main_menu_(main_menu) {}

    void print() const noexcept;
};

#pragma once

#include <memory>

#include "MainMenu.h"
#include "MainMenuView.h"
#include "../app_context/AppContext.h"
#include "../controller/Controller.h"


class MainMenuController final : public Controller {
    std::shared_ptr<MainMenu> main_menu_;
    std::shared_ptr<MainMenuView> main_menu_view_;
public:
    explicit MainMenuController(const AppContext& ctx) :
        Controller(ctx),
        main_menu_(std::make_shared<MainMenu>()),
        main_menu_view_(std::make_shared<MainMenuView>(main_menu_)) {}

    std::unique_ptr<Controller> run() override;
};
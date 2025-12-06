#pragma once

#include <memory>

#include "UserSettingsView.h"
#include "../controller/Controller.h"
#include "../app_context/AppContext.h"
#include "../user_settings/UserSettings.h"


class UserSettingsController final : public Controller {
    std::shared_ptr<UserSettings> user_settings_;
    std::shared_ptr<UserSettingsView> user_settings_view_;

    void run_resolution_editor();
public:
    explicit UserSettingsController(const AppContext& ctx) :
        Controller(ctx),
        user_settings_(std::make_shared<UserSettings>()),
        user_settings_view_(std::make_shared<UserSettingsView>(user_settings_)) {}

    std::unique_ptr<Controller> run() override;
};


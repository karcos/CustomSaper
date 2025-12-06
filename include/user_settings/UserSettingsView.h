#pragma once

#include <memory>
#include <string>

#include "UserSettings.h"
#include "UserSettingsConstants.h"


class UserSettingsView final {
    const std::weak_ptr<UserSettings> user_settings_;
public:
    explicit UserSettingsView(const std::shared_ptr<UserSettings>& user_settings) : user_settings_(user_settings) {}

    void print() const noexcept;
    void print_resolution_frame(int width, int height, const std::string& message = UserSettingsViewConstants::message) const noexcept;
};

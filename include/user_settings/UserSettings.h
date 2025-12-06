#pragma once

#include <vector>
#include <string>

#include "UserSettingsConstants.h"
#include "../selectable_list_base/SelectableListBase.h"


class UserSettings final : public SelectableListBase{
    Language language_{ UserSettingsConstants::language };
    int volume_{ UserSettingsConstants::volume };
    int width_{ UserSettingsConstants::min_width };
    int height_{ UserSettingsConstants::min_height };

public:
    explicit UserSettings(const std::vector<std::string>& options = UserSettingsConstants::options) : SelectableListBase(options) {}

    void set_language(const Language l) noexcept { language_ = l; }
    void volume_up() noexcept { if (volume_ < UserSettingsConstants::max_volume) { volume_++; } }
    void volume_down() noexcept { if (volume_ > UserSettingsConstants::min_volume) { volume_--; } }
    void more_width() noexcept { if (width_ < UserSettingsConstants::max_width) { width_++; } }
    void less_width() noexcept { if (width_ > UserSettingsConstants::min_width) { width_--; } }
    void more_height() noexcept { if (height_ < UserSettingsConstants::max_height) { height_++; } }
    void less_height() noexcept { if (height_ > UserSettingsConstants::min_height) { height_--; } }
    bool set_width(const int w) noexcept {
        if (w <= UserSettingsConstants::max_width and w >= UserSettingsConstants::min_width) {
            width_ = w;
            return true;
        }
        return false;
    }

    bool set_height(const int h) noexcept {
        if (h <= UserSettingsConstants::max_height and h >= UserSettingsConstants::min_height) {
            height_ = h;
            return true;
        }
        return false;
    }

    int width() const noexcept { return width_; }
    int height() const noexcept { return height_; }
    Language language() const noexcept { return language_; }
};

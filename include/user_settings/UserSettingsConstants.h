#pragma once

#include <vector>
#include <string>
#include <cstdint>


enum class Language {
    Polish,
    English,
    Germany,
    French,
    Ukrainian,
    Russian
};

enum class UserSettingsOptions {
    VOLUME,
    APP_SIZE
};

namespace UserSettingsConstants {
    constexpr int min_width{ 20 };
    constexpr int min_height{ 20 };
    constexpr int max_width{ 100 };
    constexpr int max_height{ 100 };
    constexpr int min_volume{ 0 };
    constexpr int max_volume{ 100 };

    constexpr auto language{ Language::English };
    constexpr int volume{ 50 };

    const std::vector<std::string> options{ "Volume", "App size" };
}

namespace UserSettingsViewConstants {
    constexpr std::uint32_t focused_option_color{ 0x98ff8f };
    const std::string message{ "'Enter' for apply, 'Esc' for quit" };
}
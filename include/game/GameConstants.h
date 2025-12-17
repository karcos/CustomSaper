#pragma once

#include "../general_constants/GeneralConstants.h"
#include <cstdint>

enum class GameStatus {
    LOSE,
    WIN,
    DURING,
    PAUSED
};

namespace GameConstants {
    constexpr auto status_{ GameStatus::DURING };
}

namespace GameViewConstants {
    constexpr std::uint32_t focused_option_color{ 0x98ff8f };
}

namespace GameControllerConstants {
    // constexpr Keys up =
}

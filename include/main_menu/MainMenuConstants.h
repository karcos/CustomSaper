#pragma once

#include <cstdint>
#include <vector>
#include <string>


enum class MenuOptions {
	START,
	OPTIONS,
	EXIT
};

namespace MainMenuConstants {
	constexpr std::uint32_t focused_option_color{ 0x98ff8f };
	constexpr int focused_option{ 0 };
	const std::vector<std::string> options{ "Start", "Options", "Exit" };
}
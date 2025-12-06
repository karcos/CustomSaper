#pragma once
#include <string>

#include <cstdint>
#include "../coords/Coords.h"


namespace BoardConstants {
	constexpr Coords focused_tile = { 0, 0 };
	constexpr int width = 10;
	constexpr int height = 10;
	constexpr float d_chance_to_bomb = 0.1f;

	constexpr int min_bombs = 1;
	constexpr int max_bombs = 3;
	static const int space_to_show = static_cast<int>(std::to_string(max_bombs * 8).size()) + 1;

	constexpr std::uint32_t focused_tile_text_color = 0xff3df8;
	constexpr std::uint32_t focused_tile_bg_color = 0x3dff44;
}
#pragma once

#include <unordered_map>


enum class TileType {
	TileBase,
	TileBomb,
	TileNumber
};

namespace TileConstants {
	constexpr auto closed_mark{ u8"\u25A0" };
	constexpr auto flag_mark{ u8"\u2690" };

	namespace TileBase {
		constexpr bool is_open{ false };
		constexpr bool is_flagged{ false };
		constexpr auto opened_mark{ " " };
	}

	namespace TileBomb {
		constexpr bool is_open{ false };
		constexpr bool is_flagged{ false };
		constexpr bool explode{ false };
		constexpr int bombs{ 1 };
		constexpr auto opened_mark_no_explosion{ u8"\u00F0" };
		constexpr auto opened_mark_wh_explosion{ u8"\u2739" };
	}

	namespace TileNumber {
		constexpr bool is_open{ false };
		constexpr bool is_flagged{ false };
		constexpr int bombs{ 1 };
		constexpr int to_add_default{ 1 };
		const std::unordered_map<int, const char*> opened_marks = {
			{1, u8"\u2022"},
			{2, u8"\u205A"},
			{3, u8"\u22EE"},
			{4, u8"\u2E2C"}
		};
	}
}

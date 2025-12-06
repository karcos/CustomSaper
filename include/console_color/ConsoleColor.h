#pragma once
#include <cstdint>
#include <string>


namespace ConsoleColor {
	void set_text_color(std::uint32_t hex_color);
	void set_background_color(std::uint32_t hex_color);
	void set_colors(std::uint32_t text_hex_color, std::uint32_t bg_hex_color);
	void print_text(const std::string& text, std::uint32_t text_hex_color, std::uint32_t bg_hex_color = 0x000000);
	void reset();
}
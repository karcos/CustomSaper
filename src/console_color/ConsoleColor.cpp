#include "../../include/console_color/ConsoleColor.h"
#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif


namespace {
    bool g_ansi_initialized = false;

#ifdef _WIN32
    WORD g_initial_wAttributes = 0;
    bool g_have_initial_attr = false;
#endif

    void auto_reset() {
#ifdef _WIN32
        if (g_have_initial_attr) {
            const HANDLE& hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            if (hOut != INVALID_HANDLE_VALUE) {
                SetConsoleTextAttribute(hOut, g_initial_wAttributes);
                return;
            }
        }
#endif
        std::cout << "\033[0m";
    }

    void init_ansi() {
        if (g_ansi_initialized) { return; }
        g_ansi_initialized = true;

#ifdef _WIN32
        const HANDLE& hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut != INVALID_HANDLE_VALUE) {
   
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            if (GetConsoleScreenBufferInfo(hOut, &csbi)) {
                g_initial_wAttributes = csbi.wAttributes;
                g_have_initial_attr = true;
            }

            DWORD dwMode = 0;
            if (GetConsoleMode(hOut, &dwMode)) {
                SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
            }
        }
#endif

        std::atexit(auto_reset);
    }

    unsigned r(const std::uint32_t c) { return (c >> 16) & 0xFFu; }
    unsigned g(const std::uint32_t c) { return (c >> 8) & 0xFFu; }
    unsigned b(const std::uint32_t c) { return (c) & 0xFFu; }
}

namespace ConsoleColor {
    void init() { init_ansi(); }

    void set_text_color(const std::uint32_t hex_color) {
        init_ansi();
        std::cout << "\033[38;2;" << r(hex_color) << ';' << g(hex_color) << ';' << b(hex_color) << 'm';
    }

    void set_background_color(const std::uint32_t hex_color) {
        init_ansi();
        std::cout << "\033[48;2;" << r(hex_color) << ';' << g(hex_color) << ';' << b(hex_color) << 'm';
    }

    void set_colors(const std::uint32_t text_hex_color, const std::uint32_t bg_hex_color) {
        set_text_color(text_hex_color);
        set_background_color(bg_hex_color);
    }

    void print_text(const std::string& text, const std::uint32_t text_hex_color, const std::uint32_t bg_hex_color) {
        set_colors(text_hex_color, bg_hex_color);
        std::cout << text;
        reset();
    }

    void reset() {
        init_ansi();

#ifdef _WIN32

        if (g_have_initial_attr) {
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            if (hOut != INVALID_HANDLE_VALUE) {
                SetConsoleTextAttribute(hOut, g_initial_wAttributes);
                return;
            }
        }
#endif
        std::cout << "\033[0m";
    }
}

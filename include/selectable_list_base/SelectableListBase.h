#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include <limits>

class SelectableListBase {
protected:
    int focused_option_{ 0 };
    std::vector<std::string> options_;
public:
    virtual ~SelectableListBase() = default;
    explicit SelectableListBase(const std::vector<std::string>& options) : options_(options) {
        if (options_.size() > std::numeric_limits<int>::max()) { throw std::out_of_range("Options must have size lower or equal INT_MAX"); }
        if (options_.empty()) { throw std::invalid_argument("Options must not be empty"); }
    }

    [[nodiscard]] int get_focused_option() const noexcept { return focused_option_; }
    [[nodiscard]] const std::vector<std::string>& options() const noexcept { return options_; }
    virtual void goto_next_option() noexcept {
        if (focused_option_ < options_.size() - 1) { focused_option_++; }
        else { focused_option_ = 0; }
    }

    virtual void goto_previous_option() noexcept {
        if (focused_option_ > 0) { focused_option_--; }
        else { focused_option_ = static_cast<int>(options_.size()) - 1; }
    }
};

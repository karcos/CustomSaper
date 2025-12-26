#pragma once

#include <string>
#include <fstream>

#include "LoggerConstants.h"


class Logger final {
private:
    std::ofstream log_file_;
public:
    explicit Logger();
    ~Logger();

    void log(LogLevel lvl, const std::string& msg);
private:
    static std::string lvl2str(LogLevel lvl);
    static std::string current_time();
};

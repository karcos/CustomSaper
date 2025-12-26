#pragma once

#include <string>

enum class LogLevel {
    INFO,
    WARNING,
    ERROR,
    FATAL
};

const std::string logger_file_name = "app_logs.log";
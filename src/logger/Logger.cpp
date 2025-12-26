#include <fstream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <iostream>

#include "../../include/logger/Logger.h"
#include "../../include/logger/LoggerConstants.h"


Logger::Logger() {
    log_file_.open(logger_file_name, std::ios::app);

    if (not log_file_.good()) {
        std::cerr << "Cannot open log file! " << logger_file_name << std::endl;
        throw std::runtime_error("Cannot open log file!");
    }

    log_file_ << "\nSTART - " << current_time() << std::endl;
}

Logger::~Logger() {
    log_file_ << "END - " << current_time() << std::endl;
    log_file_.close();
}

void Logger::log(const LogLevel lvl, const std::string& msg) {
    log_file_ << lvl2str(lvl) << ": " << msg << std::endl;
}

std::string Logger::current_time() {
    using namespace std::chrono;

    auto now = system_clock::now();
    auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;

    std::time_t t = system_clock::to_time_t(now);
    std::tm tm{};

#if defined(_WIN32)
    localtime_s(&tm, &t);
#else
    localtime_r(&t, &tm);
#endif

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << '.' << std::setw(3) << std::setfill('0') << ms.count();

    return oss.str();
}

std::string Logger::lvl2str(const LogLevel lvl) {
    switch (lvl) {
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR: return "ERROR";
        case LogLevel::FATAL: return "FATAL";
        default: return "UNKNOWN";
    }
}

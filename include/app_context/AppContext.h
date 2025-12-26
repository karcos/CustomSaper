#pragma once

#include "../user_settings/UserSettings.h"
#include "../logger/Logger.h"


struct AppContext {
public:
    Logger logger_;
protected:
    UserSettings user_settings_;
};

#pragma once

#include <memory>
#include <utility>

#include "../include/app_context/AppContext.h"


class Controller {
protected:
    AppContext ctx_;
public:
    explicit Controller(AppContext& ctx) {}
    virtual ~Controller() = default;

    virtual std::unique_ptr<Controller> run() = 0;
};

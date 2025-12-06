#pragma once

#include <vector>
#include <string>
#include "MainMenuConstants.h"
#include "../selectable_list_base/SelectableListBase.h"


class MainMenu final : public SelectableListBase {
public:
	explicit MainMenu(const std::vector<std::string>& options = MainMenuConstants::options) : SelectableListBase(options) {}
};


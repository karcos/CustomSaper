#include <memory>

#include "../include/controller/Controller.h"
#include "../include/main_menu/MainMenuController.h"
#include "../include/app_context/AppContext.h"


int main() 
{
    AppContext app_context;
    std::unique_ptr<Controller> controller = std::make_unique<MainMenuController>(app_context);

    while (controller != nullptr) {
        controller = controller->run();
    }







}
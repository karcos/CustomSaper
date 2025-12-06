cmake_minimum_required(VERSION 4.0)
project(Aplikacja_konsoli_C__2)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/board)
include_directories(include/console_color)
include_directories(include/main_menu)
include_directories(include/random)
include_directories(include/tile)

add_executable(Aplikacja_konsoli_C__2
        src/board/Board.cpp
        include/board/Board.h
        include/board/BoardConstants.h
        include/Coords/Coords.h
        src/console_color/ConsoleColor.cpp
        include/console_color/ConsoleColor.h
        src/main_menu/MainMenu.cpp
        include/main_menu/MainMenu.h
        include/main_menu/MainMenuConstants.h
        src/random/Random.cpp
        include/random/Random.h
        src/tile/Tile.cpp
        include/tile/Tile.h
        include/tile/TileConstants.h
        src/main.cpp
        include/general_constants/GeneralConstants.h
        src/user_settings/UserSettings.cpp
        include/user_settings/UserSettings.h
        include/user_settings/UserSettingsConstants.h
        src/main_menu/MainMenuController.cpp
        include/main_menu/MainMenuController.h
        src/app_context/AppContext.cpp
        include/app_context/AppContext.h
        src/controller/Controller.cpp
        include/controller/Controller.h
        src/Game/Game.cpp
        include/Game/Game.h
        include/game/GameController.h
        src/game/GameController.cpp
        src/user_settings/UserSettingsController.cpp
        include/user_settings/UserSettingsController.h
        src/user_settings/UserSettingsView.cpp
        include/user_settings/UserSettingsView.h
        include/selectable_list_base/SelectableListBase.h
        include/game/GameConstants.h
        include/main_menu/MainMenuView.h
        src/main_menu/MainMenuView.cpp
        src/game/GameView.cpp
        include/game/GameView.h
)

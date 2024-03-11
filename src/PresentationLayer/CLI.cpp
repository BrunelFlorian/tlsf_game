#include "../../include/PresentationLayer/cli.h"

/*
 * Display the main menu
 */
void displayMainMenu() {
    std::cout << "------------------------" << std::endl;
    std::cout << "|    The legend of     |" << std::endl;
    std::cout << "|  Segmentation Fault  |" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "| 1. New Game          |" << std::endl;
    std::cout << "| 2. Load Save         |" << std::endl;
    std::cout << "| 3. Exit              |" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "Enter your choice: ";
}

/*
 * Display the game name
 */
void displayGameName() {
    std::cout << R"(
                       ________            __                          __         ____               
                      /_  __/ /_  ___     / /__  ____ ____  ____  ____/ /  ____  / __/               
                       / / / __ \/ _ \   / / _ \/ __ `/ _ \/ __ \/ __  /  / __ \/ /_                 
                      / / / / / /  __/  / /  __/ /_/ /  __/ / / / /_/ /  / /_/ / __/                 
                     /_/ /_/ /_/\___/  /_/\___/\__, /\___/_/ /_/\__,_/   \____/_/                    
                                              /____/       __  _                ____            ____ 
           ________  ____ _____ ___  ___  ____  / /_____ _/ /_(_)___  ____     / __/___ ___  __/ / /_
          / ___/ _ \/ __ `/ __ `__ \/ _ \/ __ \/ __/ __ `/ __/ / __ \/ __ \   / /_/ __ `/ / / / / __/
         (__  )  __/ /_/ / / / / / /  __/ / / / /_/ /_/ / /_/ / /_/ / / / /  / __/ /_/ / /_/ / / /_  
        /____/\___/\__, /_/ /_/ /_/\___/_/ /_/\__/\__,_/\__/_/\____/_/ /_/  /_/  \__,_/\__,_/_/\__/  
                  /____/                                                                             
    )" << std::endl;
}

/*
 * Display the player selection
 * @return int : player selection
 */
int displayPlayerSelection() {
    int choice;

    std::cout << "\n------------------------" << std::endl;
    std::cout << "| Choose your character |" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "| 1. Berserker          |" << std::endl;
    std::cout << "| 2. Paladin            |" << std::endl;
    std::cout << "| 3. Warrior            |" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    return choice;
}

/*
 * Display the in-game menu
 */
void displayInGameMenu() {
    std::cout << "\nChoose your action:" << std::endl;
    std::cout << "1. Move forward" << std::endl;
    std::cout << "2. View inventory and stats" << std::endl;
    std::cout << "3. Equip item" << std::endl;
    std::cout << "4. Quit game" << std::endl;
}

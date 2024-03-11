#include <iostream>
#include <vector>
#include "../include/PresentationLayer/cli.h"
#include "../include/BusinessLogicLayer/gameManager.h"
#include "../include/DataLayer/character.h"
#include "../include/DataLayer/player.h"
#include "../include/DataLayer/enemy.h"
#include "../include/DataLayer/ally.h"
#include "../include/DataLayer/potion.h"
#include "../include/DataLayer/weapon.h"
#include "../include/DataLayer/armor.h"
#include "../include/PresentationLayer/musicPlayer.h"
#include "../include/DataLayer/dataHandler.h"

int main() {
    MusicPlayer musicPlayer;
    DataHandler dataHandler;
    std::unique_ptr<Player> player;

    try {
        // Load menu music and start it
        musicPlayer.loadMusic("menu_music.mp3");
        musicPlayer.fadeInMusic(1500);

        int choice;
        bool newGame = false;

        do {
            displayMainMenu();
            std::cin >> choice;

            switch (choice) {
                case 1:
                    newGame = true;
                    break;
                case 2:
                    std::cout << "Loading save..." << std::endl;
                    player = dataHandler.loadGame("save.txt");
                    if (player != nullptr) {
                        newGame = true;
                    }
                    break;
                case 3:
                    std::cout << "Exiting game..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
            }
        } while (choice != 1 && choice != 3);

        if (newGame) {
            system("clear");

            // Stop menu music and start game music
            musicPlayer.stopMusic();
            musicPlayer.loadMusic("game_music.mp3");
            musicPlayer.fadeInMusic(1500);

            // Player choice
            int characterType = displayPlayerSelection();
            std::unique_ptr<Player> player = createPlayer(characterType);

            system("clear");
            displayGameName();
            player->displayStats();

            bool gameOver = false;

            while (!gameOver) {
                displayInGameMenu();
                std::cin >> choice;

                switch (choice) {
                    case 1:
                        handleEncounter(*player);
                        break;
                    case 2:
                        player->displayStats();
                        break;
                    case 3:
                        handleEquipment(*player);
                        break;
                    case 4:
                        gameOver = true;
                        dataHandler.saveGame(*player, "save.txt");
                        std::cout << "Exiting game..." << std::endl;
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again." << std::endl;
                        break;
                }

                if (player->getHealth() <= 0) {
                    // Check if player has a healing potion
                    bool potionUsed = false;
                    for (size_t i = 0; i < 10; ++i) {
                        if (player->getItem(i) != nullptr && player->getItem(i)->getType() == ItemType::Potion) {
                            std::cout << "Player uses Healing Potion!" << std::endl;
                            player->useItem(i);
                            potionUsed = true;
                            break;
                        }
                    }

                    if (!potionUsed) {
                        gameOver = true;
                        std::cout << "Player has been defeated!" << std::endl;
                    }
                }
            }
        }

    } catch (const std::exception& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
        musicPlayer.stopMusic();
    }

    musicPlayer.stopMusic();
    Mix_Quit();
    return 0;
}

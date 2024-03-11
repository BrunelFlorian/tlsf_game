#include "../../include/DataLayer/dataHandler.h"
#include "../../include/DataLayer/itemType.h"
#include <fstream>

/*
 * Save the game
 * @param player Player : player to save
 * @param filename std::string : file name
 * @return bool : true if the game is saved, false otherwise
 */
bool DataHandler::saveGame(const Player& player, const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        return false;
    }

    // Sauvegardez les informations du joueur
    file << player.getName() << '\n';
    file << player.getHealth() << '\n';
    file << player.getAttack() << '\n';
    file << player.getDefense() << '\n';

    // Sauvegardez l'arme équipée
    const Weapon* equippedWeapon = player.getEquippedWeapon();
    if (equippedWeapon != nullptr) {
        file << "Weapon\n";
        file << equippedWeapon->getName() << '\n';
        file << equippedWeapon->getAttackPower() << '\n';
    } else {
        file << "None\n";
    }

    // Sauvegardez l'armure équipée
    const Armor* equippedArmor = player.getEquippedArmor();
    if (equippedArmor != nullptr) {
        file << "Armor\n";
        file << equippedArmor->getName() << '\n';
        file << equippedArmor->getDefensePower() << '\n';
    } else {
        file << "None\n";
    }

    // Sauvegardez l'inventaire
    file << player.getInventory().size() << '\n';
    for (const auto& item : player.getInventory()) {
        if (item != nullptr) {
            file << item->getType() << '\n';
            file << item->getName() << '\n';
            switch (item->getType()) {
                case ItemType::Potion:
                    file << static_cast<const Potion*>(item.get())->getHealingPower() << '\n';
                    break;
                case ItemType::Weapon:
                    file << static_cast<const Weapon*>(item.get())->getAttackPower() << '\n';
                    break;
                case ItemType::Armor:
                    file << static_cast<const Armor*>(item.get())->getDefensePower() << '\n';
                    break;
            }
        }
    }

    file.close();
    return true;
}


/*
 * String to item type
 * @param str std::string : string to convert
 * @return ItemType : item type
 */
ItemType DataHandler::stringToItemType(const std::string& str) {
    if (str == "Potion") {
        return ItemType::Potion;
    } else if (str == "Weapon") {
        return ItemType::Weapon;
    } else if (str == "Armor") {
        return ItemType::Armor;
    } else {
        throw std::runtime_error("Invalid item type: " + str);
    }
}

/*
 * Load the game
 * @param player Player : player to load
 * @param filename std::string : file name
 * @return std::unique_ptr<Player> : player
 */
std::unique_ptr<Player> DataHandler::loadGame(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        return nullptr;
    }

    std::string line;
    std::unique_ptr<Player> player(new Player("John Doe", 100, 10, 10));

    // Load player name
    if (std::getline(file, line)) {
        player->setName(line);
    } else {
        std::cerr << "Error loading player name." << std::endl;
        return nullptr;
    }

    // Load player health
    if (std::getline(file, line)) {
        player->setHealth(std::stoi(line));
    } else {
        std::cerr << "Error loading player health." << std::endl;
        return nullptr;
    }

    // Load player attack
    if (std::getline(file, line)) {
        player->setAttack(std::stoi(line));
    } else {
        std::cerr << "Error loading player attack." << std::endl;
        return nullptr;
    }

    // Load player defense
    if (std::getline(file, line)) {
        player->setDefense(std::stoi(line));
    } else {
        std::cerr << "Error loading player defense." << std::endl;
        return nullptr;
    }

    // Load equipped weapon
    if (std::getline(file, line)) {
        if (line != "None") {
            ItemType type = stringToItemType(line);
            if (type == ItemType::Weapon) {
                if (std::getline(file, line)) {
                    std::unique_ptr<Item> item(new Weapon(line, 0));
                    player->equipWeapon(static_cast<Weapon*>(item.get()));
                    player->addItem(std::move(item));
                } else {
                    std::cerr << "Error loading equipped weapon name." << std::endl;
                    return nullptr;
                }
            } else {
                std::cerr << "Error: Equipped weapon has invalid type." << std::endl;
                return nullptr;
            }
        }
    } else {
        std::cerr << "Error loading equipped weapon type." << std::endl;
        return nullptr;
    }

    // Load equipped armor
    if (std::getline(file, line)) {
        if (line != "None") {
            ItemType type = stringToItemType(line);
            if (type == ItemType::Armor) {
                if (std::getline(file, line)) {
                    std::unique_ptr<Item> item(new Armor(line, 0));
                    player->equipArmor(static_cast<Armor*>(item.get()));
                    player->addItem(std::move(item));
                } else {
                    std::cerr << "Error loading equipped armor name." << std::endl;
                    return nullptr;
                }
            } else {
                std::cerr << "Error: Equipped armor has invalid type." << std::endl;
                return nullptr;
            }
        }
    } else {
        std::cerr << "Error loading equipped armor type." << std::endl;
        return nullptr;
    }

    // Load inventory size
    if (std::getline(file, line)) {
        size_t inventorySize = std::stoi(line);

        // Load inventory items
        for (size_t i = 0; i < inventorySize; ++i) {
            if (file.eof()) {
                std::cerr << "Error: End of file reached while loading inventory items." << std::endl;
                break;
            }

            if (std::getline(file, line)) {
                ItemType type = stringToItemType(line);
                std::cerr << "Item type: " << line << std::endl;
                if (std::getline(file, line)) {
                    std::cerr << "Item name: " << line << std::endl;
                    std::unique_ptr<Item> item;
                    switch (type) {
                        case ItemType::Potion:
                            if (std::getline(file, line)) {
                                item.reset(new Potion(line, std::stoi(line)));
                            } else {
                                std::cerr << "Error loading potion healing power." << std::endl;
                                return nullptr;
                            }
                            break;
                        case ItemType::Weapon:
                            if (std::getline(file, line)) {
                                item.reset(new Weapon(line, std::stoi(line)));
                            } else {
                                std::cerr << "Error loading weapon damage." << std::endl;
                                return nullptr;
                            }
                            break;
                        case ItemType::Armor:
                            if (std::getline(file, line)) {
                                item.reset(new Armor(line, std::stoi(line)));
                            } else {
                                std::cerr << "Error loading armor defense." << std::endl;
                                return nullptr;
                            }
                            break;
                        default:
                            std::cerr << "Error: Invalid item type." << std::endl;
                            return nullptr;
                    }
                    player->addItem(std::move(item));
                } else {
                    std::cerr << "Error loading item name." << std::endl;
                    return nullptr;
                }
            } else {
                std::cerr << "Error loading item type." << std::endl;
                return nullptr;
            }

            // Check if the end of the file has been reached
            if (file.peek() == std::ifstream::traits_type::eof()) {
                break;
            }
        }
    } else {
        std::cerr << "Error loading inventory size." << std::endl;
        return nullptr;
    }

    file.close();
    return player;
}

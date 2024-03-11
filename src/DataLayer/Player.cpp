#include "../../include/DataLayer/player.h"

Player::Player(const std::string& name, unsigned int health, unsigned int attack, unsigned int defense)
    : Character(name, health, attack, defense) {}

void Player::chooseItem(std::vector<std::unique_ptr<Item>>& items) {
    if (items.empty()) {
        std::cout << "\nNo items to choose from." << std::endl;
        return;
    }

    std::cout << "\nChoose an item (enter the index):" << std::endl;
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << i << ": " << *(items[i]) << std::endl;
    }

    int choice;
    std::cin >> choice;

    if (choice >= 0 && choice < static_cast<int>(items.size())) {
        addItem(std::move(items[choice]));
        items[choice] = nullptr;
        std::cout << "\nItem added to inventory: " << std::endl;
    } else {
        std::cout << "\nInvalid choice." << std::endl;
    }
}

/*
 * Remove an item from the player's inventory
 * @param item Item : item to remove
 */
void Player::removeItem(int index) {
    setInventoryItem(index, nullptr);
}

/*
 * Get the player's equipped weapon
 * @return Weapon* : player's equipped weapon
 */
Armor* Player::getEquippedArmor() const {
    return this->equippedArmor;
}

/*
 * Get the player's equipped armor
 * @return Armor* : player's equipped armor
 */
Weapon* Player::getEquippedWeapon() const {
    return this->equippedWeapon;
}
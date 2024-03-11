#include "../../include/BusinessLogicLayer/gameManager.h"
#include "../../include/BusinessLogicLayer/fightManager.h"

/*
 * Create a player
 * @param characterType int : The player type
 * @return std::unique_ptr<Player> : The player
 */
std::unique_ptr<Player> createPlayer(int characterType) {
    std::string characterName;
    int health, attack, defense;

    switch (characterType) {
        case 1:
            characterName = "Berserker";
            health = 90;
            attack = 16;
            defense = 9;
            break;
        case 2:
            characterName = "Paladin";
            health = 110;
            attack = 12;
            defense = 12;
            break;
        case 3:
            characterName = "Warrior";
            health = 100;
            attack = 14;
            defense = 10;
            break;
        default:
            throw std::invalid_argument("Invalid character type.");
    }

    return std::unique_ptr<Player>(new Player(characterName, health, attack, defense));
}

/*
 * Get a random number between min and max
 * @param min int : The minimum value
 * @param max int : The maximum value
 * @return int : A random number between min and max
 */
int getRandomNumber(int min, int max) {
    static bool firstTime = true;
    if (firstTime) {
        srand(time(nullptr));
        firstTime = false;
    }
    return rand() % (max - min + 1) + min;
}

/*
 * Handle the encounter with an enemy, an ally or an item
 * @param player Player : The player
 */
void handleEncounter(Player& player) {
    int encounterType = getRandomNumber(1, 10);

    if (encounterType <= 5) {
        // Rencontre d'un ennemi
        std::vector<std::unique_ptr<Item>> enemyLoot;
        int enemyType = getRandomNumber(1, 100);
        std::string enemyName;
        int health, attack, defense;

        if (enemyType <= 10) {
            // SegFault Evil
            enemyName = "SegFault Evil";
            health = 130;
            attack = 15;
            defense = 10;
            enemyLoot.push_back(std::unique_ptr<Potion>(new Potion("Health Potion", getRandomNumber(80, 100))));
            enemyLoot.push_back(std::unique_ptr<Weapon>(new Weapon("SegFault Sword", getRandomNumber(20, 30))));
        } else if (enemyType <= 50) {
            // Orc
            enemyName = "Orc";
            health = 70;
            attack = 12;
            defense = 7;
            enemyLoot.push_back(std::unique_ptr<Potion>(new Potion("Health Potion", getRandomNumber(40, 60))));
            enemyLoot.push_back(std::unique_ptr<Weapon>(new Weapon("Axe", getRandomNumber(8, 15))));
        } else {
            // Goblin
            enemyName = "Goblin";
            health = 50;
            attack = 10;
            defense = 5;
            enemyLoot.push_back(std::unique_ptr<Potion>(new Potion("Health Potion", getRandomNumber(30, 50))));
            enemyLoot.push_back(std::unique_ptr<Weapon>(new Weapon("Sword", getRandomNumber(5, 10))));
        }

        Enemy enemy(enemyName, health, attack, defense, std::move(enemyLoot));
        handleFight(player, enemy);
    } else if (encounterType <= 8) {
        // Rencontre d'un allié
        std::vector<std::unique_ptr<Item>> allyGifts;
        allyGifts.push_back(std::unique_ptr<Armor>(new Armor("Shield", getRandomNumber(3, 20))));
        allyGifts.push_back(std::unique_ptr<Potion>(new Potion("Mana Potion", getRandomNumber(20, 60))));
        Ally ally("Ally", 100, 10, 10, std::move(allyGifts));
        handleAlly(player, ally);
    } else {
        // Rencontre d'un objet
        int itemType = getRandomNumber(1, 3);
        Item* item;

        switch (itemType) {
            case 1:
                item = new Potion("Health Potion", getRandomNumber(30, 60));
                break;
            case 2:
                item = new Weapon("Sword", getRandomNumber(5, 15));
                break;
            case 3:
                item = new Armor("Shield", getRandomNumber(3, 15));
                break;
        }

        handleItem(player, item);
    }
}


/*
 * Handle the encounter with an ally
 * @param player Player : The player
 * @param ally Ally : The ally
 */
void handleAlly(Player& player, Ally& ally) {
    std::cout << "\nYou encountered an ally!" << std::endl;
    player.chooseItem(ally.getGifts());
}

/*
 * Handle the encounter with an item
 * @param player Player : The player
 * @param item Item* : The item
 */
void handleItem(Player& player, Item* item) {
    std::cout << "\nYou found an item on the ground: " << item->getName() << "! Do you want to pick it up? (y/n)" << std::endl;
    char choice;
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        std::unique_ptr<Item> uniqueItem(item);
        player.addItem(std::move(uniqueItem));
        std::cout << "\nItem added to your inventory." << std::endl;
    } else {
        std::cout << "\nYou decided not to pick up the item." << std::endl;
        delete item;
    }
}

/*
 * Handle the equipment	of an item (armor or weapon)
 * @param player Player : The player
 */
void handleEquipment(Player& player) {
    std::cout << "\nEquipment:" << std::endl;

    for (size_t i = 0; i < player.getInventory().size(); ++i) {
        if (player.getInventory()[i] != nullptr) {
            std::cout << i << ": " << player.getInventory()[i]->getName() << std::endl;
        } else {
            std::cout << i << ": Empty" << std::endl;
        }
    }

    std::cout << "\nEnter the index of the item to equip or -1 to go back: ";
    int index;
    std::cin >> index;

    if (static_cast<size_t>(index) >= 0 && static_cast<size_t>(index) < player.getInventory().size()) {
        std::unique_ptr<Item>& item = const_cast<std::unique_ptr<Item>&>(player.getInventory()[index]);
        if (item != nullptr) {
            if (item->getType() == ItemType::Weapon) {
                // Unequip current weapon
                if (player.getEquippedWeapon() != nullptr) {
                    player.unequipWeapon();
                }
                player.equipWeapon(static_cast<Weapon*>(item.get()));
            } else if (item->getType() == ItemType::Armor) {
                // unequip current armor
                if (player.getEquippedArmor() != nullptr) {
                    player.unequipArmor();
                }
                player.equipArmor(static_cast<Armor*>(item.get()));
            }
            item = nullptr;
        }
    }
}


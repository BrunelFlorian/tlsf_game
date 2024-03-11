#include "../../include/DataLayer/character.h"
#include "../../include/DataLayer/weapon.h"
#include "../../include/DataLayer/potion.h"
#include "../../include/DataLayer/armor.h"

/*
 * Constructor
 * @param characterName std::string : character name
 * @param healthPoints unsigned int : health points
 * @param attackPower unsigned int : attack power
 * @param defensePower unsigned int : defense power
 */
Character::Character(const std::string& characterName, unsigned int healthPoints, unsigned int attackPower, unsigned int defensePower)
    : name(characterName), health(healthPoints), attack(attackPower), defense(defensePower), equippedWeapon(nullptr), equippedArmor(nullptr) {}

/*
 * Destructor
 */
Character::~Character() {
    for (int i = 0; i < 10; ++i) {
        inventory[i] = nullptr;
    }
}

/*
 * Get character name
 * @return std::string : character name
 */
const std::string Character::getName() const {
    return this->name;
}

/*
    * Set character name
    * @param n std::string : character name
    */
void Character::setName(const std::string& n) {
    this->name = n;
}

/*
 * Get character health
 * @return unsigned int : character health
 */
unsigned int Character::getHealth() const {
    return this->health;
}

/*
 * Set character health
 * @param healthPoints unsigned int : health points
 */
void Character::setHealth(unsigned int healthPoints) {
    this->health = healthPoints;
}

/*
 * Get character attack
 * @return unsigned int : character attack
 */
unsigned int Character::getAttack() const {
    return this->attack;
}

/*
 * Set character attack
 * @param attackPower unsigned int : attack power
 */
void Character::setAttack(unsigned int attackPower) {
    this->attack = attackPower;
}

/*
 * Get character defense
 * @return unsigned int : character defense
 */
unsigned int Character::getDefense() const {
    return this->defense;
}

/*
 * Set character defense
 * @param defensePower unsigned int : defense power
 */
void Character::setDefense(unsigned int defensePower) {
    this->defense = defensePower;
}

/*
 * Get character's inventory
 * @return std::array<std::unique_ptr<Item>, 10>& : pointer to character's inventory
 */
const std::array<std::unique_ptr<Item>, 10>& Character::getInventory() const {
    return this->inventory;
}

/*
 * Get item from character's inventory
 * @param index int : index of the item to get
 * @return Item : item from character's inventory
 */
Item* Character::getItem(int index) {
    return inventory[index].get();
}

/*
 * Set item in character's inventory
 * @param index int : index of the item to set
 * @param item Item : item to set
 */
void Character::setInventoryItem(int index, std::unique_ptr<Item> item) {
    inventory[index] = std::move(item);
}

/*
 * Add item to character's inventory
 * @param item std::unique_ptr<Item> : item to add
 */
void Character::addItem(std::unique_ptr<Item> item) {
    bool added = false;
    for (size_t i = 0; i < this->inventory.size(); ++i) {
        if (!this->inventory[i]) { // Si l'emplacement est vide
            this->inventory[i] = std::move(item);
            added = true;
            break;
        }
    }
    if (!added) {
        std::cout << "\nInventory is full. Cannot add more items." << std::endl;
    }
}

/*
 * Use item from character's inventory
 * @param index int : index of the item to use
 */
void Character::useItem(int index) {
    if (static_cast<std::size_t>(index) < inventory.size()) {
        if (inventory[index] != nullptr) {
            inventory[index]->use(*this);
            inventory[index] = nullptr;
        } else {
            std::cout << "\nNo item at index " << index << std::endl;
        }
    } else {
        std::cout << "\nInvalid item index." << std::endl;
    }
}

/*
 * Equip weapon
 * @param weapon Weapon* : weapon to equip
 */
void Character::equipWeapon(Weapon* weapon) {
    if (equippedWeapon != nullptr) {
        std::cout << "\nYou already have a weapon equipped. Unequip current weapon first." << std::endl;
        return;
    }

    equippedWeapon = weapon;
    attack += equippedWeapon->getAttackPower();
    std::cout << "\nWeapon equipped: " << equippedWeapon->getName() << std::endl;
}

/*
 * Unequip weapon
 */
void Character::unequipWeapon() {
    if (equippedWeapon == nullptr) {
        std::cout << "\nYou don't have a weapon equipped." << std::endl;
        return;
    }

    attack -= equippedWeapon->getAttackPower();
    equippedWeapon = nullptr;
    std::cout << "\nWeapon unequipped" << std::endl;
}

/*
 * Equip armor
 * @param armor Armor* : armor to equip
 */
void Character::equipArmor(Armor* armor) {
    if (equippedArmor != nullptr) {
        std::cout << "\nYou already have an armor equipped. Unequip current armor first." << std::endl;
        return;
    }

    equippedArmor = armor;
    defense += equippedArmor->getDefensePower();
    std::cout << "\nArmor equipped: " << equippedArmor->getName() << std::endl;
}

/*
 * Unequip armor
 */
void Character::unequipArmor() {
    if (equippedArmor == nullptr) {
        std::cout << "\nYou don't have an armor equipped." << std::endl;
        return;
    }

    defense -= equippedArmor->getDefensePower();
    equippedArmor = nullptr;
    std::cout << "\nArmor unequipped" << std::endl;
}

/*
 * Display character stats
 */
void Character::displayStats() const {
    std::cout << "\nName: " << name << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Attack: " << attack << std::endl;
    std::cout << "Defense: " << defense << std::endl;
    std::cout << "Equipped Weapon: " << (equippedWeapon ? equippedWeapon->getName() : "None") << std::endl;
    std::cout << "Equipped Armor: " << (equippedArmor ? equippedArmor->getName() : "None") << std::endl;
    std::cout << "Inventory: " << std::endl;

    for (size_t i = 0; i < inventory.size(); i++) {
        if (inventory[i] != nullptr) {
            std::cout << i << ": " << inventory[i]->getName() << std::endl;
        } else {
            std::cout << i << ": Empty" << std::endl;
        }
    }
}

/*
 * Attack another character
 * @param target Character : character to attack
 */
void Character::attackTarget(Character& target) {
    unsigned int damage = this->getAttack() - target.getDefense(); 
    if (damage > 0) {
        if (target.getHealth() > damage) {
            target.setHealth(target.getHealth() - damage);
        } else {
            target.setHealth(0);
        }
    } else {
        std::cout << "\nNo damage dealt." << std::endl;
    }
}
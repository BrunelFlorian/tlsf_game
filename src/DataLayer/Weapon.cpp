#include "../../include/DataLayer/weapon.h"
#include "../../include/DataLayer/character.h"

/*
 * Constructor
 * @param name std::string : weapon name
 * @param power int : weapon attack power
 */
Weapon::Weapon(const std::string& name, unsigned int attackPower)
    : Item(name, ItemType::Weapon, attackPower) {}

/*
 * Get weapon attack power
 * @return unsigned int : weapon attack power
 */
unsigned int Weapon::getAttackPower() const {
    return this->getPower();
}

/*
 * Use the weapon
 * @param character Character : character who will use the weapon
 */
void Weapon::use(Character& character) {
    character.equipWeapon(this);
}
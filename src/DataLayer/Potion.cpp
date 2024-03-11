#include "../../include/DataLayer/potion.h"

/*
 * Constructor
 * @param name std::string : potion name
 * @param healingPower int : healing power of the potion
 */
Potion::Potion(const std::string& name, unsigned int healingPower)
    : Item(name, ItemType::Potion, healingPower) {}

/*
 * Get potion healing power
 * @return unsigned int : potion healing power
 */
unsigned int Potion::getHealingPower() const {
    return this->getPower();
}

/*
 * Use the potion
 * @param character Character : character who will use the potion
 */
void Potion::use(Character& character) {
    character.setHealth(character.getHealth() + this->getPower());
}

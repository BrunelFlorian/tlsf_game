#include "../../include/DataLayer/armor.h"
#include "../../include/DataLayer/character.h"

/*
 * Constructor
 * @param name std::string : armor name
 * @param defensePower int : defense power of the armor
 */
Armor::Armor(const std::string& name, unsigned int defensePower)
    : Item(name, ItemType::Armor, defensePower) {}

/*
 * Get armor defense power
 * @return unsigned int : armor defense power
 */
unsigned int Armor::getDefensePower() const {
    return this->getPower();
}

/*
 * Use the armor
 * @param character Character : character who will use the armor
 */
void Armor::use(Character& character) {
    character.equipArmor(this);
}

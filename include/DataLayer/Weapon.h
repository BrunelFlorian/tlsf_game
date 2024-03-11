#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include "item.h"

class Character;

class Weapon : public Item {
public:
    /*
     * Constructor
     * @param name std::string : weapon name
     * @param power int : weapon attack power
     */
    Weapon(const std::string& name, unsigned int power);

    /*
     * Destructor
     */
    virtual ~Weapon() = default;

    /*
     * Get weapon attack power
     * @return unsigned int : weapon attack power
     */
    unsigned int getAttackPower() const;

    /*
     * Use the weapon
     * @param character Character : character who will use the weapon
     */
    void use(Character& character);
};

#endif // WEAPON_H
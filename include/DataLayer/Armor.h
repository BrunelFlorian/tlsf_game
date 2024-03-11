#ifndef ARMOR_H
#define ARMOR_H

#include <iostream>
#include "item.h"

class Character;

class Armor : public Item {
public:
    /*
     * Constructor
     * @param name std::string : armor name
     * @param defensePower int : armor defense power
     */
    Armor(const std::string& name, unsigned int defensePower);

    /*
     * Destructor
     */
    virtual ~Armor() = default;

    /*
     * Get armor defense power
     * @return int : armor defense power
     */
    unsigned int getDefensePower() const;

    /*
     * Use the armor
     * @param character Character : character who will use the armor
     */
    void use(Character& character);
};

#endif // ARMOR_H

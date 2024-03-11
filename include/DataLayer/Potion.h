#ifndef POTION_H
#define POTION_H

#include <iostream>
#include "item.h"
#include "character.h"

class Potion : public Item {
public:
    /*
     * Constructor
     * @param name std::string : potion name
     * @param healingPower int : potion healing power
     */
    Potion(const std::string& name, unsigned int healingPower);

    /*
     * Destructor
     */
    virtual ~Potion() = default;

    /*
     * Get potion healing power
     * @return unsigned int : potion healing power
     */
    unsigned int getHealingPower() const;

    /*
     * Use the potion
     * @param character Character : character who will use the potion
     */
    void use(Character& character);
};

#endif // POTION_H

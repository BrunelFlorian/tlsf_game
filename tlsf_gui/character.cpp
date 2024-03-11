#include "character.h"
#include <iostream>

/*
 * Constructor
 * @param n std::string : character name
 * @param h unsigned int : health points
 * @param a unsigned int : attack points
 * @param d unsigned int : defense points
 */
Character::Character(const std::string& n, unsigned int h, unsigned int a, unsigned int d, QObject *parent)
    : QObject(parent), name(n), health(h), attackPower(a), defense(d) {}

/*
 * Get character name
 * @return std::string : character name
 */
const std::string Character::getName() const {
    return name;
}

/*
 * Get character health
 * @return unsigned int : character health
 */
unsigned int Character::getHealth() const {
    return health;
}

/*
 * Get character attack
 * @return unsigned int : character attack
 */
unsigned int Character::getAttack() const {
    return attackPower;
}

/*
 * Get character defense
 * @return unsigned int : character defense
 */
unsigned int Character::getDefense() const {
    return defense;
}

QString Character::getSkin() const {
    return skin;
}

void Character::setSkin(const QString& newSkin) {
    if (skin != newSkin) {
        skin = newSkin;
        emit skinChanged(newSkin); // Émettre le signal skinChanged
    }
}

/*
 * Display character stats
 */
void Character::displayStats() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Attack: " << attackPower << std::endl;
    std::cout << "Defense: " << defense << std::endl;
}

/*
 * Attack another character
 * @param target Character : character to attack
 */
void Character::attack(Character& target) {
    target.health -= attackPower - target.defense;
}

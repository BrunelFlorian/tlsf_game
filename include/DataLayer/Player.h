#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>
#include "../../include/DataLayer/character.h"
#include "../../include/DataLayer/item.h"

class Player : public Character {
public:
    /*
     * Constructor
     * @param name std::string : player name
     * @param health int : player health
     * @param attack int : player attack
     * @param defense int : player defense
     */
    Player(const std::string& name, unsigned int health, unsigned int attack, unsigned int defense);

    /*
     * Destructor
     */
    void chooseItem(std::vector<std::unique_ptr<Item>>& items);

    /*
     * Remove an item from the player's inventory
     * @param item Item : item to remove
     */
    void removeItem(int index);

    /*
     * Get the player's equipped weapon
     * @return Weapon* : player's equipped weapon
     */
    Armor* getEquippedArmor() const;

    /*
     * Get the player's equipped armor
     * @return Armor* : player's equipped armor
     */
    Weapon* getEquippedWeapon() const;
};

#endif // PLAYER_H

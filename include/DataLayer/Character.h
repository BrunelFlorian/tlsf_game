#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <memory>
#include <array>
#include "armor.h"
#include "weapon.h"

class Item;

class Character {
private:
    std::string name;
    unsigned int health;
    unsigned int attack;
    unsigned int defense;
    std::array<std::unique_ptr<Item>, 10> inventory;

protected:
    Weapon* equippedWeapon;
    Armor* equippedArmor;

public:
    /*
     * Constructor
     * @param name std::string : character name
     * @param health unsigned int : health points
     * @param attack unsigned int : attack power
     * @param defense unsigned int : defense power
     */
    Character(const std::string& name, unsigned int health, unsigned int attack, unsigned int defense);

    /*
     * Destructor
     */
    ~Character();

    /*
     * Get character name
     * @return std::string : character name
     */
    const std::string getName() const;

    /*
     * Set character name
     * @param n std::string : character name
     */
    void setName(const std::string& n);

    /*
     * Get character health
     * @return unsigned int : character health
     */
    unsigned int getHealth() const;

    /*
     * Set character health
     * @param h unsigned int : health points
     */
    void setHealth(unsigned int h);

    /*
     * Get character attack
     * @return unsigned int : character attack
     */
    unsigned int getAttack() const;

    /*
     * Set character attack
     * @param a unsigned int : attack points
     */
    void setAttack(unsigned int a);

    /*
     * Get character defense
     * @return unsigned int : character defense
     */
    unsigned int getDefense() const;

    /*
     * Set character defense
     * @param d unsigned int : defense points
     */
    void setDefense(unsigned int d);

    /*
     * Get character's inventory
     * @return std::array<std::unique_ptr<Item>, 10>& : pointer to character's inventory
     */
    const std::array<std::unique_ptr<Item>, 10>& getInventory() const;

    /*
     * Get item from character's inventory
     * @param index int : index of the item to get
     * @return Item : item from character's inventory
     */
    Item* getItem(int index);

    /*
     * Set item in character's inventory
     * @param index int : index of the item to set
     * @param item Item : item to set
     */
    void setInventoryItem(int index, std::unique_ptr<Item> item);

    /*
     * Add item to character's inventory
     * @param item Item : item to add
     */
    void addItem(std::unique_ptr<Item> item);

    /*
     * Use item from character's inventory
     * @param index int : index of the item to use
     */
    void useItem(int index);

    /*
    * Equip weapon
    * @param weapon Weapon* : weapon to equip
    */
    void equipWeapon(Weapon *weapon);

    /*
    * Unequip weapon
    */
    void unequipWeapon();

    /*
    * Equip armor
    * @param armor Armor* : armor to equip
    */
    void equipArmor(Armor *armor);

    /*
    * Unequip armor
    */
    void unequipArmor();

    /*
     * Display character stats
     */
    void displayStats() const;

    /*
     * Attack another character
     * @param target Character : character to attack
     */
    void attackTarget(Character& target);
};

#endif // CHARACTER_H
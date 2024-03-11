#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include "itemType.h"

class Character;

class Item {
private:
    std::string name;
    ItemType type; // Enum for item type: Potion, Weapon, Armor -> defined in itemType.h
    unsigned int power;

public:
    /*
     * Constructor
     * @param itemName std::string : item name
     * @param itemType ItemType : item type
     * @param power unsigned int : item power
     */
    Item(const std::string& itemName, ItemType itemType, unsigned int power);

    /*
     * Destructor
     */
    virtual ~Item() = default;

    /*
     * Get item name
     * @return std::string : item name
     */
    std::string getName() const;

    /*
     * Get item type
     * @return ItemType : item type
     */
    ItemType getType() const;

    /*
     * Get item power
     * @return unsigned int : item power
     */
    unsigned int getPower() const;

    /*
     * Display item (friend function to access private members of Item class) -> operator overloading
     * @param os std::ostream : output stream
     * @param item Item : item to display
     * @return std::ostream& : output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const Item& item);

    /*
     * Use the item
     * @param character Character : character who will use the item
     */
    virtual void use(Character& character) = 0; // Pure virtual function to use the item -> defined in derived classes (Potion, Weapon, Armor)
};

#endif // ITEM_H
#include "../../include/DataLayer/item.h"
#include "../../include/DataLayer/character.h"

/*
 * Constructor
 * @param itemName std::string : item name
 * @param itemType ItemType : item type
 */
Item::Item(const std::string& itemName, ItemType itemType, unsigned int itemPower)
    : name(itemName), type(itemType), power(itemPower) {}

/*
 * Get item name
 * @return std::string : item name
 */
std::string Item::getName() const {
    return this->name;
}

/*
 * Get item type
 * @return ItemType : item type
 */
ItemType Item::getType() const {
    return this->type;
}

/*
 * Get item power
 * @return unsigned int : item power
 */
unsigned int Item::getPower() const {
    return this->power;
}

/*
 * Display item (friend function to access private members of Item class) -> operator overloading
 * @param os std::ostream : output stream
 * @param item Item : item to display
 * @return std::ostream& : output stream
 */
std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << "Name: " << item.name << ", Type: ";
    switch (item.type) {
        case ItemType::Potion:
            os << "Potion, Power: " << item.getPower();
            break;
        case ItemType::Weapon:
            os << "Weapon, Power: " << item.getPower();
            break;
        case ItemType::Armor:
            os << "Armor, Power: " << item.getPower();
            break;
    }
    return os;
}

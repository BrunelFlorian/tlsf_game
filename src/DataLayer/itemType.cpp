#include <iostream>
#include "../../include/DataLayer/itemType.h"

/*
 * Output stream operator overloading for ItemType
 * @param os std::ostream : output stream
 * @param itemType ItemType : item type
 * @return std::ostream& : output stream
 */
std::ostream& operator<<(std::ostream& os, const ItemType& itemType) {
    switch (itemType) {
        case ItemType::Potion:
            os << "Potion";
            break;
        case ItemType::Weapon:
            os << "Weapon";
            break;
        case ItemType::Armor:
            os << "Armor";
            break;
        default:
            os << "Invalid ItemType";
            break;
    }
    return os;
}

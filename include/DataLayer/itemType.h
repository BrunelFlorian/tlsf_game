#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum class ItemType {
    Potion,
    Weapon,
    Armor
};

/*
 * Output stream operator overloading for ItemType
 * @param os std::ostream : output stream
 * @param itemType ItemType : item type
 * @return std::ostream& : output stream
 */
std::ostream& operator<<(std::ostream& os, const ItemType& itemType);

#endif // ITEMTYPE_H
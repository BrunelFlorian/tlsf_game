#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include "player.h"
#include "potion.h"
#include "weapon.h"
#include "armor.h"
#include "itemType.h"
#include <string>

class DataHandler {
public:
    /*
     * Save the game
     * @param player Player : player to save
     * @param filename std::string : file name
     * @return bool : true if the game is saved, false otherwise
     */
    bool saveGame(const Player& player, const std::string& filename);

    /*
     * String to item type
     * @param str std::string : string to convert
     * @return ItemType : item type
     */
    ItemType stringToItemType(const std::string& str);

    /*
     * Load the game
     * @param player Player : player to load
     * @param filename std::string : file name
     * @return std::unique_ptr<Player> : player
     */
    std::unique_ptr<Player> loadGame(const std::string& filename);
};

#endif

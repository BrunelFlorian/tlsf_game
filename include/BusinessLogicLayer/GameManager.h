#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../DataLayer/player.h"
#include "../DataLayer/enemy.h"
#include "../DataLayer/ally.h"
#include "../DataLayer/item.h"
#include "../DataLayer/potion.h"
#include "../DataLayer/weapon.h"
#include "../DataLayer/armor.h"

/*
 * Create a player
 * @param characterType int : The character type
 * @return std::unique_ptr<Player> : The player
 */
std::unique_ptr<Player> createPlayer(int characterType);

/*
 * Get a random number between min and max
 * @param min int : The minimum value
 * @param max int : The maximum value
 * @return int : A random number between min and max
 */
int getRandomNumber(int min, int max);

/*
 * Handle the encounter with an enemy, an ally or an item
 * @param player Player : The player
 */
void handleEncounter(Player& player);

/*
 * Handle the encounter with an ally
 * @param player Player : The player
 * @param ally Ally : The ally
 */
void handleAlly(Player& player, Ally& ally);

/*
 * Handle the encounter with an item
 * @param player Player : The player
 * @param item Item* : The item
 */
void handleItem(Player& player, Item* item);

/*
 * Handle the equipment	of an item (armor or weapon)
 * @param player Player : The player
 */
void handleEquipment(Player &player);

#endif // GAMEMANAGER_H

#ifndef FIGHTMANAGER_H
#define FIGHTMANAGER_H

#include "../DataLayer/player.h"
#include "../DataLayer/enemy.h"

/*
 * Handle the fight between player and enemy
 * @param player Player : player
 * @param enemy Enemy : enemy
 */
void handleFight(Player &player, Enemy &enemy);

#endif // FIGHTMANAGER_H

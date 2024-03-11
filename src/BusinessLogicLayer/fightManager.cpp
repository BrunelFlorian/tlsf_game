#include "../../include/BusinessLogicLayer/fightManager.h"
#include "../../include/BusinessLogicLayer/gameManager.h"

/*
 * Handle the fight between player and enemy
 * @param player Player : player
 * @param enemy Enemy : enemy
 */
void handleFight(Player& player, Enemy& enemy) {

    std::cout << "A wild " << enemy.getName() << " has appeared!" << std::endl;

    // Randomly choose who attacks first
    int firstAttacker = getRandomNumber(1, 2);

    while (player.getHealth() > 0 && enemy.getHealth() > 0) {
        if (firstAttacker == 1) {
            std::cout << "\nPlayer attacks enemy!" << std::endl;
            player.attackTarget(enemy);
            std::cout << "Enemy health: " << enemy.getHealth() << std::endl;
            firstAttacker = 2;
        } else {
            std::cout << "\nEnemy attacks player!" << std::endl;
            enemy.attackTarget(player);
            std::cout << "Player health: " << player.getHealth() << std::endl;
            firstAttacker = 1;
        }
    }

    if (enemy.getHealth() <= 0) {
        std::cout << "Enemy has been defeated!" << std::endl;
        player.chooseItem(enemy.getLoot());
    }
}

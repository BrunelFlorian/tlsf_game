#include "../../include/DataLayer/enemy.h"

Enemy::Enemy(const std::string& name, unsigned int health, unsigned int attack, unsigned int defense,
             std::vector<std::unique_ptr<Item>>&& loot)
    : Character(name, health, attack, defense), loot(std::move(loot)) {}

std::vector<std::unique_ptr<Item>>& Enemy::getLoot() {
    return loot;
}

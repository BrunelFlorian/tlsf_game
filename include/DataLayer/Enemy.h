#ifndef ENEMY_H
#define ENEMY_H

#include "../../include/DataLayer/character.h"
#include "../../include/DataLayer/item.h"
#include <vector>

class Enemy : public Character {
public:
    Enemy(const std::string& name, unsigned int health, unsigned int attack, unsigned int defense,
          std::vector<std::unique_ptr<Item>>&& loot);

    std::vector<std::unique_ptr<Item>>& getLoot();

private:
    std::vector<std::unique_ptr<Item>> loot;
};

#endif // ENEMY_H

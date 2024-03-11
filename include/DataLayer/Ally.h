#ifndef ALLY_H
#define ALLY_H

#include "../../include/DataLayer/character.h"
#include "../../include/DataLayer/item.h"
#include <vector>

class Ally : public Character {
public:
    Ally(const std::string& name, unsigned int health, unsigned int attack, unsigned int defense,
         std::vector<std::unique_ptr<Item>>&& gifts);

    std::vector<std::unique_ptr<Item>>& getGifts();

private:
    std::vector<std::unique_ptr<Item>> gifts;
};

#endif // ALLY_H

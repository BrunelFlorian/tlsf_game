#include "../../include/DataLayer/ally.h"

Ally::Ally(const std::string& name, unsigned int health, unsigned int attack, unsigned int defense,
           std::vector<std::unique_ptr<Item>>&& gifts)
    : Character(name, health, attack, defense), gifts(std::move(gifts)) {}

std::vector<std::unique_ptr<Item>>& Ally::getGifts() {
    return gifts;
}

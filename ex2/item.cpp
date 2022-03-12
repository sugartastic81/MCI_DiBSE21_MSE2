//
// Created by juerg on 20.02.2022.
//
#include "item.h"

void Item::initItem() {
    this->setIsValid(false);
}

void Item::initItem(const std::string &var_name, int var_gold) {
    this->setName(var_name);
    this->setGold(var_gold);
    this->setIsValid(true);
}

int xrand(int valstart, int valend) {
    return (rand() % (valend - valstart) ) + valstart;
}



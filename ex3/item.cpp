//
// Created by juerg on 20.02.2022.
//
#include <iostream>
#include "item.h"

using namespace std;

/*
void Item::initItem(const std::string &var_name, int var_gold) {
    this->setName(var_name);
    this->setGold(var_gold);
    this->setIsValid(true);
}
*/

int xrand(int valstart, int valend) {
    return (rand() % (valend - valstart) ) + valstart;
}

std::ostream &operator<<(std::ostream &output, const Item &item) {
    std::cout << item.getName() << "(" << item.getGold() << ")";
    return output;
}




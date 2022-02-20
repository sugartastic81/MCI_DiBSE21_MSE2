//
// Created by juerg on 20.02.2022.
//
#ifndef PROTOTYP_ITEM_H
#define PROTOTYP_ITEM_H

#include <string>

struct Item_t {
    std::string name;
    int gold;
    bool isValid;
};

void initItem(Item_t* item, char* name, int gold);
void initItem(Item_t* item);

#endif //PROTOTYP_ITEM_H


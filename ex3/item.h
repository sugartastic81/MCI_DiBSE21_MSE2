//
// Created by juerg on 20.02.2022.
//
#define INVENTORYSIZE 10
#define STARTINGINVENTORY 4
#define DIFFERENTINVENTORIES 6

#define GEARSIZE 2

#ifndef PROTOTYP_ITEM_H
#define PROTOTYP_ITEM_H

#include <string>
#include <iostream>

using namespace std;

int xrand(int valstart, int valend);

class Item {
private:
    std::string name;
    int gold;
    bool isValid;
public:
    Item() : gold(0), isValid(false) {}

    Item(const std::string& name, int gold) : name(name), gold(gold), isValid(true) {
        //cout << "initialized -> itemname: " << name << " | gold: " << gold << " | isValid: " << isValid << std::endl;
    }

    // Getter & Setter für Variable name
    void setName(const std::string &var_name) {
        this->name = var_name;
    }
    std::string getName() const {
        return name;
    }

    // Getter & Setter für Variable gold
    void setGold(int var_gold) {
        this->gold = var_gold;
    }
    int getGold() const {
        return gold;
    }

    // Getter & Setter für Variable isValid
    void setIsValid(bool var_isValid) {
        this->isValid = var_isValid;
    }
    bool getIsValid() const {
        return isValid;
    }

};

std::ostream &operator<<(std::ostream &output, const Item &item);

#endif //PROTOTYP_ITEM_H


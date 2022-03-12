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

int random_number_generator (int valstart, int valend);

class Item {
private:
    std::string name;
    int gold;
    bool isValid;
public:
    void initItem();
    void initItem(const std::string &name, int gold);

    // Getter & Setter für Variable name
    void setName(const std::string &var_name) {
        this->name = var_name;
    }
    std::string getName() {
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

#endif //PROTOTYP_ITEM_H


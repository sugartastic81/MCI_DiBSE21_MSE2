// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#ifndef DAYONE_GOODS_H
#define DAYONE_GOODS_H

#include <string>
#include <iostream>

using namespace std;

class Good {
    public:
        virtual ~Good(){};
        virtual int scanGood() = 0;
};

// standard goods
class standardGoods : public Good {
public:
    virtual int scanGood() override;
};

// hazardous goods
class hazardousGoods : public Good {
public:
    virtual int scanGood() override;
};

// frozen goods
class frozenGoods : public Good {
public:
    virtual int scanGood() override;
};

#endif //DAYONE_GOODS_H

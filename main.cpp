// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include <iostream>
#include "Ware.h"
#include "Sortiment.h"
#include "Algorithms.h"
#include "exceptions.h"

// https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
std::string gen_random(const int len) {
    static const char alphanum[] =
            //"0123456789"
            //"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    tmp_s += "Ware_";
    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return tmp_s;
}



int main() {

    std::srand(time(0));

    std::cout << std::endl;
    std::cout << "Algorithmen und Datenstrukturen - Uebungsblatt 1 - Antiquities Dealership" << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;


    try {

        for(int j=1; j < 7; j++ ) {
            Sortiment DealerHero;
            for(int i=0; i < MAXELEMENTS+1; i++ ) {
                DealerHero.addWare( new Ware(gen_random(6), rand() % 899 + 100, rand() % 9 + 1, rand() % 89 + 10, rand() % 89 + 10) );
            }
            DealerHero.sort(j);
        }


        std::cout << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "Ende Uebeung." << std::endl;
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }



    return 0;
}

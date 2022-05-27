// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include <iostream>
#include "Ware.h"
#include "Sortiment.h"
#include "Algorithms.h"
#include "exceptions.h"
#include "PerformanceTest.h"
#include "skyrimitemlist.h"

int main() {
    Skyrimitemlist itemlist;
    srand( (unsigned) time(nullptr));
    std::cout << std::endl << "***************************" << std::endl << "Antiquities Dealership of Skyrim Items - Fun with Sorting Algorithms!" << std::endl << "***************************" << std::endl;

    try {
        for(int j=1; j <= 5; j++ ) {
            Sortiment DealerHero;
            std::cout << std::endl << std::endl <<"------------------------------------" << std::endl << "Generates random new assortment for modus " << j << "." << std::endl << "------------------------------------" << std::endl;

            for(int i=0; i < 10; i++ ) {
                DealerHero.addWare( new Ware(itemlist.skyrimitems[rand() % SKYRIMITEMCOUNT], rand() % 899 + 100, rand() % 9 + 1, rand() % 89 + 10, rand() % 89 + 10) );
            }

            DealerHero.view();
            DealerHero.sort(j);
            DealerHero.view();
            std::cout << "------------------------------------" << std::endl << "End of modus " << j << "." << std::endl << "------------------------------------" << std::endl << std::endl;
        }
        std::cout << std::endl << "***************************" << std::endl << "End of the simulation." << std::endl << "***************************" << std::endl << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

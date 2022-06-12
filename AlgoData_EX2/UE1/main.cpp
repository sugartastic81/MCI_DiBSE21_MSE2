// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include <iostream>
#include "Ware.h"
#include "skyrimitemlist.h"
#include "extendedBinaryTree.h"
#include "extendedBinaryTreeNode.h"

int main() {
    Skyrimitemlist itemlist;
    srand( (unsigned) time(nullptr));
    std::cout << std::endl << "***************************" << std::endl << "   Dealership of Skyrim" << std::endl << "***************************" << std::endl;

    try {
        std::cout << std::endl << std::endl <<"------------------------------------" << std::endl << "Generates random new assortment for: Aufgabe 2.1 - Binaerer Suchbaum / Binary Search Tree" << std::endl << "------------------------------------" << std::endl;

/*
        Sortiment DealerHero;

        for(int i=0; i < 10; i++ ) {
            DealerHero.addWare( new Ware(itemlist.skyrimitems[rand() % SKYRIMITEMCOUNT], rand() % 899 + 100, rand() % 9 + 1, rand() % 89 + 10, rand() % 89 + 10) );
        }

        ExtendedBinaryTree tree(&ware1);

        DealerHero.view();
        DealerHero.sort();
        DealerHero.view();
        std::cout << "------------------------------------" << std::endl << "End of: Aufgabe 2.1 - Binaerer Suchbaum / Binary Search Tree" << std::endl << "------------------------------------" << std::endl << std::endl;


*/
        Ware ware[MAXWAREROWS];
        for( int i = 0; i < MAXWAREROWS; i++) {
            ware[i].setBezeichnung(itemlist.skyrimitems[rand() % SKYRIMITEMCOUNT]);
            ware[i].setSeriennummer(rand() % 899 + 100);
            ware[i].setGewicht((double)(rand() % 899 + 100)/100);
            ware[i].setEinkaufspreis((double)(rand() % 3999 + 1000)/100);
            ware[i].setVerkaufspreis((double) ware[i].getEinkaufspreis() * 1.2 );
            ware[i].printWare();
        }

        ExtendedBinaryTree tree(&ware[0]);
        for( int i = 1; i < MAXWAREROWS; i++) {
            tree.insert(&ware[i]);
        }

        std::cout << std::endl << std::endl <<"------------------------------------" << std::endl << "printPreorder()\t\t";
        std::cout << tree.printPreorder();
        for( int i = 0; i < MAXWAREROWS; i++) {
            std::cout << std::endl << "printPreorder(" << ware[i].getVerkaufspreis() << ")\t" << tree.printPreorder(&ware[i]);
        }
        std::cout << std::endl << std::endl <<"------------------------------------" << std::endl << "printPostorder()\t";
        std::cout << tree.printPostorder();
        for( int i = 0; i < MAXWAREROWS; i++) {
            std::cout << std::endl << "printPostorder(" << ware[i].getVerkaufspreis() << ")\t" << tree.printPostorder(&ware[i]);
        }
        std::cout << std::endl << std::endl <<"------------------------------------" << std::endl << "printInorder()\t\t";
        std::cout << tree.printInorder();
        for( int i = 0; i < MAXWAREROWS; i++) {
            std::cout << std::endl << "printInorder(" << ware[i].getVerkaufspreis() << ")\t" << tree.printInorder(&ware[i]);
        }

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    //std::cout << std::endl << "***************************" << std::endl << "End of the simulation." << std::endl << "***************************" << std::endl << std::endl;
    return 0;
}

// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include <iostream>
#include "doublyLinkedList.h"

#define LISTLENGTH 8


int main() {
    srand( (unsigned) time(nullptr));
    DoublyLinkedList firstlist;
    firstlist.print();

    std::cout << std::endl << "INSERT RANDOM ITEMS TO THE FIRST LIST" << std::endl << std::endl;
    for( int i = 0; i < LISTLENGTH; i++) {
        firstlist.insertSorted(rand() % 89 + 10);
    }
    firstlist.print();


    DoublyLinkedList secondlist;
    std::cout << std::endl << "INSERT RANDOM ITEMS TO A SECOND LIST" << std::endl << std::endl;
    for( int i = 0; i < LISTLENGTH/2; i++) {
        secondlist.insertSorted(rand() % 89 + 10);
    }
    secondlist.print();
    std::cout << std::endl << "INTEGRATES SECOND LIST SORTED IN FIRST LIST" << std::endl << std::endl;
    firstlist.integrates(&secondlist);
    firstlist.print();


    DoublyLinkedList thirdlist;
    std::cout << std::endl << "INSERT RANDOM ITEMS TO A THIRD LIST" << std::endl << std::endl;
    for( int i = 0; i < LISTLENGTH/2; i++) {
        thirdlist.insertSorted(rand() % 89 + 10);
    }
    thirdlist.print();
    std::cout << std::endl << "APPENDS THIRD LIST ON FIRST LIST" << std::endl << std::endl;
    firstlist.append(&thirdlist);
    firstlist.print();


    DoublyLinkedList fourthlist;
    std::cout << std::endl << "INSERT RANDOM ITEMS TO A FOURTH LIST" << std::endl << std::endl;
    for( int i = 0; i < LISTLENGTH; i++) {
        fourthlist.insertSorted(rand() % 89 + 10);
    }
    fourthlist.print();
    std::cout << std::endl << "SPLICES FOURTH LIST IN FIRST LIST ON POS " << (LISTLENGTH/2) << std::endl << std::endl;
    firstlist.splice(&fourthlist, (LISTLENGTH/2));
    firstlist.print();



    std::cout << std::endl << "DELETE RANDOM ITEMS" << std::endl;
    for( int i = 0; i < LISTLENGTH; i++) {
        firstlist.deleteItem(rand() % 89 + 10);
    }
    std::cout << std::endl;

    firstlist.print();




    return 0;
}

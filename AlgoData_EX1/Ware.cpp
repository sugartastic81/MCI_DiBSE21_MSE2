// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include "Ware.h"

void swapWaren(Ware *waren[], int posA, int posB) {
    Ware warendummy;
    //std::cout << " Ware 1 ::: " << this->waren[posA]->getBezeichnung() << ", SNR " << this->waren[posA]->getSeriennummer() << ", Gewicht " << this->waren[posA]->getGewicht() << " kg, EP " << this->waren[posA]->getEinkaufspreis() << " EUR, VP " << this->waren[posA]->getVerkaufspreis()<< " EUR." << std::endl;
    //std::cout << " Ware 2 ::: " << this->waren[posB]->getBezeichnung() << ", SNR " << this->waren[posB]->getSeriennummer() << ", Gewicht " << this->waren[posB]->getGewicht() << " kg, EP " << this->waren[posB]->getEinkaufspreis() << " EUR, VP " << this->waren[posB]->getVerkaufspreis()<< " EUR." << std::endl;

    warendummy.setBezeichnung( waren[posA]->getBezeichnung() );
    warendummy.setSeriennummer( waren[posA]->getSeriennummer() );
    warendummy.setGewicht( waren[posA]->getGewicht() );
    warendummy.setEinkaufspreis( waren[posA]->getEinkaufspreis() );
    warendummy.setVerkaufspreis( waren[posA]->getVerkaufspreis() );

    waren[posA]->setBezeichnung( waren[posB]->getBezeichnung() );
    waren[posA]->setSeriennummer( waren[posB]->getSeriennummer() );
    waren[posA]->setGewicht( waren[posB]->getGewicht() );
    waren[posA]->setEinkaufspreis( waren[posB]->getEinkaufspreis() );
    waren[posA]->setVerkaufspreis( waren[posB]->getVerkaufspreis() );

    waren[posB]->setBezeichnung( warendummy.getBezeichnung() );
    waren[posB]->setSeriennummer( warendummy.getSeriennummer() );
    waren[posB]->setGewicht( warendummy.getGewicht() );
    waren[posB]->setEinkaufspreis( warendummy.getEinkaufspreis() );
    waren[posB]->setVerkaufspreis( warendummy.getVerkaufspreis() );

    //std::cout << " Ware 1 ::: " << this->waren[posA]->getBezeichnung() << ", SNR " << this->waren[posA]->getSeriennummer() << ", Gewicht " << this->waren[posA]->getGewicht() << " kg, EP " << this->waren[posA]->getEinkaufspreis() << " EUR, VP " << this->waren[posA]->getVerkaufspreis()<< " EUR." << std::endl;
    //std::cout << " Ware 2 ::: " << this->waren[posB]->getBezeichnung() << ", SNR " << this->waren[posB]->getSeriennummer() << ", Gewicht " << this->waren[posB]->getGewicht() << " kg, EP " << this->waren[posB]->getEinkaufspreis() << " EUR, VP " << this->waren[posB]->getVerkaufspreis()<< " EUR." << std::endl;
}
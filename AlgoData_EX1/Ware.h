// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#ifndef ABGABE1_WARE_H
#define ABGABE1_WARE_H

#include <iostream>
using namespace std;

class Ware {
private:
    std::string bezeichnung;
    int seriennummer;
    double gewicht;
    double einkaufspreis;
    double verkaufspreis;
public:
    Ware() {
        //std::cout << "Empty constructor Ware. " << std::endl;
    }

    Ware(const std::string &bezeichnung, int seriennummer, double gewicht, double einkaufspreis, double verkaufspreis)
            : bezeichnung(bezeichnung), seriennummer(seriennummer), gewicht(gewicht), einkaufspreis(einkaufspreis),
              verkaufspreis(verkaufspreis) {

    }

    virtual ~Ware() {
        //std::cout << "Destructor Ware. " << std::endl;
    }

    const string &getBezeichnung() const {
        return bezeichnung;
    }

    int getSeriennummer() const {
        return seriennummer;
    }

    double getGewicht() const {
        return gewicht;
    }

    double getEinkaufspreis() const {
        return einkaufspreis;
    }

    double getVerkaufspreis() const {
        return verkaufspreis;
    }

    void setBezeichnung(const string &bezeichnung) {
        Ware::bezeichnung = bezeichnung;
    }

    void setSeriennummer(int seriennummer) {
        Ware::seriennummer = seriennummer;
    }

    void setGewicht(double gewicht) {
        Ware::gewicht = gewicht;
    }

    void setEinkaufspreis(double einkaufspreis) {
        Ware::einkaufspreis = einkaufspreis;
    }

    void setVerkaufspreis(double verkaufspreis) {
        Ware::verkaufspreis = verkaufspreis;
    }


};

void swapWaren(Ware *waren[], int posA, int posB);

#endif //ABGABE1_WARE_H

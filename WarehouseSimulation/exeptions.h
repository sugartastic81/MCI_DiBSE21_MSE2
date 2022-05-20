// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#ifndef DAYONE_EXEPTIONS_H
#define DAYONE_EXEPTIONS_H

#include <exception>
#include <stdexcept>

class WarehouseException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};


class DefectiveGoodExceptions : public WarehouseException {
public:
    using WarehouseException::WarehouseException;
};

class ScanErrorExceptions : public WarehouseException {
public:
    using WarehouseException::WarehouseException;
};

#endif //DAYONE_EXEPTIONS_H

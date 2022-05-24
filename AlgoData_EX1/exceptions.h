// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021
#ifndef ABGABE1_EXCEPTIONS_H
#define ABGABE1_EXCEPTIONS_H

class AlgorithmException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class FullSortimentException : public AlgorithmException {
public:
    using AlgorithmException::AlgorithmException;
};



#endif //ABGABE1_EXCEPTIONS_H

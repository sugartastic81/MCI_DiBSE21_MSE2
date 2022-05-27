// Name: Jürgen Zangerl
// Matrikelnummer: 021625
// MCI DiBSE JG 2021

#ifndef ABGABE1_PERFORMANCETEST_H
#define ABGABE1_PERFORMANCETEST_H

#include <cstring>
#include <chrono>
#include <vector>
#include "Ware.h"
#include "Sortiment.h"
#include "Algorithms.h"
#include "exceptions.h"

class PerformanceTest {
private:
    double minExecutionTime;
    double maxExecutionTime;
    double totalExecutionTime;
    std::string algorithmName;
public:
    PerformanceTest() {
        this->minExecutionTime = 0;
        this->maxExecutionTime = 0;
        this->totalExecutionTime = 0;
        this->algorithmName = "";
    };

    double getMinExecutionTime() {
        return this->minExecutionTime;
    }

    double getMaxExecutionTime() {
        return this->maxExecutionTime;
    }

    double getTotalExecutionTime() {
        return this->totalExecutionTime;
    }

    const std::string& getAlgorithmName() {
        return this->algorithmName;
    }

    void setAlgorithmName(std::string name) {
        this->algorithmName = name;
    }

    void processResult(std::chrono::high_resolution_clock::time_point startTime, std::chrono::high_resolution_clock::time_point endTime);

};


#endif //ABGABE1_PERFORMANCETEST_H

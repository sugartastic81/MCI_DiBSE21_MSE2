// Name: Jürgen Zangerl
// Matrikelnummer: 021625
// MCI DiBSE JG 2021

#include <cstring>
#include <chrono>
#include <vector>
#include "PerformanceTest.h"
#include "Ware.h"
#include "Sortiment.h"
#include "Algorithms.h"
#include "exceptions.h"

void PerformanceTest::processResult(std::chrono::high_resolution_clock::time_point startTime, std::chrono::high_resolution_clock::time_point endTime) {
    std::chrono::duration<double, std::milli> duration = (endTime - startTime);
    double execTime = duration.count();
    this->totalExecutionTime += execTime;
    if(execTime < this->minExecutionTime) {
        this->minExecutionTime = execTime;
        return;
    } else if(execTime > this->maxExecutionTime) {
        this->maxExecutionTime = execTime;
        return;
    }
}

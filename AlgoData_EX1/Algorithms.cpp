// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include "Algorithms.h"
#include "Ware.h"
#include <cstring>
#include <iostream>

// QuickSort Algorithm inspired by https://www.softwaretestinghelp.com/quick-sort/#C_Example
int quicksort_partition(Ware *waren[], int low, int high){
    int pivot = waren[high]->getSeriennummer();
    int i = low-1;

    for (int j = low; j <= high- 1; j++)
    {
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (waren[j]->getSeriennummer() <= pivot)
        {
            i++;    // increment index of smaller element
            swapWaren(waren, i, j);
        }
    }
    swapWaren(waren, i+1, high);
    return i+1;
}

void quicksort_seriennummer(Ware *waren[], int low, int high){
    if (low < high)
    {
        //partition the array
        int partition = quicksort_partition(waren, low, high);

        //sort the sub arrays independently
        quicksort_seriennummer(waren, low, partition - 1);
        quicksort_seriennummer(waren, partition + 1, high);
    }
}



//BubbleSort Algorithm inspired by https://www.geeksforgeeks.org/bubble-sort/
void bubblesort_gewicht(Ware *waren[], int WarenCounted) {
    for (int index = 0; index < WarenCounted - 1; index++) {
        for (int j = 0; j < WarenCounted - index - 1; j++) {
            if (waren[j]->getGewicht() > waren[j + 1]->getGewicht()) {
                swapWaren(waren, j, j+1);
            }
        }
    }
}


// MergeSort Algorithm inspired by the great Pascal
void mergesort_bezeichnung(Ware *waren[], int left, int right) {
    //std::cout  << "_start mergesort_bezeichnung(..., left " << left << ", right " << right << ")" << std::endl;
    if(left < right) {
        int middle = left+(right-left)/2;
        mergesort_bezeichnung(waren, left, middle);
        mergesort_bezeichnung(waren, middle+1, right);
        merge_bezeichnung(waren, left, middle, right);
    }
    //std::cout  << "_end mergesort_bezeichnung()" << std::endl;
}

void merge_bezeichnung(Ware *waren[], int left, int middle, int right) {
    //std::cout  << "_start merge_bezeichnung(..., left " << left << ", middle " << middle << ", right " << right << ")" << std::endl;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    Ware* leftWaren[n1];
    std::memset(leftWaren, 0, sizeof(Ware*)*n1);

    Ware* rightWaren[n2];
    std::memset(rightWaren, 0, sizeof(Ware*)*n2);

    for(int i= 0; i < n1; i++) {
        leftWaren[i] = waren[left + i];
    }
    for(int j = 0; j < n2; j++) {
        rightWaren[j] = waren[middle + j + 1];
    }

    int k = 0, l = 0, m = left;
    while(k < n1 && l < n2){
        int compare;
        if(rightWaren[l] == nullptr) {
            compare = -1;
        } else if(leftWaren[k] == nullptr) {
            compare = 1;
        } else {
            compare = leftWaren[k]->getBezeichnung().compare(rightWaren[l]->getBezeichnung());
        }

        if(compare <= 0) {
            waren[m] = leftWaren[k];
            k++;
        } else {
            waren[m] = rightWaren[l];
            l++;
        }
        m++;
    }

    while(k<n1){
        waren[m] = leftWaren[k];
        k++;
        m++;
    }

    while(l<n2){
        waren[m] = rightWaren[l];
        l++;
        m++;
    }
    //std::cout  << "_end merge_bezeichnung()" << std::endl;
}

// InsertionSortBase Algorithm inspired by the great Pascal
void insertionSortBase_buyprice(Ware *waren[], int WarenCounted) {
    int i = 0;
    while(i < WarenCounted){
        int j = i;
        while(j > 0 && waren[j-1]->getEinkaufspreis() > waren[j]->getEinkaufspreis()){
            swapWaren(waren, j, (j-1));
            j--;
        }
        i++;
    }
}

void insertionSortOptimized_sellprice(Ware *waren[], int WarenCounted) {
    int i = 0;
    while(i < WarenCounted){
        int j = i;
        while(j > 0 && waren[j-1]->getVerkaufspreis() > waren[j]->getVerkaufspreis()){
            swapWaren(waren, j, (j-1));
            j--;
        }
        i++;
    }
}
// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#ifndef ABGABE1_ALGORITHMS_H
#define ABGABE1_ALGORITHMS_H

#include "Sortiment.h"
#include "Ware.h"

int quicksort_partition(Ware *waren[], int low, int high);
void quicksort_seriennummer(Ware *waren[], int low, int high);
void bubblesort_gewicht(Ware *waren[], int WarenCounted);
void mergesort_bezeichnung(Ware *waren[], int left, int right);
void merge_bezeichnung(Ware *waren[], int left, int middle, int right);
void insertionSortBase_buyprice(Ware *waren[], int WarenCounted);
void insertionSortOptimized_sellprice(Ware *waren[], int WarenCounted);

#endif //ABGABE1_ALGORITHMS_H

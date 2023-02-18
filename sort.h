#ifndef SORT_H_
#define SORT_H_
#include <iostream>
#include <time.h>
#include <cstring>
#include <chrono>

void showEl(const int*, int, char);

void setRandom(int*, int, int, int);

void showMass(int*, int);

void setRandom(int*, int, int);

void swap(int&, int&);

void SelectionSort(int*, int);

void insertionSort(int*, int);

void quickSort(int*, int);

void mergeSort(int*, int);

static void merge(int*, int, int);

void bubbleSort(int*, int);

bool getStatInfo(int*, int, int*, int);

int search(int*, int, int);

void countSort(int*, int);


#endif // SORT_HPP




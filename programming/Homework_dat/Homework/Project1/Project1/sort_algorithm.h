#pragma once
#ifndef SORT_ALGORITHM

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

extern int max_index;
extern int max_value;


//generate random arrray
void generate_random_array(int*&, int&);


//input and output array
void inputArray(int*&, int&);
void outputArray(int*, int);

// 1. Selection Sort
// https://www.geeksforgeeks.org/selection-sort/
void selectionSort(int *, int);

// 2. Interchange Sort (Exchange Sort)
//https://www.geeksforgeeks.org/interchange-sort-exchange-sort/
void interchangeSort(int *, int);

// 3. Insertion Sort
//https://www.geeksforgeeks.org/insertion-sort/
void insertionSort(int *, int);

// 4. Binary Insertion Sort
//https://www.geeksforgeeks.org/binary-insertion-sort/
int binarySearch(int *, int, int, int, int);

void binaryInsertionSort(int *, int);

//bubble sort
void bubbleSort(int*, int);

// shaker sort
void shakerSort(int*, int);

// counting sort
void countingSort(int*, int);

//quick sort
void quickSort(int*, int, int, int);

//merge sort algorithms
void merge(int*&, int, int, int);
void merge_sort(int*&, int, int);

//heap sort algorithms
void heapify(int*&, int, int);
void heap_sort(int*&, int);

//radix sort algoritms
int getMax(int*, int);
void countSort(int, int);
void radix_sort(int*, int);

//shell sort algorithms
void shell_sort(int*&, int);

// Calculate the time of sorting algorithm
void writeToFile(int*, const int, const string&);


#endif // !SORT_ALGORITHM

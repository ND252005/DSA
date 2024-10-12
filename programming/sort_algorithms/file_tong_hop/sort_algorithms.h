#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

extern int max_index;
extern int max_value;


//generate random arrray
void generate_random_array(int *&a, int &n);


//input and output array
void inputArray(int *&a, int &n);
void outputArray(int *a, int n);

//merge sort algorithms
void merge(int *&a, int l, int m, int r);
void merge_sort(int *&a, int l, int r);

//heap sort algorithms
void heapify(int *&a, int N, int i);
void heap_sort(int *&a, int N);

//radix sort algoritms
int getMax(int *arr, int n);
void countSort(int *arr, int n, int exp);
void radix_sort(int *arr, int n);

//shell sort algorithms
void shell_sort(int *&a, int n);

#endif
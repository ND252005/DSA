#include "sort_algorithm.h"

int max_index = 1E6;
int max_value = 1E4;
//generate random array 
void generate_random_array(int*& a, int& n) {
    cout << "The quantities of random array: "; cin >> n;
    a = new int[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % (max_value + 1);
    }
}



//Input and output
void inputArray(int*& a, int& n) {
    a = new int[n];
    cout << "Nhap so luong phan tu mang: ";
    cin >> n;
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void outputArray(int* a, int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void selectionSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}

void interchangeSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i])
                swap(arr[i], arr[j]);
        }
    }
}

void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int binarySearch(int *arr, int n, int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == arr[mid]) return mid + 1;
        if (item > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

void binaryInsertionSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = binarySearch(arr, n, key, 0, i - 1);

        for (int k = i - 1; k >= j; k--) {
            arr[k + 1] = arr[k];
        }

        arr[j] = key;
    }
}

void bubbleSort(int* arr, int n)
{
    bool canSwap;

    for (int i = 0; i < n - 1; i++) 
    {
        canSwap = false;
        for (int j = 0; j < n - i - 1; j++) 
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
                canSwap = true;
            }

        if (!canSwap)
            break;
    }
}

// Reference: https://www.geeksforgeeks.org/cocktail-sort/
void shakerSort(int* a, int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        // reset the swapped flag on entering
        // the loop, because it might be true from
        // a previous iteration.
        swapped = false;

        // loop from left to right same as
        // the bubble sort
        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        // if nothing moved, then array is sorted.
        if (!swapped)
            break;

        // otherwise, reset the swapped flag so that it
        // can be used in the next stage
        swapped = false;

        // move the end point back by one, because
        // item at the end is in its rightful spot
        --end;

        // from right to left, doing the
        // same comparison as in the previous stage
        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        // increase the starting point, because
        // the last stage would have moved the next
        // smallest number to its rightful spot.
        ++start;
    }
}

void countingSort(int* arr, int n)
{
    if (n <= 0) 
        return;

    int max = *max_element(arr, arr + n);
    int* count = new int[max + 1];

    for (int i = 0; i <= max; i++) 
        count[i] = 0;

    for (int i = 0; i < n; i++) 
        count[arr[i]]++;

    int index = 0;
    for (int i = 0; i <= max; i++)
        while (count[i] > 0) 
        {
            arr[index++] = i;
            count[i]--;
        }

    delete[] count;
}

void quickSort(int* arr, int n, int l, int r)
{
    int p = arr[l + ((r - l) >> 1)];
    int i = l;
    int j = r;
    while (i <= j)
    {
        while (arr[i] < p)
            i++;
        while (arr[j] > p)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (i < r)
        quickSort(arr, n, i, r);
    if (j > l)
        quickSort(arr, n, l, j);
}

//https://www.geeksforgeeks.org/heap-sort/
//heap sort algorithms
void heapify(int*& a, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n and a[l] > a[largest])
        largest = l;
    if (r < n and a[r] > a[largest])
        largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heap_sort(int*& a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}


//Tham khao thuat toan roi tu viet lai 
//merge sort algorithms
void merge(int*& a, int l, int m, int r) {
    int* b = new int[m - l + 1];
    int* c = new int[r - m];
    for (int i = 0; i <= m - l; i++) {
        b[i] = a[l + i];
    }
    for (int i = 0; i < r - m; i++) {
        c[i] = a[m + i + 1];
    }
    int count = l; int i = 0; int j = 0;
    while (i < m - l + 1 && j < r - m) {
        if (b[i] <= c[j]) {
            a[count++] = b[i++];
        }
        else {
            a[count++] = c[j++];
        }
    }

    while (i < m - l + 1) {
        a[count++] = b[i++];
    }
    while (j < r - m) {
        a[count++] = c[j++];
    }
    delete[] b;
    delete[] c;
}

void merge_sort(int*& a, int l, int r) {
    if (l >= r)
        return;
    merge_sort(a, l, (l + r) / 2);
    merge_sort(a, (l + r) / 2 + 1, r);
    merge(a, l, (l + r) / 2, r);

}


//https://www.geeksforgeeks.org/radix-sort/
//radix sort algorithms
int getMax(int* arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[]
// according to the digit
// represented by exp.
void countSort(int* arr, int n, int exp)
{

    // Output array
    int* output = new int[n];
    int i, count[10] = { 0 };

    // Store count of occurrences
    // in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i]
    // now contains actual position
    // of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[],
    // so that arr[] now contains sorted
    // numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[]
// of size n using Radix Sort
void radix_sort(int* arr, int n)
{

    // Find the maximum number to
    // know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit.
    // Note that instead of passing digit
    // number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}


//https://codelearn.io/learning/data-structure-and-algorithms?activityType=12&activityId=1290
//shell sort algoritms 
void shell_sort(int*& a, int n) {
    int interval, i, j, temp;
    for (interval = n / 2; interval > 0; interval /= 2) {
        for (i = interval; i < n; i++) {
            temp = a[i];
            for (j = i; j >= interval && a[j - interval] > temp; j -= interval) {
                a[j] = a[j - interval];
            }
            a[j] = temp;
        }
    }
}
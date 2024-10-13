#include "sort_algorithm.h"

int main() {
    bool is_program = true;
    while (is_program) {
        cout << "\n**************MENU***************" << endl;
        cout << "1. Selection Sort" << endl;
        cout << "2. Interchange Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Binary Insertion Sort" << endl;
        cout << "5. Bubble Sort" << endl;
        cout << "6. Shake/Shaker Sort" << endl;
        cout << "7. Counting Sort" << endl;
        cout << "8. Quick Sort" << endl;
        cout << "9. Merge Sort" << endl;
        cout << "10. Heap Sort" << endl;
        cout << "11. Shell Sort" << endl;
        cout << "12. Radix Sort" << endl;
        int n; int* a;
        generate_random_array(a, n);
        outputArray(a, n);
        cout << "Please choose an algorithm (Enter an interger):";
        int k; cin >> k;
        switch (k) {
        case 1:
            cout << "Your choice is selection sort.\n";
            selectionSort(a, n);
            outputArray(a, n);
            break;
        case 2:
            cout << "Your choice is interchange sort.\n";
            interchangeSort(a, n);
            outputArray(a, n);
            break;
        case 3:
            cout << "Your choice is insertion sort.\n";
            insertionSort(a, n);
            outputArray(a, n);
            break;
        case 4:
            cout << "Your choice is binary insertion sort.\n";
            binaryInsertionSort(a, n);
            outputArray(a, n);
            break;
        case 5:
            cout << "Your choice is bubble sort.\n";
            bubbleSort(a, n);
            outputArray(a, n);
            break;
        case 6:
            cout << "Your choice is shaker sort.\n";
            shakerSort(a, n);
            outputArray(a, n);
            break;
        case 7:
            cout << "Your choice is counting sort.\n";
            countingSort(a, n);
            outputArray(a, n);
            break;
        case 8:
            cout << "Your choice is quick sort.\n";
            quickSort(a, n, 0, n - 1);
            outputArray(a, n);
            break;
        case 9:
            cout << "Your choice is merge sort." << endl;
            merge_sort(a, 0, n - 1);
            outputArray(a, n);
            break;
        case 10:
            cout << "Your choice is heap sort." << endl;
            heap_sort(a, n);
            outputArray(a, n);
            break;
        case 11:
            cout << "Your choice is shell sort." << endl;
            shell_sort(a, n);
            outputArray(a, n);
            break;
        case 12:
            cout << "Your choice is radix sort." << endl;
            radix_sort(a, n);
            outputArray(a, n);
            break;
        }
        char x;
        cout << "Do you want to continue (y/n):"; cin >> x;
        if (x == 'n') {
            is_program = false;
            cout << "See you again!";
        }
        delete[] a;
    }
    return 0;
}
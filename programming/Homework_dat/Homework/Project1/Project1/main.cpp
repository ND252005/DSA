#include "sort_algorithm.h"

int main() {
    srand(time(0));
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

        int n;
        int* a = NULL;
        generate_random_array(a, n);
        outputArray(a, n);

        cout << "Please choose an algorithm (Enter an integer): ";
        int k;
        cin >> k;

        vector<int> arrCopy(a, a + n); // Copy original array

        auto start = high_resolution_clock::now(); // Start timing

        switch (k) {
        case 1:
            cout << "Your choice is selection sort.\n";
            selectionSort(a, n);
            break;
        case 2:
            cout << "Your choice is interchange sort.\n";
            interchangeSort(a, n);
            break;
        case 3:
            cout << "Your choice is insertion sort.\n";
            insertionSort(a, n);
            break;
        case 4:
            cout << "Your choice is binary insertion sort.\n";
            binaryInsertionSort(a, n);
            break;
        case 5:
            cout << "Your choice is bubble sort.\n";
            bubbleSort(a, n);
            break;
        case 6:
            cout << "Your choice is shaker sort.\n";
            shakerSort(a, n);
            break;
        case 7:
            cout << "Your choice is counting sort.\n";
            countingSort(a, n);
            break;
        case 8:
            cout << "Your choice is quick sort.\n";
            quickSort(a, n, 0, n - 1);
            break;
        case 9:
            cout << "Your choice is merge sort.\n";
            merge_sort(a, 0, n - 1);
            break;
        case 10:
            cout << "Your choice is heap sort.\n";
            heap_sort(a, n);
            break;
        case 11:
            cout << "Your choice is shell sort.\n";
            shell_sort(a, n);
            break;
        case 12:
            cout << "Your choice is radix sort.\n";
            radix_sort(a, n);
            break;
        default:
            cout << "Invalid choice. Exiting.\n";
            is_program = false;
            continue;
        }

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "Time taken by algorithm: " << duration.count() << " milliseconds\n";

        outputArray(a, n);
        writeToFile(a, n, "sorted_array.txt");
        cout << "Sorted array has been written to 'sorted_array.txt'.\n";

        char cont;
        cout << "Do you want to continue (y/n): ";
        cin >> cont;

        if (cont == 'n' || cont == 'N') {
            cout << "See you again\n";
            is_program = false;
        }

        delete[] a; // Free memory
    }

    return 0;
}
#include "sort_algorithms.h"
#include <iostream>
using namespace std;


int main() {
    bool is_program = true;
    while(is_program) {
        cout << "**************MENU***************" << endl;
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
        int n; int *a;
        generate_random_array(a, n);
        outputArray(a, n);
        cout << "Please choose an algorithm (Enter an interger):"; 
        int k; cin >> k;
        switch(k) {
            case 9:
                cout << "Your choose is merge sort." << endl;
                merge_sort(a, 0, n - 1);
                outputArray(a, n);
                break;
            case 10:
                cout << "Your choose is heap sort." << endl;
                heap_sort(a, n);
                outputArray(a, n);
                break;
            case 11:
                cout << "Your choose is shell sort." << endl;
                shell_sort(a, n);
                outputArray(a, n);
                break;
            case 12:
                cout << "Your choose is radix sort." << endl;
                radix_sort(a, n);
                outputArray(a, n);
                break;
        }
        char x;
        cout << "Do you want to continue(y/n):"; cin >> x;
        if(x == 'n'){
            is_program = false;
            cout << "See you again!";
        }
        delete[] a;
    }
    return 0;
}
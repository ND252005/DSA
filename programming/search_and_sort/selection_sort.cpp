#include <iostream>
using namespace std;

void inputArray(int *&a, int &n) {
    // First input n
    cin >> n;
    a = new int[n];  // Then allocate memory for the array
    for(int i = 0; i < n; i++)
        cin >> a[i];
}

void outputArray(int *a, int n) {
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}

void Selection_sort(int *&arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[min] > arr[j]) {  // Compare with arr[j] instead of arr[i]
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

int main() {
   int *a = NULL, n;
   inputArray(a, n);
   Selection_sort(a, n);
   outputArray(a, n);
   delete[] a;  // Free allocated memory
   return 0;
}

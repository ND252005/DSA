#include <iostream>
using namespace std;


int partition(int arr[], int low, int high, int mode) {
    int pivot = arr[high]; 
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if ((mode == 0 && arr[j] < pivot) || (mode == 1 && arr[j] > pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int mode) {
    if (low < high) {
        int pi = partition(arr, low, high, mode);

        quickSort(arr, low, pi - 1, mode);
        quickSort(arr, pi + 1, high, mode);
    }
}

int main() {
    int n;
    
    // Nhập số phần tử và chế độ
    cin >> n ;
    
    int *a = new int[n];
    int *b = new int[n];
    int *c = new int [n];
    int nb = 0, nc = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2 == 0){
            b[nb++] = a[i];
        }else{
            c[nc++] = a[i];
        }
    }

    quickSort(b, 0, nb - 1, 0);
    quickSort(c, 0, nc - 1, 1);

    int k = 0, z = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            swap(a[i], b[k]);
            k++;
        }else{
            swap(a[i], c[z]);
            z++;
        }
    }
    cout<<"Sorted Array: ";   
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}



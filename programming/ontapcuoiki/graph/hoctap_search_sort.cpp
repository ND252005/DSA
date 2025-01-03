#include <iostream>
using namespace std;

//binarysearch
int binary_search(int *a, int l, int r, int x) {
    while (l <= r) {
        int mid = (l + r)/2;
        if(a[mid] == x) return mid;
        if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

//selection sort 
void selection_sort(int *a, int n) {
    for(int i = 0; i < n; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(a[min] > a[j]) {
                swap(a[min], a[j]);
                min = j;
            }
        }
    }
}

//insertion sort
void insertion_sort(int *a, int n) {
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

//quick sort
void quick_sort(int *a, int l, int r) {
    if(l > r) return;
    int pivot = a[(l + r)/2];
    int i = l, j = r;
    while(i <= j) {
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(i < r) quick_sort(a, i, r);
    if(j > l) quick_sort(a, l, j);
}

int main() {
    int n; cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\nNhap x: ";
    int x; cin >> x;
    cout << binary_search(a, 0, n - 1, x);
}
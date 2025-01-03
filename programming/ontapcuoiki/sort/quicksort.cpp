#include <iostream>
using namespace std;

void quick_sort(int *a, int l, int r) {
    if(l <= r) {
        int mid = (l + r)/2;
        int pv = a[mid];
        int i = l; int j = r;
        while(i <= j) {
            while(i < pv) i++;
            while(j > pv) j--;
            if(i <= j) {
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }
        quick_sort(a, l, j);
        quick_sort(a, i, r);
    }
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
}
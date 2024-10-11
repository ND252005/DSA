#include <iostream>
using namespace std;

void merge(int *&a, int l, int m, int r) {
    int *b = new int[m - l + 1];
    int *c = new int[r - m];
    for(int i = 0; i <= m - l; i++) {
            b[i] = a[l + i];
    }
    for(int i = 0; i < r - m; i++) {
            c[i] = a[m + i + 1];
    }
    int count = l; int i = 0; int j = 0;
    while (i < m - l + 1 && j < r - m) {
        if (b[i] <= c[j]) {
            a[count++] = b[i++];
        } else {
            a[count++] = c[j++];
        }
    }

    while(i < m - l + 1) {
        a[count++] = b[i++];
    }
    while(j < r - m) {
        a[count++] = c[j++];
    }
    delete[] b;
    delete[] c;
}

void merge_sort(int *&a, int l, int r) {
    if(l >= r)
        return;
    merge_sort(a, l,(l + r)/2);
    merge_sort(a, (l + r)/2 + 1, r);
    merge(a, l, (l + r)/2, r);

}

void input_array(int *&a, int n) {
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void output_array(int *a, int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << ' '; 
    }
}

int main() {
    int n; cin >> n;
    int *a = new int[n];
    input_array(a, n);
    merge_sort(a, 0, n - 1);
    output_array(a, n);
    return 0;

}
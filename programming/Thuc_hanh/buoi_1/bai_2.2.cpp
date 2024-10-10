#include <iostream>
using namespace std;

void input_arr(int *&a, int n){
    a = new int [n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void output_arr(int *a, int n){
    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}
void quick_sort_increase(int *&a, int low, int high){
    if(low < high){
        int pivot = a[(low + high)/2];
        int i = low;
        int j = high;
        while(i <= j){
            while(a[i] < pivot) i++;
            while(a[j] > pivot) j--;
            if(i <= j){
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }
        if(low < j) quick_sort_increase(a, low, j);
        if(i < high) quick_sort_increase(a, i, high);
    }
}
void quick_sort_decrease(int *&a, int low, int high){
    if(low < high){
        int pivot = a[(low + high)/2];
        int i = low;
        int j = high;
        while(i <= j){
            while(a[i] > pivot) i++;
            while(a[j] < pivot) j--;
            if(i <= j){
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }
        if(low < j) quick_sort_decrease(a, low, j);
        if(i < high) quick_sort_decrease(a, i, high);
    }
}

void sort(int *&a, int n){
    int *b, *c;
    b = new int [n];
    c = new int [n];
    int j = 0;
    int k = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            b[j++] = a[i];
        } else {
            c[k++] = a[i];
        }
    }
    quick_sort_increase(b, 0, j - 1);
    quick_sort_decrease(c, 0, k - 1);
    j = 0;
    k = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            a[i] = b[j++];
        } else {
            a[i] = c[k++];
        }
    }
}


int main(){
    int n; cin >> n;
    int *a;
    input_arr(a,n);
    sort(a, n);
    output_arr(a, n);

}
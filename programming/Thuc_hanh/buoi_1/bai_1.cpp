#include <iostream>
using namespace std;

void input_arr(int *&a, int n){
    a = new int [n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void output_arr(int *a, int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
}
void quick_sort(int *&a, int low, int high){
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
        if(low < j) quick_sort(a, low, j);
        if(i < high) quick_sort(a, i, high);
    }
}

void sort(int *&a, int n){
    int *b;
    b = new int [n];
    int j = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            b[j] = a[i];
            j++;
        }
    }
    quick_sort(b, 0, j-1);
    j = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            a[i] = b[j];
            j++;
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
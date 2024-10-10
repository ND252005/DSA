#include <iostream>
using namespace std;
void print(int *a, int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}
void bubbleSort(int *arr, int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                print(arr, n);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}
int main(){
    int *a, n; cin >>  n;
    a = new int [n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    bubbleSort(a, n);
}
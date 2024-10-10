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
    cout << endl;
}

int *sort(int *a, int *b, int n1, int n2){
    int *c; c = new int [n1 + n2];
    int k = 0, i = 0, j = 0;
    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            c[k++] = a[i++];
        }else{
            c[k++] = b[j++];
        }
    }
    while(i < n1){
        c[k++] = a[i++];
    }
    while(j < n2){
        c[k++] = b[j++];
    }
    return c;
}

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int n1; cin >> n1;
        int n2;cin >> n2;
        int *a, *b;
        input_arr(a,n1);
        input_arr(b,n2);
        int *c = sort(a, b, n1, n2);
        output_arr(c, n2 + n1);
        delete [] a;
        delete [] b;
        delete [] c;
    }


}
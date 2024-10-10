#include <iostream>
using namespace std;

void Merge(int *a, int na, int *b, int nb){
    int nc = 0, *c;
    c = new int [na + nb];
    int i = 0; int j = 0;
    while(i < na && j < nb) {
        if(a[i] < b[j]) {
            c[nc++] = a[i];
            i++;
        }else{
            c[nc++] = b[j];
            j++;
        }
    }
    while(i < na){
        c[nc++] = a[i];
        i++;
    }
    while(j < nb){
        c[nc++] = b[j];
        j++;
    }
    for(int i = 0; i < na + nb; i++){
        cout << c[i] << ' ';
    }
    cout << endl;   
    delete[] c;
}

int main() {
    int t; cin >> t;
    for(int k = 0; k < t; k++){
        int *a, n; cin >> n;
        int *b, m; cin >> m;
        a = new int [n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        b = new int [m];
        for(int i = 0; i < m; i++){
            cin >> b[i];
        }
        Merge(a, n, b, m);
        delete[] a;
        delete[] b;
    }
     
}
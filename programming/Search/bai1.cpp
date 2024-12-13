#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        bool check = false;
        int x; cin >> x;
        for(int j = 0; j < n; j++) {
            if(x == arr[j]) {
                cout << j << endl;
                check = true;
                break;
            } 
        }
        if(check == false) cout << -1 << endl;
    }
    delete [] arr;
    return 0;
} 
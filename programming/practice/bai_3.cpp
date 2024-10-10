#include <iostream>
using namespace std;

int max_quantity = 1e9+1;
int max_queries = 1e5 + 1;

int main() {
    int n; cin >> n;
    bool *duong = new bool[max_quantity];
    bool *am = new bool[max_quantity];
    bool *check = new bool[max_queries];

    duong[max_quantity] = { };
    am[max_quantity] = { };
    int m; cin >> m;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if(tmp >= 0) duong[tmp] = !duong[tmp];
        if(tmp < 0) am[tmp] = !am[-tmp];
    }
    for(int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        if(tmp >= 0) { 
            if(duong[tmp]) check[i] = true;
            else check[i] = false;
        }
        else if(tmp < 0){ 
            if(am[tmp]) check[i] = true;
            else check[i] = false;
        }
    }
    for(int i = 0; i < m; i++) {
        if(check[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    delete[] am;
    delete[] duong;  // Don't forget to free memory
    return 0;
}

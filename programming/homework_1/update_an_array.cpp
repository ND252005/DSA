#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int x; cin >> x;
    vector <int> a;
    while(x != -2) {
        if(x != -1)
            a.push_back(x);
        else if(x == -1 and !a.empty()) {
            int max = *max_element(a.begin(), a.end());
            a.erase(remove(a.begin(), a.end(), max), a.end());    
        }

        cin >> x;
    }

    if(x == -2) {
        if(!a.empty()){
            cout << a.size() << endl;
            sort(a.begin(), a.end());
            for(int i = a.size() - 1; i >= 0; i--)
                cout << a[i] << endl;
        }
    }
}

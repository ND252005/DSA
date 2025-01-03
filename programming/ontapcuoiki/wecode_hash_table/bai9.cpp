#include <map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    map <string, vector<string>> login;
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        login[s].push_back(t);
    }
    for(int i = 0; i < q; i++) {
        string str; cin >> str;
        if(login[str].empty()) {
            cout << "Chua Dang Ky!" << endl;
        } else {
            for(int j = 0; j < login[str].size(); j++) {
                cout << login[str][j] << " ";
            }
            cout << endl;
        }
    }
}
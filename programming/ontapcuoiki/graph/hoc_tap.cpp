#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int v, e, n;
    cin >> v >> e >> n;
    map<string, set<int>> graph;
    map<string, int> convert;
    map<int, string> reverse;
    for(int i = 0; i < v; i++) {
        string x; cin >> x;
        convert[x] = i;
        reverse[i] = x;
    }
    for(int i = 0; i < e; i++) {
        string x, y; cin >> x >> y;
        graph[x].insert(convert[y]);
    }   
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        if(k == 1) {
            string x, y; cin >> x >> y;
            if(graph[x].find(convert[y]) != graph[x].end()) {
                cout << "TRUE" << endl;
            } else cout << "FALSE" << endl;       
        }
        if(k == 2) {
            string x; cin >> x;
            bool check = false;
            for(int i = 0; i < v; i++) {
                if(graph[x].find(i) != graph[x].end()) {
                    cout << reverse[i] << " ";
                    check = true;
                }
                
            }
            if(check == false) cout << "NONE";
            cout << endl;
        }
    }
}
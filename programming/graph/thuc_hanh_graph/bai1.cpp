#include <iostream>
#include <vector>
using namespace std;

vector <int> adj[1001];
int main() {
    int m, n; cin >> m >> n;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int dem = 0;
    for(int i = 0; i < m; i++) {
        if(adj[i].empty()) dem++;
    }
    cout << dem;
}

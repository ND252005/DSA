#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool visited[1001];

void bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int x : adj[v]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(visited, false, sizeof(visited)); 
    int dem = 0;

    for (int i = 0; i < m; i++) {
        if (!visited[i]) {
            bfs(i);
            dem++;
        }
    }

    // for (int i = 0; i < m; i++) {
    //     if (adj[i].empty()) {
    //         dem--;
    //     }
    // }

    cout << dem;
    return 0;
}

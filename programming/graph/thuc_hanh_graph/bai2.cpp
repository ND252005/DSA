#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

void bfs(int v, int n, unordered_map<string, int>& index, vector<vector<int>>& arr, string s, string u, vector<string>& dinh) {
    vector<bool> visited(v, false); 
    queue<int> chua;               
    vector<int> parent(v, -1);  
    bool found = false;             
    int vertices_explored = 0;      
    int path_length = 0;            

    // Khởi tạo BFS từ đỉnh s
    chua.push(index[s]);
    visited[index[s]] = true;

    while (!chua.empty()) {
        int z = chua.front();
        chua.pop();
        vertices_explored++;

        if (z == index[u]) {
            found = true;
            break; 
        }

        
        for (int i = 0; i < v; i++) {
            if (arr[z][i] && !visited[i]) {
                chua.push(i);
                visited[i] = true;
                parent[i] = z; 
            }
        }
    }

    if (found) {
        int in2 = index[u];
        int in1 = index[s];
        vector<int> path;

       
        for (int cur = in2; cur != in1; cur = parent[cur]) {
            path.push_back(cur);
        }
        path.push_back(in1);
        reverse(path.begin(), path.end());

     
        for (int i = 1; i < path.size(); ++i) {
            path_length += arr[path[i - 1]][path[i]];
        }

        
        for (auto ii : path) {
            cout << dinh[ii] << " ";
        }
        cout << endl;

   
        cout << vertices_explored << " " << path_length << endl;
    } else {
       
        cout << "-unreachable-" << endl;
        cout << vertices_explored << " 0" << endl; 
    }
}

int main() {
    int v, n;
    cin >> v >> n;
    vector<string> dinh(v);
    unordered_map<string, int> index;

  
    for (int i = 0; i < v; i++) {
        cin >> dinh[i];
        index[dinh[i]] = i; 
    }

  
    vector<vector<int>> arr(v, vector<int>(v, 0));
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> arr[i][j];
        }
    }

    
    for (int i = 0; i < n; i++) {
        string s, u;
        cin >> s >> u;
        bfs(v, n, index, arr, s, u, dinh); 
    }

    return 0;
}
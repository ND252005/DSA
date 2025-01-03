#include <bits/stdc++.h>
using namespace std;

void bfs(int v, map<string, int> index, vector<vector<int>> &arr, string s, string u, vector<string> &dinh) {
    vector <bool>visited(v, false); //gán mảng visited là false 
    queue <int> open; //tạo hàng đợi chứa các đỉnh chuẩn bị xét
    vector <int> parent(v, -1); //tạo mảng parent lưu cha của các đỉnh được xét
    bool found = false; // Cờ check đã tìm được đường đi hay chưa 
    int ver_explored = 0; //tổng số đỉnh được duyệt 
    int path_length = 0; //tổng trọng số đường đi 
    
    //khởi tạo bfs
    open.push(index[s]);
    visited[index[s]] = true;
    while(!open.empty()) {
        int z = open.front();
        open.pop();
        ver_explored++;

        //nếu tìm thấy đỉnh u thì break
        if(z == index[u]) {
            found = true; 
            break;
        }

        for(int i = 0; i < v; i++) {
            if(arr[z][i] && !visited[i]) {
                open.push(i);
                visited[i] = true;
                parent[i] = z;
            }
        }

    }
    if(found) {
        vector<int> path;
        for(int current = index[u]; current != index[s]; current = parent[current]) {
            path.push_back(current);
        }
        path.push_back(index[s]);
        reverse(path.begin(), path.end());

        for(int i = 1; i < path.size(); i++) {
            path_length += arr[path[i - 1]][path[i]];
        }
        for(auto x : path) {
            cout << dinh[x] << " ";
        }
        cout << endl;
        cout << ver_explored << " " << path_length << endl;

    } else {
        //Trường hợp không tìm thấy đường đi
        cout << "-unreachable-" << endl;
        cout << ver_explored << " 0" << endl; 
    }
    

}




int main() {
    int v, n;
    cin >> v >> n;
    vector <string> dinh (v);
    map<string, int> index;
    
    //nhập đỉnh, ánh xạ đỉnh sang số 
    for(int i = 0; i < v; i++) {
        cin >> dinh[i];
        index[dinh[i]] = i; 
    }
    
    //Nhập ma trận kề
    vector<vector<int>>arr(v, vector<int>(v, 0));
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        string s, u;
        cin >> s >> u;
        bfs(v, index, arr, s, u, dinh); 
    }
    return 0;

}
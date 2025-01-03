// #include <iostream>
// #include <vector>
// #include <map>
// #include <stack>
#include <bits/stdc++.h>

using namespace std;

struct Graph
{
    // ------------------ Khởi tạo ----------------------
    // Danh sách đỉnh
    vector<string> danhSachDinh;

    // Ma trận kề
    vector<vector<int>> G;

    // Ánh xạ giữa danh sách đỉnh và ma trận kề
    map<string, int> ver_index;


    // ------------------- Hàm --------------------------

    // Nhập & xuất danh sách đỉnh
    void nhapDanhSachDinh(const int&);
    void xuatDanhSachDinh();

    // Nhập & xuất ma trận kề
    void nhapMaTranKe(const int&);
    void xuatMaTranKe();

    // DFS
    void DFS(string, string);

    // Solve
    void process(int);
};

void Graph :: nhapDanhSachDinh(const int& v) {
    danhSachDinh = vector<string>(v);
    for(int i = 0; i < v; i++) {
        cin >> danhSachDinh[i];
        //thực hiện ánh xạ 
        ver_index[danhSachDinh[i]] = i;
    }
}

void Graph :: xuatDanhSachDinh() {
    for(auto x : danhSachDinh) {
        cout << x << ' ';
    }
}

void Graph :: nhapMaTranKe(const int& v) {
    G = vector<vector<int>> (v, vector<int>(v, 0));
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            cin >> G[i][j];
        }
    }
}
void Graph :: xuatMaTranKe() {
    for(int i = 0; i < G.size(); i++) {
        for(int j = 0; j < G[0].size(); j++) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}
void Graph :: DFS(string s, string u) {
    stack<int> open; //ngăn xếp chứa các phần tử chờ để thăm
    vector<bool> visited(G[0].size(), false); //mảng thăm phần tử 
    vector<int> parent(G[0].size(), -1); //mảng lưu phần tử cha
    bool found = false; //cờ check đã gặp phần tử hay chưa
    int count = 0; //biến đếm đã thăm được bao nhiêu phần tử 
    int weight = 0; // tổng trọng số của đường đi từ s->u

    open.push(ver_index[s]); 
    visited[ver_index[s]] = true;
    while(!open.empty()) {
        int z = open.top();
        open.pop();
        visited[z] = true;
        count++;
        if(z == ver_index[u]){
            found = true;
            break;
        }
        for(int i = 0; i < G[z].size(); i++) {
            if(G[z][i] > 0 && !visited[i]) {
                open.push(i);
                parent[i] = z;
            }
        }
    }
    if(!found) {
        cout << "-unreachable-" << endl;
        cout << 1 << " " << weight << endl;
    } else {
        vector <int> path; 
        for(int cur = ver_index[u]; cur != ver_index[s]; cur = parent[cur]) {
            path.push_back(cur);
        }
        path.push_back(ver_index[s]);
        reverse(path.begin(), path.end());

        for(int i = 1; i < path.size(); i++) {
            weight += G[path[i - 1]][path[i]];
        }
        for(auto x : path) {
            cout << danhSachDinh[x] << " ";
        }
        cout << endl;
        cout << count << " " << weight << endl;
    }
}
void Graph :: process(int n) {
    for(int i = 0; i < n; i++) {
        string s, u;
        cin >> s >> u;
        DFS(s, u);
    }
}
int main()
{
    Graph G;

    // Nhập đỉnh & số thao tác tìm kiếm
    int v, n;
    cin >> v >> n;

    // Nhập danh sách đỉnh
    G.nhapDanhSachDinh(v);
    
    // Xuất danh sách đỉnh
    // G.xuatDanhSachDinh();

    // Nhập ma trận kề
    G.nhapMaTranKe(v);

    // Xuất ma trận kề
    // G.xuatMaTranKe();

    // Giải quyết bài toán
    G.process(n);

    return 0;
}
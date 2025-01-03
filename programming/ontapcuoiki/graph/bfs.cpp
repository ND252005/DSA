#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

void bfs(int v, int n, unordered_map<string, int>& index, vector<vector<int>>& arr, string s, string u, vector<string>& dinh) {
    vector<bool> visited(v, false);  // Đánh dấu các đỉnh đã duyệt
    queue<int> chua;                // Hàng đợi để duyệt BFS
    vector<int> parent(v, -1);      // Mảng lưu cha của mỗi đỉnh
    bool found = false;             // Cờ kiểm tra tìm thấy đỉnh đích hay chưa
    int vertices_explored = 0;      // Số đỉnh đã duyệt
    int path_length = 0;            // Tổng trọng số đường đi (nếu có)

    // Khởi tạo BFS từ đỉnh s
    chua.push(index[s]);
    visited[index[s]] = true;

    while (!chua.empty()) {
        int z = chua.front();
        chua.pop();
        vertices_explored++; // Đếm số đỉnh đã duyệt

        if (z == index[u]) {
            found = true;
            break; // Nếu tìm thấy đỉnh u, thoát khỏi vòng lặp
        }

        // Duyệt các đỉnh kề của z
        for (int i = 0; i < v; i++) {
            if (arr[z][i] && !visited[i]) { // Nếu có đường đi và chưa duyệt
                chua.push(i);
                visited[i] = true;
                parent[i] = z; // Lưu cha của đỉnh i
            }
        }
    }

    if (found) {
        int in2 = index[u];
        int in1 = index[s];
        vector<int> path;

        // Truy vết đường đi từ u về s
        for (int cur = in2; cur != in1; cur = parent[cur]) {
            path.push_back(cur);
        }
        path.push_back(in1);
        reverse(path.begin(), path.end());

        // Tính tổng trọng số đường đi
        for (int i = 1; i < path.size(); ++i) {
            path_length += arr[path[i - 1]][path[i]];
        }

        // In ra đường đi
        for (auto ii : path) {
            cout << dinh[ii] << " ";
        }
        cout << endl;

        // In số đỉnh đã duyệt và tổng trọng số đường đi
        cout << vertices_explored << " " << path_length << endl;
    } else {
        // Nếu không tìm thấy đường đi
        cout << "-unreachable-" << endl;
        cout << vertices_explored << " 0" << endl; // In số đỉnh đã duyệt và độ dài xem như zero
    }
}

int main() {
    int v, n;
    cin >> v >> n;
    vector<string> dinh(v);
    unordered_map<string, int> index;

    // Nhập danh sách tên các đỉnh
    for (int i = 0; i < v; i++) {
        cin >> dinh[i];
        index[dinh[i]] = i; // Lưu chỉ số của từng đỉnh
    }

    // Nhập ma trận kề
    vector<vector<int>> arr(v, vector<int>(v, 0));
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> arr[i][j];
        }
    }

    // Xử lý từng truy vấn
    for (int i = 0; i < n; i++) {
        string s, u;
        cin >> s >> u;
        bfs(v, n, index, arr, s, u, dinh); // Gọi hàm BFS để tìm đường đi
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

struct Graph
{
    // ------------------ Khởi tạo ----------------------
    // Danh sách đỉnh
    vector<string> danhSachDinh;

    // Ma trận kề
    vector<vector<int>> G;

    // Ánh xạ giữa danh sách đỉnh và ma trận kề
    map<string, int> verticeIndex;


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

void Graph::nhapDanhSachDinh(const int& v)
{
    danhSachDinh = vector<string>(v);
    for(int i = 0; i < v; ++i)
    {
        cin >> danhSachDinh[i];

        // Thực hiện ánh xạ tại bước này
        verticeIndex[danhSachDinh[i]] = i;
    }
}

void Graph::xuatDanhSachDinh()
{
    for(auto x : danhSachDinh)
        cout << x << " ";
}

void Graph::nhapMaTranKe(const int& v)
{
    G = vector<vector<int>>(v, vector<int>(v, 0));

    for(int i = 0; i < v; ++i)
        for(int j = 0; j < v; ++j)
            cin >> G[i][j];
}

void Graph::xuatMaTranKe()
{
    for(int i = 0; i < G.size(); ++i)
    {
        for(int j = 0; j < G[0].size(); ++j)
            cout << G[i][j] << " ";
        cout << endl;
    }
}

void Graph::DFS(string s, string e)
{
    // ------------------- Khởi tạo --------------------

    stack<string> open; // Stack chứa các đỉnh sẽ thăm
    open.push(s); 

    vector<bool> visited(danhSachDinh.size(), false); // Mảng visted đánh dấu các đỉnh đã thăm
    // Lưu ý: Trong một vài tài liệu có sử dụng mảng close 
    // --> mảng visited và mảng close có thể xem như là có ý nghĩa như nhau

    map<string, string> parent; // Quan hệ cha-con truy vết đường đi
    bool found = false;

    int count = 1;
    int weight = 0;

    // --------------------- Bắt Đầu ---------------------
    
    // B1: Vòng lặp DFS
    while(!open.empty())
    {
        // 1.1: Lấy đỉnh p từ đầu open (stack)
        string p = open.top();
        open.pop();

        // 1.2: Kiểm tra nếu p là đỉnh đích cần tìm
        // Ví dụ: Tìm đường đi từ A -> E, thì kiếm tra liệu p có phải là đỉnh E (đỉnh đích) không?
        if(p == e)
        {
            found = true;
            break;
        }

        // 1.3: Nếu không phải là đỉnh đích, đánh dấu là đã thăm
        if(!visited[verticeIndex[p]])
        {
            visited[verticeIndex[p]] = true; // Sử dụng ánh xạ (verticeIndex) đã khai báo ở trên
            count++;
        }

        // 1.4: Duyệt các đỉnh kề của p
        int pIndex = verticeIndex[p];
        for(int i = 0; i < G[pIndex].size(); ++i)
        {
            // Nếu tồn tại cạnh giữa đỉnh p và đỉnh thứ i + đỉnh thứ i đó chưa được thăm
            // ==> Thêm đỉnh i đó và stack (open)
            if(G[pIndex][i] > 0 && !visited[i])  // Tồn tại cạnh & đỉnh chưa được thăm (visted)
            {
                open.push(danhSachDinh[i]); // Thêm đỉnh vào open (stack)
                parent[danhSachDinh[i]] = p; // Thiết lập đỉnh thứ i có cha là đỉnh p
            }
        }
    } 

    // B2: Xuất kết quả (đường đi)
    if(!found)
    {
        cout << "-unreachable-\n";
        cout << count - 1 << " " << weight << endl;
    }
    else 
    {
        // Truy vết đường đi từ đỉnh đích (end) đến đỉnh đầu (start)
        vector<string> path; // lưu đường đi
        for(string cur = e; cur != s; cur = parent[cur])
        {
            path.push_back(cur);
            weight += G[verticeIndex[parent[cur]]][verticeIndex[cur]]; // Tính độ dài đường đi
        }
        path.push_back(s);

        // In đường đi từ start đến end
        for(auto it = path.rbegin(); it != path.rend(); ++it)
            cout << *it << " ";
        cout << endl;
        cout << count << " " << weight << endl;
    }
}

void Graph::process(int n)
{
    while(n--)
    {
        string s, u;
        cin >> s >> u;

        // Tìm đường đi bằng thuật toán DFS
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
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

struct compare 
{
    bool operator()(pair<int, int> a, pair<int, int> b) 
    {
        if (a.first == b.first)
            return a.second < b.second; // Æ¯u tiÃªn Äá»nh nháº­p sau (chá» sá» lá»n hÆ¡n)
        return a.first > b.first; // Æ¯u tiÃªn khoáº£ng cÃ¡ch nhá» hÆ¡n
    }
};

struct Graph
{
    // Danh sÃ¡ch Äá»nh
    vector<string> tapDinh;

    // Ãnh xáº¡ giá»¯a Äá»nh vÃ  index
    map<string, int> verticeIndex;

    // Ma tran ke
    vector<vector<int>> G;

    // Nhap & xuat tap dinh
    void nhapTapDinh(int);
    void xuatTapDinh();

    // Nhap & xuat ma tran ke
    void nhapMaTranKe(int);
    void xuatMaTranKe();

    // Dijkstra
    void Dijkstra(int, int, int);

    // Xu Ly
    void solve(int);
};

void Graph::nhapTapDinh(int v)
{
    tapDinh = vector<string>(v);
    for(int i = 0; i < v; ++i)
    {
        cin >> tapDinh[i];

        verticeIndex[tapDinh[i]] = i;
    }
}

void Graph::xuatTapDinh()
{
    for(auto x : tapDinh)
        cout << x << " ";
}

void Graph::nhapMaTranKe(int v)
{
    G = vector<vector<int>>(v, vector<int>(v, 0));
    for(int i = 0; i < G.size(); ++i)
        for(int j = 0; j < G[0].size(); ++j)
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

void Graph::Dijkstra(int start, int end, int v) // Truyá»n index cá»§a Äá»nh start vÃ  Äá»nh end
{
    // set<pair<string, int>> open;
    // VD: open = {(A, 20), (B, 35)};

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> open;

    vector<bool> close(v, false);
    map<int, int> parent;
    vector<int> d(v, INT_MAX);

    // BÆ°á»c 1: Khá»i táº¡o
    open.push({0, start}); // Open := {s};
                           // Close :={};
    d[start] = 0; // d(s):=0;        
    bool found = false;

    int count = 1;
    
    // BÆ°á»c 2: While (Open â  {})
    while(!open.empty())
    {
        // 2.1 Chá»n p thuá»c Open cÃ³  d(p) nhá» nháº¥t (xÃ³a p ra khá»i Open).
        int p = open.top().second;
        open.pop();

        // -------------- Note --------------
        // Náº¿u 2 pháº§n tá»­ cÃ³ d báº±ng nhau thÃ¬ chá»n Äá»©a nao???

        // 2.2 Náº¿u p lÃ  Äá»nh ÄÃ­ch thÃ¬ xuáº¥t ÄÆ°á»ng Äi, káº¿t thÃºc thuáº­t toÃ¡n
        if(p == end)
        {
            found = true;
            break;
        }
// 2.3 Náº¿u p ÄÃ£ duyá»t rá»i thÃ¬ bá» qua, khÃ´ng xem xÃ©t láº¡i, trá» láº¡i Äáº§u vÃ²ng láº·p
        if(close[p] == true)
            continue;

        // 2.4 ÄÃ¡nh dáº¥u p ÄÃ£ duyá»t qua rá»i (tá»©c thÃªm p vÃ o Close)
        close[p] = true;
        count++;

        // 2.5 Má» cÃ¡c Äá»nh káº¿ tiáº¿p q sau p (ká» vá»i p)
        for(int q = 0; q < v; ++q)
        {
            if(G[p][q] > 0 && close[q] == false)
            // Vá»i má»i Äá»nh q ká» vá»i p, náº¿u q khÃ´ng thuá»c Close:
            // 2.5.1 Náº¿u q ÄÃ£ cÃ³ trong Open
            {
                int newDist = d[p] + G[p][q]; // Khoáº£ng cÃ¡ch má»i cho q
                if (newDist < d[q]) // giÃ¡ trá» má»i tá»t hÆ¡n giÃ¡ trá» cÅ©
                {         
                    d[q] = newDist;          // Cáº­p nháº­t láº¡i giÃ¡ trá» má»i
                    parent[q] = p;           // Cáº­p nháº­t cha cá»§a q
                    open.push({newDist, q}); // ThÃªm q vÃ o Open
                }
                // ------------ NHáº¬N XÃT:
                // - Náº¿u q chÆ°a cÃ³ trong open thÃ¬
                //   d[q] lÃ  giÃ¡ trá» khá»i táº¡o ban Äáº§u, tá»©c lÃ  VÃ CÃNG
                //   vÃ  hiá»n nhiÃªn d_new < vÃ´ cÃ¹ng, Äiá»u kiá»n cá»§a if sáº½ thá»a
                //   náº¿u q ÄÃ£ cÃ³ trong open rá»i thÃ¬ 
                //   bÆ°á»c bá» thÃªm q vÃ o láº¡i open cÅ©ng khÃ´ng sao, queue cÃ³ sawpx xáº¿p theo 
                //   Äá» Æ°u tiÃªn nÃªn q tá»t nháº¥t sáº½ ÄÆ°á»£c chá»n 
            }
        }
    }
    
    // BÆ°á»c 3: Káº¿t luáº­n âKhÃ´ng tÃ¬m tháº¥y ÄÆ°á»ng Äiâ

    if (!found) 
    {
        cout << "-unreachable-\n";
        cout << count - 1 << " " << 0 << endl;
    } else 
    {
        // cout << "Duong di ngan nhat tu " << tapDinh[start] << " den " << tapDinh[end] << ": " << d[end] << endl;

        // Truy váº¿t ÄÆ°á»ng Äi tá»« ÄÃ­ch ngÆ°á»£c vá» Äáº§u
        stack<int> path;
        for (int cur = end; cur != start; cur = parent[cur])
            path.push(cur);
        path.push(start);

        // Xuáº¥t ÄÆ°á»ng Äi
        while (!path.empty()) 
        {
            cout << tapDinh[path.top()] << " ";
            path.pop();
        }
        cout << endl;
        cout << count << " " << d[end] << endl;
    }
}


void Graph::solve(int n)
{
    while(n--)
    {
        string s, e;
        cin >> s >> e;

        Dijkstra(verticeIndex[s], verticeIndex[e], tapDinh.size());
    }
}

int main()
{
    Graph G;

    int v, n;
    cin >> v >> n;

    G.nhapTapDinh(v);
    // G.xuatTapDinh();
G.nhapMaTranKe(v);
    // G.xuatMaTranKe();

    G.solve(n);

    return 0;
}
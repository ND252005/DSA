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
            return a.second < b.second;
        return a.first > b.first;
    }
};

struct Graph
{
    vector<string> vertices;
    map<string, int> index_map;
    vector<vector<int>> adjacency_matrix;

    void input_vertices(int);
    void output_vertices();
    void input_graph(int);
    void output_graph();
    void dijstra(int, int, int);
    void process(int);
};

void Graph::input_vertices(int v)
{
    vertices = vector<string>(v);
    for(int i = 0; i < v; ++i)
    {
        cin >> vertices[i];
        index_map[vertices[i]] = i;
    }
}

void Graph::output_vertices()
{
    for(auto x : vertices)
        cout << x << " ";
}

void Graph::input_graph(int v)
{
    adjacency_matrix = vector<vector<int>>(v, vector<int>(v, 0));
    for(int i = 0; i < adjacency_matrix.size(); ++i)
        for(int j = 0; j < adjacency_matrix[0].size(); ++j)
            cin >> adjacency_matrix[i][j];
}

void Graph::output_graph()
{
    for(int i = 0; i < adjacency_matrix.size(); ++i)
    {
        for(int j = 0; j < adjacency_matrix[0].size(); ++j)
            cout << adjacency_matrix[i][j] << " ";
        cout << endl;
    }
}

void Graph::dijstra(int start, int end, int v)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> open;
    vector<bool> close(v, false);
    map<int, int> parent;
    vector<int> d(v, INT_MAX);
    open.push({0, start});
    d[start] = 0;
    bool found = false;
    int count = 1;

    while(!open.empty())
    {
        int p = open.top().second;
        open.pop();

        if(p == end)
        {
            found = true;
            break;
        }

        if(close[p] == true)
            continue;

        close[p] = true;
        count++;

        for(int q = 0; q < v; ++q)
        {
            if(adjacency_matrix[p][q] > 0 && close[q] == false)
            {
                int newDist = d[p] + adjacency_matrix[p][q];
                if (newDist < d[q])
                {         
                    d[q] = newDist;
                    parent[q] = p;
                    open.push({newDist, q});
                }
            }
        }
    }

    if (!found) 
    {
        cout << "-unreachable-\n";
        cout << count - 1 << " " << 0 << endl;
    } 
    else 
    {
        stack<int> path;
        for (int cur = end; cur != start; cur = parent[cur])
            path.push(cur);
        path.push(start);

        while (!path.empty()) 
        {
            cout << vertices[path.top()] << " ";
            path.pop();
        }
        cout << endl;
        cout << count << " " << d[end] << endl;
    }
}

void Graph::process(int n)
{
    while(n--)
    {
        string s, e;
        cin >> s >> e;
        dijstra(index_map[s], index_map[e], vertices.size());
    }
}

int main()
{
    Graph G;

    int v, n;
    cin >> v >> n;

    G.input_vertices(v);
    G.input_graph(v);
    G.process(n);

    return 0;
}
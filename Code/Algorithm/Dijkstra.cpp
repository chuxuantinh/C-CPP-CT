/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-CPP/GNU-Compiler/In-Out/"
// #define pathio "E:/Code/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio"input.txt","r",stdin
#define lfo pathio"output.txt","w",stdout

using namespace std;

class Dijkstra
{
private:
    int nodes, edges;
    vector<vector<pair<int, int>>> Graph;
    vector<int> distMin;
    queue<int> Queue;
    vector<bool> inQueue;
    int oo = ((1LL << 31) - 1);

public:
    Dijkstra(int N, int M) : nodes(N),
                             edges(M),
                             Graph(2 * N + 1),
                             distMin(2 * N + 1),
                             inQueue(N + 1) {}

    void addEdge(int x, int y, int cost)
    {
        Graph[x].push_back(make_pair(y, cost));
    }

    void solve()
    {
        for (int i = 2; i <= nodes; i++)
            distMin[i] = oo;
        distMin[1] = 0;
        Queue.push(1);
        inQueue[1] = true;
        while (!Queue.empty())
        {
            int node = Queue.front();
            Queue.pop();
            inQueue[node] = false;
            for (auto G : Graph[node])
            {
                if (distMin[G.first] > distMin[node] + G.second)
                {
                    distMin[G.first] = distMin[node] + G.second;
                    if (!inQueue[G.first])
                    {
                        Queue.push(G.first);
                        inQueue[G.first] = true;
                    }
                }
            }
        }
    }

    void getDistMin()
    {
        freopen(lfo);
        for (int i = 2; i <= nodes; i++)
        {
            printf("%d ", distMin[i] < oo ? distMin[i] : 0);
        }
        fclose(stdout);
    }

    void printGraph()
    {
        cout << endl;
        for (int i = 1; i <= nodes; i++)
        {
            cout << i << " -> ";
            for (auto v : Graph[i])
            {
                cout << v.first;
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    freopen(lfi);
    freopen(lfo);
    // ios_base :: sync_with_stdio (0);
    cin.tie(0);

    int n,
        m,
        x,
        y,
        cost;
    freopen(lfi);
    cin >> n >> m;
    // cout << n << m;
    // /*

    Dijkstra dij(n, m);
    while (m--)
    {
        cin >> x >> y >> cost;
        dij.addEdge(x, y, cost);
    }

    dij.solve();
    dij.getDistMin();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
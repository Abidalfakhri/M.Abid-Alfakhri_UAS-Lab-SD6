#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge
{
    int u, v;
    int jarak;
    int biaya;
};

int main()
{
    int V, E, start;
    cin >> V >> E >> start;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].jarak >> edges[i].biaya;
    }

    vector<int> dist(V, INT_MAX);
    vector<int> cost(V, INT_MAX);
    vector<int> parent(V, -1);

    dist[start] = 0;
    cost[start] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (auto &e : edges)
        {
            if (dist[e.u] != INT_MAX)
            {
                int newDist = dist[e.u] + e.jarak;
                int newCost = cost[e.u] + e.biaya;

                if (newDist < dist[e.v])
                {
                    dist[e.v] = newDist;
                    cost[e.v] = newCost;
                    parent[e.v] = e.u;
                }
                else if (newDist == dist[e.v] && newCost < cost[e.v])
                {
                    cost[e.v] = newCost;
                    parent[e.v] = e.u;
                }
            }
        }
    }

    cout << "Jarak (meter): ";
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "inf ";
        else
            cout << dist[i] << " ";
    }
    cout << "\n";

    cout << "Biaya (rupiah): ";
    for (int i = 0; i < V; i++)
    {
        if (cost[i] == INT_MAX)
            cout << "inf ";
        else
            cout << cost[i] << " ";
    }
    cout << endl;
    cout << "Jalur ke kos " << V - 1 << ": ";

    vector<int> path;
    int cur = V - 1;

    if (dist[cur] == INT_MAX)
    {
        cout << "Tidak ada jalur\n";
        return 0;
    }

    while (cur != -1)
    {
        path.push_back(cur);
        cur = parent[cur];
    }

    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i];
        if (i != 0)
            cout << " -> ";
    }

    cout << "\n";
}
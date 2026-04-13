#include "bellmanford.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(vector<Edge> &edges, int V, int src, int dest)
{
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);

    dist[src] = 0;

    for(int i = 0; i < V - 1; i++)
    {
        for(auto e : edges)
        {
            if(dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v])
            {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
            }
        }
    }

    vector<int> path;

    for(int v = dest; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    return path;
}
#include "dijkstra.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>> &graph, int src, int dest)
{
    int V = graph.size();

    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for(auto edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if(dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    vector<int> path;

    for(int v = dest; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    return path;
}
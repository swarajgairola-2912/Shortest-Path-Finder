#include "floydwarshall.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> floydWarshall(vector<vector<int>> dist, int src, int dest)
{
    int V = dist.size();
    const int INF = 1e9;

    vector<vector<int>> next(V, vector<int>(V, -1));

    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            if(dist[i][j] != INF && i != j)
                next[i][j] = j;

    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }

    vector<int> path;

    if(next[src][dest] == -1)
        return path;

    int u = src;
    path.push_back(u);

    while(u != dest)
    {
        u = next[u][dest];
        path.push_back(u);
    }

    return path;
}
#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include <vector>
using namespace std;

struct Edge
{
    int u,v,w;
};

vector<int> bellmanFord(vector<Edge> &edges, int V, int src, int dest);

#endif
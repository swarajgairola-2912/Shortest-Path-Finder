#include "include/crow/app.h"
#include "dijkstra.h"
#include "bellmanford.h"
#include "floydwarshall.h"

#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    crow::SimpleApp app;

    // ================= DIJKSTRA =================
    CROW_ROUTE(app, "/dijkstra").methods("POST"_method)
    ([](const crow::request& req){

        auto body = crow::json::load(req.body);

        int nodes = body["nodes"].i();
        int source = body["source"].i();
        int destination = body["destination"].i();

        vector<vector<pair<int,int>>> graph(nodes);

        for (auto edge : body["edges"])
        {
            int u = edge["u"].i();
            int v = edge["v"].i();
            int w = edge["w"].i();

            graph[u].push_back({v, w});
        }

        auto path = dijkstra(graph, source, destination);

        crow::json::wvalue result;

        // Add path
        for(int i = 0; i < path.size(); i++)
            result["path"][i] = path[i];

        // Calculate distance
        int totalDistance = 0;
        for(int i = 0; i < path.size() - 1; i++) {
            int u = path[i];
            int v = path[i+1];

            for(auto p : graph[u]) {
                if(p.first == v) {
                    totalDistance += p.second;
                    break;
                }
            }
        }

        result["distance"] = totalDistance;

        return crow::response(result);
    });


    // ================= BELLMAN FORD =================
    CROW_ROUTE(app, "/bellmanford").methods("POST"_method)
    ([](const crow::request& req){

        auto body = crow::json::load(req.body);

        int nodes = body["nodes"].i();
        int source = body["source"].i();
        int destination = body["destination"].i();

        vector<Edge> edges;

        for (auto edge : body["edges"])
        {
            Edge e;
            e.u = edge["u"].i();
            e.v = edge["v"].i();
            e.w = edge["w"].i();
            edges.push_back(e);
        }

        auto path = bellmanFord(edges, nodes, source, destination);

        crow::json::wvalue result;

        // Add path
        for(int i = 0; i < path.size(); i++)
            result["path"][i] = path[i];

        // Calculate distance
        int totalDistance = 0;
        for(int i = 0; i < path.size() - 1; i++) {
            int u = path[i];
            int v = path[i+1];

            for(auto e : edges) {
                if(e.u == u && e.v == v) {
                    totalDistance += e.w;
                    break;
                }
            }
        }

        result["distance"] = totalDistance;

        return crow::response(result);
    });


    // ================= FLOYD WARSHALL =================
    CROW_ROUTE(app, "/floydwarshall").methods("POST"_method)
    ([](const crow::request& req){

        auto body = crow::json::load(req.body);

        int nodes = body["nodes"].i();
        int source = body["source"].i();
        int destination = body["destination"].i();

        vector<vector<int>> matrix(nodes, vector<int>(nodes, 100000));

        for (auto edge : body["edges"])
        {
            int u = edge["u"].i();
            int v = edge["v"].i();
            int w = edge["w"].i();

            matrix[u][v] = w;
        }

        auto path = floydWarshall(matrix, source, destination);

        crow::json::wvalue result;

        // Add path
        for(int i = 0; i < path.size(); i++)
            result["path"][i] = path[i];

        // Calculate distance
        int totalDistance = 0;
        for(int i = 0; i < path.size() - 1; i++) {
            int u = path[i];
            int v = path[i+1];

            totalDistance += matrix[u][v];
        }

        result["distance"] = totalDistance;

        return crow::response(result);
    });


    // ================= RUN SERVER =================
    app.port(18080).multithreaded().run();
}
#include <iostream>
#include <vector>
#include <queue>
#include <pair>

using namespace std;

struct Edge {
    int vertex;
    int weight;
};

using Graph = vector< vector<Edge> >;
using DistVertex = pair<int, int>;

// Returns the weight of the shortest path from vertex s to y in a directed graph G.
int shortest_path_weight(const Graph& G, int s, int y) {
    int n = G.size();
    vector<int> dist(n, -1);

    dist[s] = 0;
    priority_queue<int> q;
    q.push(DistVertex{dist[s], s});

    DistVertex u;
    while (not q.empty()) {
        u = q.top();    q.pop();
        for (const Edge& v : G[u]) {
            if (dist[v.vertex] > dist[u] + v.weight) {
                dist[v.vertex] = dist[u] + v.weight;

            }
        }
    }
}

int main() {
    int n, m;
    int u, v, c;
    int x, y;
    while (cin >> n >> m) {
        Graph G(n);
        for (int i=0; i<m; ++i) {
            cin >> u >> v >> c;
            G[u].push_back(Edge{v, c});
        }
        cin >> x >> y;
        cout << shortest_path_weight(x, y, G) << endl;
    }
}

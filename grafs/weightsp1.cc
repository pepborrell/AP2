#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct Edge {
    int end_vertex;
    int weight;
};

using Graph = vector< vector<Edge> >;
using DistVertex = pair<int, int>;

// Returns the weight of the shortest path from vertex s to y in a directed graph G.
int shortest_path_weight(const Graph& G, int s, int y) {
    int n = G.size();
    vector<int> dist(n, -1);

    dist[s] = 0;
    priority_queue<DistVertex, vector<DistVertex>, greater<DistVertex>> pq;
    pq.push(DistVertex{dist[s], s});

    DistVertex u;
    while (not pq.empty()) {
        u = pq.top();    pq.pop();
        for (const Edge& v : G[u.second]) {
            if (dist[v.end_vertex] == -1 or dist[v.end_vertex] > dist[u.second] + v.weight) {
                dist[v.end_vertex] = dist[u.second] + v.weight;
                pq.push(DistVertex{dist[v.end_vertex], v.end_vertex});
            }
        }
    }
    return dist[y];
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
        int outp = shortest_path_weight(G, x, y);
        if (outp == -1) {
            cout << "no path from " << x << " to " << y << endl;
        } else {
            cout << outp << endl;
        }
    }
}

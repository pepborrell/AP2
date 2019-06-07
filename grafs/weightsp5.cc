#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using Edge = pair<int, int>; //First the end vertex, then the weight.
using Graph = vector< vector<Edge> >;

int shortest_path_weight(const Graph& G, int s, int y) {
    int n = G.size();
    vector<int> dist(n, -1);

    dist[s] = 0;
    for (int i=0; i<n-1; ++i) {
        for (int j=0; j<n; ++j) {
            for (const Edge& e : G[j]) {
                if (dist[e.first] == -1 or dist[e.first] > dist[j] + e.second) {
                    dist[e.first] = dist[j] + e.second;
                }
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

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
using Edge = pair<int, int>; // weight and end vertex
using Graph = vector< vector<Edge> >;

int weight_mst(const Graph& G) {
	int totWeight = 0, n = G.size(), nMST = 0;
	vector<bool> visited(n, false);
	// Picking the initial vertex 0
	visited[0] = true; ++nMST;

	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	for (const Edge& v : G[0]) {
		pq.push(v);
	}
	while (nMST < n) {
		Edge e = pq.top(); pq.pop();
		if (not visited[e.second]) {
			visited[e.second] = true;
			++nMST;
			totWeight += e.first;
			for (const Edge& v : G[e.second]) {
				if (not visited[v.second]) pq.push(v);
			}
		}
	}
	return totWeight;
}

int main() {
	int n, m;
	int u, v, w;
	while (cin >> n >> m) {
		Graph G(n);
		for (int i=0; i<m; ++i) {
			cin >> u >> v >> w;
			--u; --v;
			G[u].push_back(Edge{w, v});
			G[v].push_back(Edge{w, u});
		}
		cout << weight_mst(G) << endl;
	}
}
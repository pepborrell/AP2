#include <iostream>
#include <vector>

using namespace std;
using Graph = vector< vector<int> >;

bool path (const Graph& G, int x, int y, vector<bool>& visited) {
	if (x == y) return true;
	if (visited[x]) return false;
	visited[x] = true;
	for (int u : G[x])
		if (path(G, u, y, visited)) return true;
	return false;
}

int main () {
	int n, m;
	cin >> n >> m;
	Graph G(n, vector<int>());
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
	}
	
	int x, y;
	cin >> x >> y;
	vector<bool> visited(n, false);
	cout << (path(G, x, y, visited) ? "yes" : "no") << endl;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Graph = vector< vector<int> >;

bool is_2_col_cc(const Graph& G, vector<int>& col, int src) {
	col[src] = 1;
	queue<int> q;
	q.push(src);
	while (not q.empty()) {
		int u = q.front(); q.pop();
		for (int v : G[u]) {
			if (col[v] == 0) {
				col[v] = -col[u];
				q.push(v);
			}
			else if (col[u] == col[v]) return false;
		}
	}
	return true;
}

bool is_2_col(const Graph& G) {
	int n = G.size();
	vector<int> col(n, 0); // The vertices have colour 0 if not visited, 1 white or -1 black.
	for (int i=0; i<n; ++i) {
		if (col[i] == 0) {
			if (not is_2_col_cc(G, col, i)) return false;
		}
	}
	return true;
}

int main() {
	int n, m;
	int x, y;
	while (cin >> n >> m) {
		Graph G(n);
		for (int i=0; i<m; ++i) {
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		cout << (is_2_col(G)? "yes" : "no") << endl;
	}
}
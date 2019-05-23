#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using Graph = vector< vector<int> >;

vector<int> count_predecessors(const Graph& G) {
	int n = G.size();
	vector<int> v(n);
	for (const vector<int>& vg: G) {
		for (int x : vg) {
			++v[x];
		}
	}
	return v;	
}

// Si un vèrtex no te predecessors, pot posar-se a l'ordre
// Llavors el posem a la cua i treiem el primer per ordre lexicografic
vector<int> topological_sort(const Graph& G) {
	vector<int> pred = count_predecessors(G);
	int n = G.size();
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i=0; i<n; ++i) {
		if (pred[i] == 0) q.push(i);
	}
	vector<int> sorted;
	while (not q.empty()) {
		int x = q.top(); q.pop();
		sorted.push_back(x);
		for (int y : G[x]) {
			--pred[y];
			if (pred[y] == 0) q.push(y);
		}
	}
	return sorted;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		Graph G(n);
		int x, y;
		// input
		for (int i=0; i<m; ++i) {
			cin >> x >> y;
			G[x].push_back(y);
		}
		
		vector<int> out = topological_sort(G);
		
		// output
		bool first = true;
		for (int o : out) {
			if (not first) cout << ' ';
			else first = false;
			cout << o;
		}
		cout << endl;
	}
}

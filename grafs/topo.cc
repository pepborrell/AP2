#include <iostream>
#include <vector>
using namespace std;

using Graph = vector< vector<int> >;

void topological_sort(const Graph& G) {
	
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		Graph G(n);
		int x, y;
		for (int i=0; i<m; ++i) {
			cin >> x >> y;
			G[x].push_back(y);
		}
		topological_sort(G);
	}
}

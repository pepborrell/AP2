#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct Rock {
	double x, y, r;
};

using Graph = vector< vector<int> >;

double dist (double x1, double y1, double x2, double y2) {
	double x = x1 - x2, y = y1 - y2;
	return sqrt(x*x + y*y);
}

bool can_leap (const vector<Rock>& v, int a, int b, int d) {
	return (dist(v[a].x, v[a].y, v[b].x, v[b].y) - v[a].r - v[b].r <= d);
}

Graph create_graph (const vector<Rock>& vr, int d) {
	int n = vr.size();
	Graph G(n);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (i != j and can_leap(vr, i, j, d)) {
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}
	return G;
}

int n_leaps (const Graph& G, int y) {
	int n = G.size();
	vector<int> level(n, -1);
	level[0] = 0;
	queue<int> q;
	q.push(0);
	while (not q.empty()) {
		int u = q.front();	q.pop();
		for (int v : G[u]) {
			if (level[v] == -1) {
				level[v] = level[u] + 1;
				q.push(v);
				if (v == y) return level[y];
			}
		}
	}
	return level[y];
}

int main () {
	int n;
	double d;
	while (cin >> n >> d) {
		vector<Rock> vr(n);
		for (Rock& s : vr) {
			cin >> s.x >> s.y >> s.r;
		}
		Graph G = create_graph(vr, d);
		int res =  n_leaps(G, n-1);
		if (res == -1) cout << "Xof!" << endl;
		else cout << res << endl;
	}
}

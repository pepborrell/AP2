#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cassert>

using namespace std;
using Graph = map<string, vector<string> >;

bool path (Graph& G, string x, string y, map<string, bool>& visited) {
	if (x == y) return true;
	if (visited[x]) return false;
	visited[x] = true;
	for (string u : G[x])
		if (path(G, u, y, visited)) return true;
	return false;
}

int main () {
	int n;
	cin >> n;
	Graph G;
	map<string, bool> visited;
	string s;
	for (int i=0; i<n; ++i) {
		cin >> s;
		G[s];
		visited[s] = false;
	}
	
	int m;
	cin >> m;
	string u, v;
	for (int i=0; i<m; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
	}
	
	string x, y;
	cin >> x >> y;
	cout << (path(G, x, y, visited) ? "yes" : "no") << endl;
}

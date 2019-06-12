#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;
using Graph = vector< set<int> >;

Graph build_graph(int n, int t) {
    Graph G(n);
    for (int i=0; i<t; ++i) {
        int k;
        cin >> k;
        vector<int> authors(k);
        for (int& x : authors) cin >> x;
        for (const int& x : authors) {
            for (const int& y : authors) {
                if (x != y) G[x].insert(y);
            }
        }
    }
    return G;
}

vector<int> explore(const Graph& G) {
    int n = G.size();
    vector<int> level(n, -1);
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    level[0] = 0;
    while (not q.empty()) {
        int x = q.front(); q.pop();
        for (int a : G[x]) {
            if (level[a] == -1) {
                level[a] = level[x] + 1;
                q.push(a);
            }
        }
    }
    return level;
}

int main() {
    int n, t;
    while (cin >> n >> t) {
        Graph G = build_graph(n, t);
        vector<int> levels = explore(G);
        for (int i=0; i<n; ++i) {
            cout << i << " : ";
            (levels[i] == -1 ? cout << "no" : cout << levels[i]);
            cout << endl;
        }
        cout << "----------" << endl;
    }
}

#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using chMatrix = vector< vector<char> >;
using bMatrix = vector< vector<bool> >;
using Point = pair<int, int>;

void prepare_map(const chMatrix& mmap, bMatrix& visited) {
    int n = mmap.size(), m = mmap[0].size();
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (mmap[i][j] == 'M') {
                if (i > 0) visited[i-1][j] = true;
                if (i < n-1) visited[i+1][j] = true;
                if (j > 0) visited[i][j-1] = true;
                if (j < m-1) visited[i][j+1] = true;
            }
        }
    }
}

bool explore_m(const chMatrix& mmap, bMatrix& visited, const Point& p) {
    int n = mmap.size(), m = mmap[0].size();
    int i = p.first, j = p.second;
    if (mmap[i][j] == 'F') return true;
    if (visited[i][j]) return false;
    visited[i][j] = true;
    bool found = false;
    if (i > 0) found = found or explore_m(mmap, visited, Point{i-1, j});
    if (i < n-1) found = found or explore_m(mmap, visited, Point{i+1, j});
    if (j > 0) found = found or explore_m(mmap, visited, Point{i, j-1});
    if (j < m-1) found = found or explore_m(mmap, visited, Point{i, j+1});
    return found;
}

bool explore(const chMatrix& mmap, const Point& start) {
    int n = mmap.size(), m = mmap[0].size();
    bMatrix visited (n, vector<bool> (m, false));
    prepare_map(mmap, visited);
    return explore_m(mmap, visited, start);
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        chMatrix layout(n, vector<char> (m));
        Point start;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                cin >> layout[i][j];
                if (layout[i][j] == 'I') start = Point{i, j};
            }
        }
        cout << (explore(layout, start) ? "SI" : "NO") << endl;
    }
}

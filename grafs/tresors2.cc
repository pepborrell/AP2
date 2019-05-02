#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using Map = vector< vector<char> >;
using Matrix_l = vector< vector<int> >;
using Point = pair<int, int>;

void visit(Matrix_l& level, queue<Point>& q, int f, int c, int of, int oc) {
    if (level[f][c] == -1) {
        level[f][c] = level[of][oc] + 1;
        q.push(Point(f,c));
    }
}

int is_path(const Map& treasure_map, int f, int c) {
    int n = treasure_map.size(), m = treasure_map[0].size();
	Matrix_l level(n, vector<int>(m, -1));
	level[f][c] = 0;
	queue<Point> q;
	q.push(Point(f, c));
	while (not q.empty()) {
		Point u = q.front();	q.pop();
        int f = u.first, c = u.second;
        if (treasure_map[f][c] == 't') return level[f][c];
        if (f < n-1 and treasure_map[f+1][c] != 'X') visit(level, q, f+1, c, f, c);
        if (f > 0 and treasure_map[f-1][c] != 'X') visit(level, q, f-1, c, f, c);
        if (c < m-1 and treasure_map[f][c+1] != 'X') visit(level, q, f, c+1, f, c);
        if (c > 0 and treasure_map[f][c-1] != 'X') visit(level, q, f, c-1, f, c);
	}
	return -1;
}

int main(){
    int n, m;
    cin >> n >> m;

    Map treasure_map(n, vector<char>(m));
    for (vector<char>& vc : treasure_map) {
        for (char& c : vc) {
            cin >> c;
        }
    }

    int f, c;
    cin >> f >> c;
    f -= 1; c -= 1;

    int res = is_path(treasure_map, f, c);
    if (res == -1) cout << "no es pot arribar a cap tresor" << endl;
    else cout << "distancia minima: " << res << endl;
}

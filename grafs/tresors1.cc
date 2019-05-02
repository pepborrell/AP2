#include <iostream>
#include <vector>

using namespace std;

using Map = vector< vector<char> >;
using Matrix_b = vector< vector<bool> >;

bool is_path(const Map& treasure_map, int f, int c, Matrix_b& visited) {
    int n = treasure_map.size(), m = treasure_map[0].size();
    if (treasure_map[f][c] == 't') return true;
    if (visited[f][c]) return false;
    visited[f][c] = true;
    if (f < n-1 and treasure_map[f+1][c] != 'X' and is_path(treasure_map, f+1, c, visited)) return true;
    if (f > 0 and treasure_map[f-1][c] != 'X' and is_path(treasure_map, f-1, c, visited)) return true;
    if (c < m-1 and treasure_map[f][c+1] != 'X' and is_path(treasure_map, f, c+1, visited)) return true;
    if (c > 0 and treasure_map[f][c-1] != 'X' and is_path(treasure_map, f, c-1, visited)) return true;
    return false;
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

    Matrix_b visited(n, vector<bool>(m, false));
    cout << (is_path(treasure_map, f, c, visited) ? "yes" : "no") << endl;
}

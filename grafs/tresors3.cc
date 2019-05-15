#include <iostream>

#include <vector>

using namespace std;

using Map = vector < vector < char > > ;
using Matrix_b = vector < vector < bool > > ;

// Retorna el nombre de tresors que hi ha en el camí que explora amb un DFS.
// x i y posició des de la que comença a investigar.
int n_treasures(const Map & t_map, Matrix_b & visited, int x, int y) {
    int count = 0;
    int n = t_map.size(), m = t_map[0].size();
    if (visited[x][y]) return 0;
    visited[x][y] = true;
    if (t_map[x][y] == 't') ++count;
    
    if (x < n - 1 and t_map[x + 1][y] != 'X') count += n_treasures(t_map, visited, x + 1, y);
    if (x > 0 and t_map[x - 1][y] != 'X') count += n_treasures(t_map, visited, x - 1, y);
    if (y < m - 1 and t_map[x][y + 1] != 'X') count += n_treasures(t_map, visited, x, y + 1);
    if (y > 0 and t_map[x][y - 1] != 'X') count += n_treasures(t_map, visited, x, y - 1);
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    Map treasure_map(n, vector < char > (m));
    for (vector < char > & vc: treasure_map) {
        for (char & c: vc) {
            cin >> c;
        }
    }

    int f, c;
    cin >> f >> c;
    f -= 1;
    c -= 1;

    Matrix_b visited(n, vector < bool > (m, false));
    cout << n_treasures(treasure_map, visited, f, c) << endl;
}

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool check(int v, int n) {
    vector<bool> obtained_values(v-1, false);
    string s;
    getline(cin, s);
    istringstream iss(s);
    for (int i=0; i<n; ++i) {
        int x;
        iss >> x;
        if (x < v) {
            if (obtained_values[v-x]) return true;
            else obtained_values[x] = true;
        }
    }
    return false;
}

int main() {
    string s;
    getline(cin, s);
    istringstream iss(s);
    int v, n;
    iss >> v >> n;
    while (v != 0 or n != 0) {
        cout << (check(v, n) ? "married" : "single") << endl;
        getline(cin, s);
        istringstream iss(s);
        iss >> v >> n;
    }
}

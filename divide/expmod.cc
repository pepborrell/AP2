#include <iostream>

using namespace std;

long calculate(int n, int k, int m) {
    if (k == 0) return 1;
    if (k == 1) return n;
    long r = calculate(n, k/2, m);
    if (k%2) return (r*r*n)%m;
    return (r*r)%m;
}

int main() {
    int n, k, m;
    while (cin >> n >> k >> m) {
        cout << calculate(n%m, k, m) << endl;
    }
}

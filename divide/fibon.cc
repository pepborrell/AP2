#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > Matrix;

void print_fib(const Matrix& M) {
    cout << M[1][0] << endl;
}

Matrix multiply_m(const Matrix& M1, const Matrix& M2, int m) {
    Matrix R(2, vector<int>(2));
    R[0][0] = M1[0][0]*M2[0][0] + M1[0][1]*M2[1][0];
    R[0][1] = M1[0][0]*M2[0][1] + M1[0][1]*M2[1][1];
    R[1][0] = M1[1][0]*M2[0][0] + M1[1][1]*M2[1][0];
    R[1][1] = M1[1][0]*M2[0][1] + M1[1][1]*M2[1][1];
    for (vector<int>& v : R) {
        for (int& x : v) x %= m;
    }
    return R;
}

Matrix calculate(const Matrix& M, int n, int m) {
    if (n == 0) return Matrix({vector<int> {1, 0}, vector<int> {0, 1}});
    if (n == 1) return M;
    Matrix R = calculate(M, n/2, m);
    if (n%2) return multiply_m(multiply_m(R, R, m), M, m);
    return multiply_m(R, R, m);
}

int main() {
    Matrix M({{1, 1},{1, 0}});
    int n, m;
    while (cin >> n >> m) {
        print_fib(calculate(M, n, m));
    }
}

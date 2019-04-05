#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > Matrix;

void print_m(const Matrix& M) {
    for (const vector<int>& v : M) {
        bool first = true;
        for (int x : v) {
            if (first) first = false;
            else cout << " ";
            cout << x;
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

Matrix multiply_m(const Matrix& M1, const Matrix& M2) {
    Matrix R(2, vector<int>(2));
    R[0][0] = M1[0][0]*M2[0][0] + M1[0][1]*M2[1][0];
    R[0][1] = M1[0][0]*M2[0][1] + M1[0][1]*M2[1][1];
    R[1][0] = M1[1][0]*M2[0][0] + M1[1][1]*M2[1][0];
    R[1][1] = M1[1][0]*M2[0][1] + M1[1][1]*M2[1][1];
    return R;
}

Matrix modulify(const Matrix& N, int m) {
    Matrix M = N;
    for (vector<int>& v : M) {
        for (int& x : v) {
            x = x%m;
        }
    }
    return M;
}

Matrix calculate(const Matrix& M, int n, int m) {
    if (n == 0) return Matrix({vector<int> {1, 0}, vector<int> {0, 1}});
    if (n == 1) return M;
    Matrix R = calculate(M, n/2, m);
    R = modulify(R, m);
    if (n%2) return modulify(multiply_m(multiply_m(R, R), M), m);
    return modulify(multiply_m(R, R), m);
}

int main() {
    Matrix M(2, vector<int>(2));
    int n, m;
    while (cin >> M[0][0] >> M[0][1] >> M[1][0] >> M[1][1] >> n >> m) {
        print_m(calculate(M, n, m));
    }
}

#include <iostream>
#include <vector>
using namespace std;

int inversions(vector<int>& v){
    
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int& x : v) cin >> x;
        cout << inversions(v) << endl;
    }
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct Rock {
	double x, y, r;
};
// using Graph = vector< vector<Rock> >;

int main () {
	int n;
	double d;
	cin >> n >> d;
	
	vector<Rock> vr(n);
	for (Rock& s : vr) {
		cin >> s.x >> s.y >> s.r;
	}
	
	// Graph G(n, vector<Rock>());
	queue<int> q;
}

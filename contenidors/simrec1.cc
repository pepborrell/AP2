#include <iostream>
using namespace std;

void escriu(int n) {
	if (n > 0) {
		cout << ' ' << n;
		escriu(n - 1);
		escriu(n - 1);
	}
}

int main() {
	int n;
	while (cin >> n) {
		escriu(n);
		cout << endl;
	}
}

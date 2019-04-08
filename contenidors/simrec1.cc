#include <iostream>
#include <stack>
using namespace std;

void escriu(int n) {
	stack<int> st;
	st.push(n);
	while (not st.empty()) {
		if (st.top() == 1) {
			cout << " " << 1;
			st.pop();
		} else {
			int k = st.top();
			st.pop();
			cout << " " << k;
			st.push(k-1);
			st.push(k-1);
		}
	}
}

int main() {
	int n;
	while (cin >> n) {
		escriu(n);
		cout << endl;
	}
}

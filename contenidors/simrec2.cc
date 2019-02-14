#include <iostream>
#include <stack>
using namespace std;

void sttost(stack<int>& result, stack<int>& source){
	while(not source.empty()){
		result.push(source.top());	source.pop();
	}
}

void escriu(int n) {
	if (n > 0) {
		stack<int> p1;
		for(int i=1; i<=n; ++i){
			stack<int> p2 = p1;
			p1.push(i);
			sttost(p1, p2);
		}
		while(not p1.empty()){
			cout << ' ' << p1.top();	p1.pop();
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

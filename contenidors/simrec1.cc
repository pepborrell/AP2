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
		for(int i=1; i<n; ++i){
			stack<int> p2;
			p2.push(i);
			sttost(p2, p1);
			stack<int> p3 = p2;
			sttost(p1, p2);
			sttost(p1, p3);
		}
		p1.push(n);
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

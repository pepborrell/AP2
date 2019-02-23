#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	string p;
	cin >> p;
	set<string> s;
	s.insert(p);
	auto it = s.begin();
	bool incr = false;
	while (p != "END") {
		if(p < *it) --it;
		cout << *it << endl;
		cin >> p;
		s.insert(p);
		if (incr) ++it;
		incr = not incr;
	}
}
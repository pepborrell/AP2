#include <iostream>
#include <map>

using namespace std;

void update(map<string, string>& m1, map<string, string>& m2, set<string>& s) {
	string a, b;
	cin >> a >> b;
	if (m1.find(a) != m1.end() or m2.find(a) != m2.end()) {
		
}

int main() {
	string action;
	map<string, string> m1, m2;
	while (cin >> action) {
		if (action == "liats") update(m1, m2, singles);
		else print_info(m1, m2, singles);
	}
}

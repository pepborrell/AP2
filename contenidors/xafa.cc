#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

void update(map<string, string>& m, set<string>& s) {
	string a, b;
	cin >> a >> b;
	s.insert(m[a]);
	s.insert(m[b]);
	s.erase(a);
	s.erase(b);
	m.erase(m[a]);
	m.erase(m[b]);
	m[a] = b;
	m[b] = a;
}

map<string, string> sort_map(const map<string, string>& mi) {
	map<string, string> mo = mi;
	for (const auto& i : mo) {
		if (i.first < i.second) {
			mo.erase(i.second);
		} else mo.erase(i.first);
	}
	return mo;
}

void print_info(const map<string, string>& m, const set<string>& s) {
	cout << "PARELLES:" << endl;
	map<string, string> msorted = sort_map(m);
	for (auto& i : msorted) cout << i.first << ' ' << i.second << endl;

	cout << "SOLS:" << endl;
	for (auto& i : s) {
		if (i != "") cout << i << endl;
	}
	cout << "----------" << endl;
}

int main() {
	string action;
	map<string, string> m;
	set<string> singles;
	while (cin >> action) {
		if (action == "liats") update(m, singles);
		else print_info(m, singles);
	}
}

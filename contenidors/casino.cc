#include <iostream>
#include <string>
#include <map>

using namespace std;

void event(const string& name, map<string, int>& m) {
	string s;
	cin >> s;
	if (s == "enters") {
		if (m.find(name) == m.end()) {
			m[name] = 0;
		} else {
			cout << name << " is already in the casino" << endl;
		}
	} else if (s == "leaves") {
		if (m.find(name) != m.end()) {
			cout << name << " has won " << m[name] << endl;
			m.erase(name);
		} else {
			cout << name << " is not in the casino" << endl;
		}
	} else if (s == "wins") {
		int n; cin >> n;
		if (m.find(name) != m.end()) {
			m[name] += n;
		} else {
			cout << name << " is not in the casino" << endl;
		}
	}
}

void print_end(const map<string, int>& m) {
	for (auto x : m) {
		cout << x.first << " is winning " << x.second << endl;
	}
}

int main() {
	map<string, int> m;
	string p;
	while (cin >> p) {
		event(p, m);
	}
	cout << "----------" << endl;
	print_end(m);
}
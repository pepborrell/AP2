#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<string> settovec(const set<string>& s){
	int n = s.size();
	vector<string> v(n);
	auto it = s.begin();
	for (int i=0; i<n; ++i){
		v[i] = *it;
		++it;
	}
	return v;
}

bool comp(const string& a, const string& b){
	int n = a.size(), m = b.size();
	if (n != m) return n < m;
	else {
		return a < b;
	}
}

void move_string(const string& p, set<string>& s, set<string>& was_s) {
	if (s.find(p) == s.end()) {
		s.insert(p);
		was_s.erase(p);
	} else {
		s.erase(p);
		was_s.insert(p);
	}
}

void print_output(int i, const set<string>& s, const set<string>& was_s) {
	cout << "GAME #" << i << endl;
	cout << "HAS:" << endl;
	for (const string& x : s) {
		cout << x << endl;
	}
	cout << endl << "HAD:" << endl;
	vector<string> v = settovec(was_s);
	sort(v.begin(), v.end(), comp);
	for (const string& x : v) {
		cout << x << endl;
	}
}

int main() {
	string p;
	int i = 1;
	while (p != "QUIT") {
		set<string> s;
		set<string> was_s;
		cin >> p;
		while (p != "END" and p != "QUIT") {
			move_string(p, s, was_s);
			cin >> p;
		}
		print_output(i, s, was_s);
		++i;
		if(p != "QUIT") cout << endl;
	}
}
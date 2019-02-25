#include <iostream>
#include <map>

using namespace std;

void question(const map<string, int>& m, const string& p) {
	if (m.empty()) cout << "indefinite " << (p == "maximum?" ? "maximum" : "minimum") << endl;
	else {
		if (p == "maximum?") {
			auto it = m.end();
			--it;
			cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
		} else {
			auto it = m.begin();
			cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
		}
	}
}

void operation(map<string, int>& m, const string& p) {
	string w;
	cin >> w;
	if (p == "store") ++m[w];
	else {
		--m[w];
		if (m[w] <= 0) m.erase(w);
	}
}

int main() {
	string p;
	map<string, int> m;
	while (cin >> p) {
		if (p.back() == '?') question(m, p);
		else operation(m, p);
	}
}
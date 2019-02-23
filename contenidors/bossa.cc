#include <iostream>
#include <set>

using namespace std;

void modify_set(const string& p, set<long long>& s) {
	long long n;
	cin >> n;
	if (p == "deixar") s.insert(n);
	else s.erase(n);
}

long long maximum_value_bag(int n, const set<long long>& s) {
	long long sum = 0;
	if(not s.empty()){
		auto it = s.end(); --it;
		n = min(n, int(s.size()));
		for (int i=0; i<n; ++i) {
			sum += *it;
			--it;
		}
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	string p;
	set<long long> s;
	while(cin >> p){
		modify_set(p, s);
		cout << maximum_value_bag(n, s) << endl;
	}
}
#include <iostream>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

int main(){
	cout.setf(ios::fixed);
	cout.precision(4);
	string l;
	priority_queue<int, vector<int>, greater<int>> pq;
	int suma = 0, maxim = -1000, minim = 1000;
	while(getline(cin, l)){
		istringstream iss(l);
		string s;
		iss >> s;
		if(s == "delete" and not pq.empty()){
			suma -= pq.top();	pq.pop();
		}else if(s == "number"){
			int x;
			iss >> x;
			suma += x;
			pq.push(x);
			if(x > maxim) maxim = x;
		}
		int n = pq.size();
		if(n){
			minim = pq.top();
			cout << "minimum: " << minim << ", maximum: " << maxim << ", average: " << double(suma)/double(n) << endl;
		}else cout << "no elements" << endl;
	}
}
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

using Bitcount = pair<double, int>;

void initialise_queue(int n, priority_queue<int, vector<int>, greater<int>>& pq){
	for(int i=0; i<n; ++i){
		Bitcount x;
		cin >> x.first;	x.second = 0;
		pq.push(x);
	}
}

double calculate(int n){
	priority_queue<int, vector<int>, greater<int>> pq;
	initialise_queue(n, pq);
	while(int(pq.size()) > 1){
		int a, b; //Numbers with the lowest frequency.
		
	}
}

int main(){
	int n;
	cin >> n;
	cout << "nombre esperat de bits per lletra: " << calcular(n) << endl;
}
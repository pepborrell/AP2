#include <iostream>
#include <queue>
#include <utility>
using namespace std;

double reduir (priority_queue<double, vector<double>, greater<double>>& pq) {
	double sum = pq.top();
	pq.pop();
	sum += pq.top();
	pq.pop();
	pq.push(sum);
	return sum;
}

double calcular (int n) {
	priority_queue<double, vector<double>, greater<double>> freq;
	double x;
	for (int i=0; i<n; ++i) {
		cin >> x;
		freq.push(x/100);
	}
	double total = 0;
	while (freq.size() > 1) {
		total += reduir(freq);
	}
	return total;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(4);
	int n;
	cin >> n;
	cout << "nombre esperat de bits per lletra: " << calcular(n) << endl;
}

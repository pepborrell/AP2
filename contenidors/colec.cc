#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

void operacions(char opr, priority_queue<int>& pq){
	if(pq.empty() and (opr == 'A' or opr == 'R' or opr == 'I' or opr == 'D')){
		cout << "error!" << endl;
	}else{
		if(opr == 'S'){
			int x;
			cin >> x;
			pq.push(x);
		}if(opr == 'A') cout << pq.top() << endl;
		if(opr == 'R') pq.pop();
		if(opr == 'I'){
			int x;
			cin >> x;
			int topcp = pq.top() + x; pq.pop();
			pq.push(topcp);
		}if(opr == 'D'){
			int x;
			cin >> x;
			int topcp = pq.top() - x; pq.pop();
			pq.push(topcp);
		}
	}
}

int main(){
	priority_queue<int> pq;
	char a;
	while(cin >> a){
		operacions(a, pq);
	}
}
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cassert>
using namespace std;

bool es_numero(string s){
	return (s[0] >= '0' and s[0] <= '9');
}

int calcula(const string& s){
	istringstream iss(s);
	string a;
	stack<int> st;
	while(iss >> a){
		if(es_numero(a)){
			st.push(stoi(a));
		}
		else{
			int x = st.top();	st.pop();
			int y = st.top();	st.pop();
				 if(a == "+") st.push(x+y);
			else if(a == "-") st.push(y-x);
			else if(a == "*") st.push(x*y);
			else assert(false);
		}
	}
	return st.top();
}

int main(){
	string line;
	while(getline(cin, line)){
		cout << calcula(line) << endl;
	}
}

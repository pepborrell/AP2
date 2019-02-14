#include <iostream>
#include <stack>
using namespace std;

bool comprova(const string& s){
	stack<int> st;
	for(char a : s){
		if(a == '(' or a == '[') st.push(a);
		else if(st.empty()
				or (a == ')' and st.top() == '[')
				or (a == ']' and st.top() == '(')){
			return false;
		}else st.pop();
	}
	return st.empty();
}

int main(){
	string s;
	while(cin >> s){
		cout << s << " es " << (comprova(s) ? "correcta" : "incorrecta") << endl;
	}
}

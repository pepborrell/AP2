#include <iostream>
using namespace std;

struct Node;

using Arbre = Node*;

struct Node {
	int x;
	Arbre fe;
	Arbre fd;
	
	~Node() {
		delete fe;
		delete fd;
	}
};

Arbre llegir_arbre() {
	int x;
	cin >> x;
	if (x == -1) return nullptr;
	
	Arbre fe = llegir_arbre();
	Arbre fd = llegir_arbre();
	return new Node{x, fe, fd};
}

void postordre(Arbre a) {
	if (a != nullptr) {
		postordre(a->fe);
		postordre(a->fd);
		cout << ' ' << a->x;
	}
}

void inordre(Arbre a) {
	if (a != nullptr) {
		inordre(a->fe);
		cout << ' ' << a->x;
		inordre(a->fd);
	}
}
	

int main()  {
	Arbre a = llegir_arbre();
	
	cout << "pos:";	postordre(a);	cout << endl;
	cout << "ino:";	inordre(a);	cout << endl;
	
	delete a;
}

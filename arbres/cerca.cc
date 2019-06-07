#include <iostream>
#include <queue>
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

bool cerca(Arbre a, int x) {
    if (not a) return false;
    if (x == a->x) return true;
    if (x < a->x) return cerca(a->fe, x);
    return cerca(a->fd, x);
}

int main() {
    int el; cin >> el; // No ens interessa.
    Arbre a = llegir_arbre();

    int x;
    while(cin >> x) {
        cout << x << " " << (cerca(a, x) ? 1 : 0) << endl;
    }
    delete a;
}

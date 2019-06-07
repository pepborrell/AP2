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

int profunditat_b(Arbre a, int i) {
    if (a) return max(profunditat_b(a->fe, i+1), profunditat_b(a->fd, i+1));
    return i;
}

int profunditat(Arbre a) {
    return profunditat_b(a, 0);
}

Arbre llegir_arbre() {
	int x;
	cin >> x;
	if (x == -1) return nullptr;

	Arbre fe = llegir_arbre();
	Arbre fd = llegir_arbre();
	return new Node{x, fe, fd};
}

int main() {
    int m;
    cin >> m;
    for (int i=0; i<m; ++i) {
        Arbre a = llegir_arbre();
        cout << profunditat(a) << endl;
        delete a;
    }
}

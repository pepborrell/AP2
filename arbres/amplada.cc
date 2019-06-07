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

int profunditat_b(Arbre a, int i) {
    if (a) return max(profunditat_b(a->fe, i+1), profunditat_b(a->fd, i+1));
    return i;
}

int profunditat(Arbre a) {
    return profunditat_b(a, 0);
}

void amplada_b(Arbre a, int l, vector<int>& width) {
    if (a) {
        ++width[l];
        ++l;
        amplada_b(a->fe, l, width);
        amplada_b(a->fd, l, width);
    }
}

int amplada(Arbre a) {
    vector<int> width(profunditat(a), 0);
    amplada_b(a, 0, width);
    int maxim = 0;
    for (int x : width) {
        if (x > maxim) maxim = x;
    }
    return maxim;
}

int main() {
    int m;
    cin >> m;
    for (int i=0; i<m; ++i) {
        Arbre a = llegir_arbre();
        cout << amplada(a) << endl;
    }
}

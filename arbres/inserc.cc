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

void preordre(Arbre a) {
    if (a == nullptr) return;
    cout << a->x << endl;
    preordre(a->fe);
    preordre(a->fd);
}

void afegeix(Arbre a, int x) {
    if (x == a->x) return;
    if (x < a->x) {
        if (a->fe) afegeix(a->fe, x);
        else a->fe = new Node{x, nullptr, nullptr};
    }
    else {
        if (a->fd) afegeix(a->fd, x);
        else a->fd = new Node{x, nullptr, nullptr};
    }
};

int main() {
    int x;
    cin >> x;
    Arbre a = new Node{x, nullptr, nullptr};
    while (cin >> x) afegeix(a, x);
    preordre(a);
    delete a;
}

#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

void operate(istringstream& iss, map<string, int>& balance) {
    char op;
    iss >> op;
    if (op == 'R') {
        string name; int number;
        iss >> name >> number;
        balance[name] += number;
    }
    if (op == 'G') {
        string name; int number;
        iss >> name >> number;
        balance[name] -= number;
    }
    if (op == 'P') {
        string name1, name2; int number;
        iss >> name1 >> number >> name2;
        balance[name1] -= number;
        balance[name2] += number;
    }
}

int intlength(int n) {
    int c = 10, i = 1;
    if (n < 0) {
        n = -n;
        ++i;
    }
    while (n >= c) {
        c *= 10;
        ++i;
    }
    return i;
}

void print_output(const map<string, int>& balance, int r) {
    vector<ostringstream> output(r);
    auto it = balance.begin();
    bool end = false;
    int count = 0;
    while (not end) {
        int max_line = 0;
        auto it2 = it;
        for (int i=0; i<r; ++i) {
            if (it2 != balance.end()) {
                int line_l = it2->first.size() + intlength(it2->second) + 1;
                if (line_l > max_line) max_line = line_l;
                ++it2;
            } else end = true;
        }
        for (int i=0; i<r; ++i) {
            if (it != balance.end()) {
                int n_spaces = max_line - it->first.size() - intlength(it->second);
                output[count] << it->first << string(" ", n_spaces) << it->second;
                ++it; ++count; count %= r;
            }
        }
    }
    for (int i=0; i<r; ++i) {
        cout << output[i].str() << endl;
    }

}

int main() {
    int r;
    while (cin >> r) {
        map<string, int> balance;
        string s;
        getline(cin, s);
        while(s != "END") {
            istringstream iss(s);
            operate(iss, balance);
            getline(cin, s);
        }
        print_output(balance, r);
        cout << "****************************************" << endl;
    }
}

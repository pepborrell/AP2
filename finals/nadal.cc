#include <iostream>
#include <queue>
#include <utility>
#include <map>

using namespace std;
// using Freq_Num = pair<int, int>; // Primer la freqüència i després el número.

struct Freq_Num {
    int freq;
    int num;

    bool operator<(const Freq_Num& rhs) const {
        if (freq != rhs.freq) return freq < rhs.freq;
        return num > rhs.num;
    }
};

void reset(map<int, int>& number, map<int, int>& ending, priority_queue<Freq_Num>& fnum, priority_queue<Freq_Num>& fend) {
    cout << endl;
    for (const auto& elem : number) {
        cout << elem.first << ' ' << elem.second << endl;
    }
    cout << "----------" << endl;
    map<int, int> newMap;
    number = ending = newMap;
    priority_queue<Freq_Num> newPq;
    fnum = fend = newPq;
}

void operate(int x, map<int, int>& number, map<int, int>& ending, priority_queue<Freq_Num>& fnum, priority_queue<Freq_Num>& fend) {
    if (x == -1) reset(number, ending, fnum, fend);
    else {
        ++number[x];
        fnum.push(Freq_Num{number[x], x});
        ++ending[x%100];
        fend.push(Freq_Num{ending[x%100], x%100});
        cout << fnum.top().num << ' ' << fnum.top().freq << ' ';
        if (fend.top().num < 10) cout << 0;
        cout << fend.top().num << ' ' << fend.top().freq << endl;
    }
}

int main() {
    int n;
    // Desa les vegades que ha sortit un nombre o final.
    map<int, int> number; map<int, int> ending;
    // Desa a cada iteració. Sempre treu la freq més gran.
    priority_queue<Freq_Num> fnum; priority_queue<Freq_Num> fend;
    while (cin >> n) {
        operate(n, number, ending, fnum, fend);
    }
}

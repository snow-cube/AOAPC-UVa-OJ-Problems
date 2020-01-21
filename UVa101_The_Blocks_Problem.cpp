#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int n;
vector<int> piles[25];

void FindBlock(int num, int &p, int &h) {
    for (p = 0; p < n; p++) {
        for (h = 0; h < piles[p].size(); h++) {
            if (num == piles[p][h]) return;
        }
    }
}

void ClearAbove(int p, int h) {
    for (int i = h + 1; i < piles[p].size(); i++)
        piles[piles[p][i]].push_back(piles[p][i]);
    piles[p].resize(h + 1);
}

void PileOver(int p, int h, int p_target) {
    for (int i = h; i < piles[p].size(); i++)
        piles[p_target].push_back(piles[p][i]);
    piles[p].resize(h);
}

int main() {
    int a, b;
    string s1, s2;
    cin >> n;
    for (int i = 0; i < n; i++) piles[i].push_back(i);

    while (true) {
        cin >> s1;
        if (s1 == "quit") break;
        cin >> a >> s2 >> b;
        int pa, ha, pb, hb;
        FindBlock(a, pa, ha);
        FindBlock(b, pb, hb);
    
        if (pa == pb) continue;
        if (s1 == "move") ClearAbove(pa, ha);
        if (s2 == "onto") ClearAbove(pb, hb);

        PileOver(pa, ha, pb);
    }

    for (int i = 0; i < n; i++) {
        cout << i << ":";
        for (int j = 0; j < piles[i].size(); j++)
            cout << " " << piles[i][j];
        cout << endl;
    }

    return 0;
}
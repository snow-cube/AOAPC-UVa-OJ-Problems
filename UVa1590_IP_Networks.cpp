#include <iostream>
#include <cstring>
using namespace std;

int network[32];
int mask[32];
int m;

void Add() {
    int l = 32;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 4; j++) {
            int num;
            cin >> num;
            cin.get();
            for (int b = 7; b >= 0; b--) {
                if (i && num % 2 != network[j*8+b]) {
                    if (j*8+b < l) l = j*8+b;
                } else network[j*8+b] = num % 2;
                num >>= 1;
            }
        }
    }

    for (int i = 0; i < l; i++) mask[i] = 1;
    for (int i = 31; i >= l; i--) network[i] = 0;
}

void Output(int binary[]) {
    for (int i = 0; i < 4; i++) {
        int n = 0;
        for (int b = 0; b < 8; b++) n = (n << 1) + binary[i*8+b];
        if (i) cout << ".";
        cout << n;
    }
    cout << endl;
}

int main() {
    while (cin >> m) {
        memset(network, 0, sizeof(network));
        memset(mask, 0, sizeof(mask));
        Add();
        Output(network);
        Output(mask);
    }

    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int marbles[10005];

int main() {
    int N, Q, kase = 0;
    while (cin >> N >> Q && N) {
        for (int i = 0; i < N; i++) cin >> marbles[i];
        sort(marbles, marbles+N);

        cout << "CASE# " << ++kase << ":" << endl;
        for (int i = 0; i < Q; i++) {
            int value;
            cin >> value;
            int p = lower_bound(marbles, marbles+N, value) - marbles;
            if (marbles[p] == value) {
                cout << value << " found at " << p+1 << endl;
            } else {
                cout << value << " not found" << endl;
            }
        }
    }

    return 0;
}
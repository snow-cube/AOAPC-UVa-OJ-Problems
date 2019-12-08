#include <iostream>
using namespace std;

const int MAXN = 100005;
int generator[MAXN];

int main() {
    for (int i = 1; i < MAXN; i++) {
        int result = i, g = i;
        while (g > 0) {
            result += g % 10;
            g /= 10;
        }
        if (result < MAXN && (!generator[result] || i < generator[result]))
            generator[result] = i;
    }

    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << generator[N] << endl;
    }


    return 0;
}

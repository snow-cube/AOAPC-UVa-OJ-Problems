#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        string s, subs, cmps;
        int t, times;
        cin >> s;
        int l = s.length();
        for (t = 1; t <= l; t++) {
            if (l % t) continue;
            subs = s.substr(0, t);
            times = l / t;

            cmps = subs;
            for (int i = 0; i < times - 1; i++) cmps += subs;
            if (cmps == s) break;
        }

        cout << t << endl;
        if (N) cout << endl;
    }

    return 0;
}

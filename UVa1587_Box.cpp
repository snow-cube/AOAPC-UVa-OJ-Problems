#include <iostream>
#include <algorithm>
using namespace std;

struct pallet {
    int w;
    int h;
} p[6];

bool cmp(struct pallet a, struct pallet b) {
    if (a.w != b.w) return a.w < b.w;
    return a.h <= b.h;
}

bool check() {
    sort(p, p+6, cmp);

    for (int i = 0; i < 5; i += 2) {
        if (p[i].w != p[i+1].w || p[i].h != p[i+1].h) return false;
    }

    if (p[2].w == p[0].w) {
        if (p[4].w == p[2].h) {
            return p[4].h == p[0].h;
        } else if (p[4].h == p[2].h) {
            return p[4].w == p[0].h;
        } else {
            return false;
        }
    } else if (p[2].h == p[0].w) {
        if (p[4].w == p[2].w) {
            return p[4].h == p[0].h;
        } else if (p[4].h == p[2].w) {
            return p[4].w == p[0].h;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main() {
    while (cin >> p[0].w >> p[0].h) {
        if (p[0].w > p[0].h) swap(p[0].w, p[0].h);
        for (int i = 1; i < 6; i++) {
            cin >> p[i].w >> p[i].h;
            if (p[i].w > p[i].h) swap(p[i].w, p[i].h);
        }

        cout << (check() ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    }

    return 0;
}
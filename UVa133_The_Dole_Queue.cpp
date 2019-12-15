#include <iostream>
#include <cstdio>
using namespace std;

int n, k, m;
int q[25];

int go(int p, int d, int t) {
    while(t--) {
        do {
            p = (p+d+n-1) % n + 1;
        } while (q[p] == 0);
    }
    return p;
}

int main() {
    while (cin >> n >> k >> m && n) {
        for (int i = 1; i <= n; i++) q[i] = i;

        int nleft = n, p1 = n, p2 = 1;
        while (nleft) {
            p1 = go(p1, 1, k);
            p2 = go(p2, -1, m);
            
            printf("%3d", p1);
            nleft--;
            if (p1 != p2) {
                printf("%3d", p2);
                nleft--;
            }
            q[p1] = q[p2] = 0;
            if (nleft) printf(",");
        }

        printf("\n");
    }

    return 0;
}
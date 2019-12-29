#include <iostream>
#include <cstring>
using namespace std;

int vExp[16][16], hExp[16][16], H[16][16], V[16][16], cnt[16];

int main() {
    int m, n, kase = 0;
    while (cin >> n >> m) {
        memset(vExp, 0, sizeof(vExp));
        memset(hExp, 0, sizeof(hExp));
        memset(H, 0, sizeof(H));
        memset(V, 0, sizeof(V));
        memset(cnt, 0, sizeof(cnt));

        char c;
        int x, y;
        for (int i = 0; i < m; i++) {
            cin >> c >> x >> y;
            if (c == 'H') H[x][y] = 1;
            else V[y][x] = 1;
        }

        for (int i = n; i >= 1; i--) {
            for (int j = n; j >= 1; j--) {
                if (H[i][j]) hExp[i][j] = hExp[i][j+1] + 1;
                if (V[i][j]) vExp[i][j] = vExp[i+1][j] + 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int max_s = min(hExp[i][j], vExp[i][j]);

                for (int s = 1; s <= max_s; s++) {
                    if (hExp[i+s][j] >= s && vExp[i][j+s] >= s)
                        cnt[s]++;
                }
            }
        }

        if (kase) printf("\n**********************************\n\n");
        printf("Problem #%d\n\n", ++kase);
        bool found = false;
        for (int s = 1; s < 16; s++) {
            if (cnt[s]) {
                found = true;
                printf("%d square (s) of size %d\n", cnt[s], s);
            }
        } 
        if (!found) printf("No completed squares can be found.\n");
    }

    return 0;
}
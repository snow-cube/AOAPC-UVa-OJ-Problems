#include <cstdio>
using namespace std;

const int kMax = 30;
int a[kMax][kMax];

int main() {
    int n, x, y, tot = 0;
    scanf("%d", &n);
    tot = a[x=0][y=n-1] = 1;
    while (tot < n*n) {
        while (x+1 < n && !a[x+1][y]) a[++x][y] = ++tot;
        while (y-1 >= 0 && !a[x][y-1]) a[x][--y] = ++tot;
        while (x-1 >= 0 && !a[x-1][y]) a[--x][y] = ++tot;
        while (y+1 < n && !a[x][y+1]) a[x][++y] = ++tot;
    }

    for (x = 0; x < n; x++) {
        for (y = 0; y < n; y++)
            printf("%4d", a[x][y]);
        printf("\n");
    }

    return 0;
}

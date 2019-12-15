#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char sqr[10][10];
int point_x[100];
int point_y[100];

int main() {
    int kase = 0, row, col;
    while (cin >> row && row && cin >> col) {
        memset(sqr, 0, sizeof(sqr));
        memset(point_x, -1, sizeof(point_x));
        memset(point_y, -1, sizeof(point_y));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> sqr[i][j];
            }
        }

        int order = 0;
        cout << (kase ? "\n" : "");
        printf("puzzle #%d:\nAcross\n", ++kase);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                bool flag = false;
                if (sqr[i][j] != '*' && (!j || sqr[i][j-1] == '*')) {
                    flag = true;
                    printf("%3d.", ++order);
                    for (int k = j; k < col; k++) {
                        if (sqr[i][k] == '*') break;
                        printf("%c", sqr[i][k]);
                    }
                    printf("\n");
                }

                if (sqr[i][j] != '*' && (!i || sqr[i-1][j] == '*')) {
                    if (!flag) order++;
                    point_x[order] = i;
                    point_y[order] = j;
                }
            }
        }

        printf("Down\n");
        for (int i = 1; i <=  order; i++) {
            if (point_x[i] >= 0 && point_y[i] >= 0) {
                printf("%3d.", i);
                for (int j = point_x[i]; j < row; j++) {
                    if (sqr[j][point_y[i]] == '*') break;
                    printf("%c", sqr[j][point_y[i]]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}

#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const double EPS = 1e-6;

int main() {
    const double lg2 = log10(2);
    char s[256] = "";
    double A, lgv;
    int B;

    while (scanf("%s", s) == 1 && strcmp(s, "0e0")) {
        *strchr(s, 'e') = ' ';
        sscanf(s, "%lf%d", &A, &B);

        lgv = log10(A) + B;
        for (int M = 1; M <= 10; M++) {
            int E = floor(log10((lgv+M*lg2-log10((1<<M)-1)) / lg2 + 1) / lg2 + 0.5);
            if (fabs(log10((1<<M)-1) - M*lg2 + ((1<<E)-1)*lg2 - lgv) <= EPS) {
                printf("%d %d\n", M - 1, E);
                break;
            }
        }
    }

    return 0;
}
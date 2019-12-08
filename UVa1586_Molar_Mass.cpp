#include <cstdio>
#include <cctype>

char s[100];

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        double result = 0;
        scanf("%s", s);
        
        char ch;
        int a = 1;
        for (int i = 0; s[i]; i++) {
            ch = s[i];
            if (isdigit(s[i+1])) {
                a = 0; // in order to a*10 + ...
                for (++i; isdigit(s[i]); i++) {
                    a = a*10 + s[i] - '0';
                }
                i--;
            }

            switch (ch) {
                case 'C':
                    result += 12.01 * a;
                    break;
                case 'H':
                    result += 1.008 * a;
                    break;
                case 'O':
                    result += 16.00 * a;
                    break;
                case 'N':
                    result += 14.01 * a;
                    break;
            }
            a = 1;
        }
        
        printf("%.3lf\n", result);
    }

    return 0;
}

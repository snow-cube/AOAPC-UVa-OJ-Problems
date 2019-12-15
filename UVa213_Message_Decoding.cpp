#include <cstdio>
#include <cstring>
using namespace std;

char code[8][1<<8];

char read_char() {
    while (true) {
        char ch = getchar();
        if (ch != '\n' && ch != '\r') return ch;
    }
}

int read_int(int l) {
    int num = 0;
    while (l--) {
        num = num * 2 + read_char() - '0';
    }

    return num;
}

bool readcodes() {
    memset(code, 0, sizeof(code));

    code[1][0] = read_char();
    for (int i = 2; i < 8; i++) {
        for (int j = 0; j < (1 << i) - 1; j++) {
            char ch = getchar();
            if (ch == EOF) return false;
            if (ch == '\n' || ch == '\r') return true;
            code[i][j] = ch;
        }
    }

    return true;
}

int main() {
    while (readcodes()) {
        while (true) {
            int len = read_int(3);
            if (!len) break;

            while (true) {
                int v = read_int(len);
                if (v == (1 << len) - 1) break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }

    return 0;
}
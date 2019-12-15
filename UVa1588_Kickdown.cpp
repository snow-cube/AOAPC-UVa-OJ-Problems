#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
int a[205], b[205];

void transfer(int *arr, string s) {
    int l = s.length();
    for (int i = 0; i < l; i++) {
        arr[i] = s[i] - '0';
    }
}

int check(int *top, int *bottom, int step, int l1, int l2) {
    int len = 0;
    for (int i = 0; i < 205 - step; i++) {
        if (!top[i] || !bottom[i+step]) break;
        if (top[i] + bottom[i+step] > 3) {
        	len = INF;
        	break;
    	}
    }

    if (len < INF) len = max(l1+step, l2);
    return len;
}

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        transfer(a, s1);
        transfer(b, s2);

        int l1 = s1.length(), l2 = s2.length();
        int most = max(l1, l2);
        int len1, len2;
        for (int step = 0; step <= most; step++) {
            len1 = check(a, b, step, l1, l2);
            if (len1 < INF) {
                break;
            }
        }
        for (int step = 0; step <= most; step++) {
            len2 = check(b, a, step, l2, l1);
            if (len2 < INF) {
                break;
            }
        }

        cout << min(len1, len2) << endl;
    }

    return 0;
}

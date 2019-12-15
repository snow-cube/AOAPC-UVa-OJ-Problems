#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char cnt[1000][4];

int main() {
    short vac[26];
    vac[0] = 0;
    vac['C'-'A'] = 1;
    vac['G'-'A'] = 2;
    vac['T'-'A'] = 3;

    char vac1[4] = {'A', 'C', 'G', 'T'};

    int T;
    cin >> T;
    while (T--) {
        memset(cnt, 0, sizeof(cnt));
        
        int m, n;
        cin >> m >> n;
        string s;
        for (int i = 0; i < m; i++) {
            cin >> s;
            for (int j = 0; j < n; j++) cnt[j][vac[s[j]-'A']]++;
        }
        
        int ham = m * n;
        for (int i = 0; i < n; i++) {
            int maxn = 0;
            for (int j = 0; j < 4; j++) {
                if (cnt[i][j] > cnt[i][maxn]) maxn = j;
            }

            cout << vac1[maxn];
            ham -= cnt[i][maxn];
        }
        cout << endl << ham << endl;
    }

    return 0;
}

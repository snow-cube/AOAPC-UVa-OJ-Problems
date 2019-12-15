#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int cnt1[26];
int cnt2[26];

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        
        int l = s1.length();
        for (int i = 0; i < l; i++) {
            cnt1[s1[i]-'A']++;
            cnt2[s2[i]-'A']++;
        }
        
        sort(cnt1, cnt1+26);
        sort(cnt2, cnt2+26);

        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] != cnt2[i]) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }

    return 0;
}
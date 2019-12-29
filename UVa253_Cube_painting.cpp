#include <iostream>
#include <cstring>
using namespace std;

char cube1[7];
int side[7][4] = {
    {0},
    {2, 4, 5, 3},
    {6, 4, 1, 3},
    {2, 1, 5, 6},
    {2, 6, 5, 1},
    {1, 4, 6, 3},
    {2, 3, 5, 4}
};

int main() {
    string s;
    while (cin >> s) {
        for (int i = 1; i <= 6; i++) cube1[i] = s[i-1];

        bool flag = false;
        for (int top = 1; top <= 6 && !flag; top++) {
            for (int front = 0; front < 4; front++) {
                string ans;
                ans += cube1[top];
                ans += cube1[side[top][front]];
                ans += cube1[side[top][(front+3)%4]];
                ans += cube1[side[top][(front+1)%4]];
                ans += cube1[side[top][(front+2)%4]];
                ans += cube1[7-top];

                if (ans == s.substr(6, 6)) {
                    flag = true;
                    break;
                }
            }
        }

        cout << (flag ? "TRUE" : "FALSE") << endl;
    }

    return 0;
}
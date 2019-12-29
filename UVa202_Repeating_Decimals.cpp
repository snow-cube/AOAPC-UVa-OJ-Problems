#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

const int MAXN = 3005;
map<int, int> Pos;

void solve(int n, const int d, string& ans, int& r) {
    Pos.clear();
    ans = ".";

    while (true) {
        n *= 10;
        int p = Pos[n];
        if (p == 0) Pos[n] = ans.size();
        else {
            // 出现循环
            r = ans.size() - p;
            if (ans.size() > 51) {
                ans.erase(51);
                ans += "...";
            }
            ans.insert(p, "(");
            ans += ')';

            break;
        }

        if (n < d) { // 补零
            ans += '0';
            continue;
        }

        ans += (char)(n / d + '0');
        n = n % d;
        if (!n) { // 除尽
            ans += "(0)";
            r = 1;
            break;
        }
    }
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        string ans = ".(0)";
        int r = 1;
        if (a % b) solve(a % b, b, ans, r);
        printf("%d/%d = %d%s\n", a, b, a / b, ans.c_str());
        printf("   %d = number of digits in repeating cycle\n\n", r);
    }

    return 0;
}
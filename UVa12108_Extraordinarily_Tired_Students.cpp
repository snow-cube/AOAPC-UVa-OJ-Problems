#include <iostream>
#include <set>
using namespace std;

struct Student {
    int a, b, c;
} stus[12];

int n;
set<string> es;

void encode(string& ans) {
    ans.clear();
    for (int i = 0; i < n; i++) ans += (char)(stus[i].c + '0');
}

int main() {
    es.clear();
    int kase = 0;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++)
            cin >> stus[i].a >> stus[i].b >> stus[i].c;
        
        cout << "Case " << ++kase << ": ";
        int minute = 1;
        while (true) {
            string status;
            encode(status);
            if (es.count(status)) {
                cout << -1 << endl;
                break;
            }
            es.insert(status);

            int awake = 0;
            for (int i = 0; i < n; i++) {
                if (stus[i].c <= stus[i].a) awake++;
            }

            if (awake == n) {
                cout << minute << endl;
                break;
            }

            for (int i = 0; i < n; i++) {
                stus[i].c++;
                if (stus[i].a + stus[i].b + 1 == stus[i].c)
                    stus[i].c = 1;
                if (stus[i].c == stus[i].a + 1 && awake >= n - awake)
                    stus[i].c = 1;
            }

            minute++;
        }
    }
}
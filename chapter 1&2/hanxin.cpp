#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    int ans = 0, kase = 1;
    while (cin >> a >> b >> c) {
        for (int i = a + 9; i <= 100; i += 3) {
            if (i % 5 == b && i % 7 == c) {
                ans = i;
                break;
            }
        }

        cout << "Case " << kase++ << ": ";
        if (ans)
            cout << ans << endl;
        else
            cout << "No answer" << endl;

        ans = 0;
    }

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
    string sub, s;
    while (cin >> sub) {
        cin >> s;
        bool flag = false;
        for (int i = 0, j = 0; j < s.length(); j++) {
            if (sub[i] == s[j]) {
                i++;
            }
            if (i == sub.length()) {
                flag = true;
                break;
            }
        }

        cout << (flag ? "Yes" : "No") << endl;
    }

    return 0;
}

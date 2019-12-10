#include <iostream>
#include <string>
using namespace std;

bool is_less(string s, int a, int b) {
    int l = s.length();
    for (int i = 0; i < l; i++) {
        char ai = s[(a+i)%l];
        char bi = s[(b+i)%l];
        if (ai != bi)
            return ai < bi;
    }
    return false;
}

int main() {
    int T;
    string s;
    cin >> T;

    while (T--) {
        cin >> s;
        int l = s.length();
        int minn = 0;
        for (int i = 0; i < l; i++) {
            if (is_less(s, i, minn))
                minn = i;
        }

        for (int i = 0; i < l; i++) cout << s[(minn+i)%l];
        cout << endl;
    }

    return 0;
}

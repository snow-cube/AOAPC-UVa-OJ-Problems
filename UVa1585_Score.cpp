#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int score = 0, step = 0;
    int N;
    cin >> N;
    while (N--) {
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'X') {
                step = 0;
            } else {
                score += (++step);
            }
        }
        cout << score << endl;

        score = 0;
        step = 0;
    }

    return 0;
}

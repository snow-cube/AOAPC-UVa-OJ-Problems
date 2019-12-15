#include <iostream>
#include <string>
using namespace std;

string s, s_guess;
int nleft, chance;
bool win, lose;

void guess(char ch) {
    bool wrong = true;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ch) {
            wrong = false;
            nleft--;
            s[i] = ' ';
        }
    }

    if (wrong) chance--;
    if (!chance) lose = true;
    if (!nleft) win = true;
}

int main() {
    int rnd;
    while (cin >> rnd >> s >> s_guess && rnd != -1) {
        win = lose = false;
        nleft = s.length();
        chance = 7;

        for (int i = 0; i < s_guess.length(); i++) {
            guess(s_guess[i]);
            if (win || lose) break;
        }

        cout << "Round " << rnd << endl;
        if (win) cout << "You win." << endl;
        else if (lose) cout << "You lose." << endl;
        else cout << "You chickened out." << endl;
    }

    return 0;
}
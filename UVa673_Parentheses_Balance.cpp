#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    getchar();
    while (n--) {
        bool flag = true;
        char c;
        stack<char> s;
        string str;
        getline(cin, str);
        if (str.size())
            for (int i = 0; str[i]; i++) {
                c = str[i];
                if (c == '(' || c == '[')
                    s.push(c);
                else if (s.empty() || (c == ')' && s.top() != '(') || (c == ']' && s.top() != '[')) {
                    flag = false;
                    break;
                } else {
                    s.pop();
                }
            }
        if (!s.empty())
            flag = false;
        cout << (flag ? "Yes" : "No") << endl;
    }

    return 0;
}
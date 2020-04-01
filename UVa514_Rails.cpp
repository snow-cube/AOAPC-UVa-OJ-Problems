#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    while (cin >> N && N) {
        while (true) {
            stack<int> st;
            bool flag = true;
            int a;
            cin >> a;
            if (!a) break;
            int tot = 0;
            for (int i = 0; i < N; i++) {
                if (i)
                    cin >> a;
                if (tot > a) {
                    if (st.top() == a)
                        st.pop();
                    else
                        flag = false;      
                } else if (tot == a) {
                    st.pop();
                } else {
                    do {
                        st.push(++tot);
                    } while (st.top() < a);
                    st.pop();
                }
            }
            cout << (flag ? "Yes" : "No") << endl;
        }
        cout << endl;
    }

    return 0;
}
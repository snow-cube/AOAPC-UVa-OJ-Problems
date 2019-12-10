#include <iostream>
#include <cstring>
using namespace std;

int times[10];
int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(times, 0, sizeof(times));
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int num = i;
            while (num > 0) {
                times[num%10]++;
                num /= 10;
            }
        }

		cout << times[0];
        for (int i = 1; i < 10; i++) cout << " " << times[i];
        cout << endl;
    }
    
    return 0;
}

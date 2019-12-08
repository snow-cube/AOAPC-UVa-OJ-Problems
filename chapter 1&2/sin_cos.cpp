#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n;
    cin >> n;
    n = n/180 * acos(-1.0);
    cout << "sin " << n << ": " << sin(n) << endl;
    cout << "cos " << n << ": " << cos(n) << endl;

    return 0;
}

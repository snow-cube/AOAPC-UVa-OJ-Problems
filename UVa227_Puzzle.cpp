#include <iostream>
#include <cstdio>
using namespace std;

char a[5][5];

int main() {
    char ch;
    int x, y;
    int kase = 0;
    while (cin >> ch && ch != 'Z') {
        bool flag = false;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) {
                if (i == 0 && j == 0) a[i][j] = ch;
                else {
                    char c = getchar();
                    if ((c < 'A' || c > 'Z') && c != ' ') {
                        j--;
                    } else {
                        a[i][j] = c;
                        
                        if (a[i][j] == ' ') {
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        //cout << "input complete" << endl;
        char o;
        while (cin >> o && o != '0') {
            int obj_x = x, obj_y = y;
            switch (o) {
                case 'A':
                    if (x == 0)
                        flag = true;
                    else
                        obj_x--;
                    break;
                case 'B':
                    if (x == 4)
                        flag = true;
                    else
                        obj_x++;
                    break;
                case 'L':
                    if (y == 0)
                        flag = true;
                    else
                        obj_y--;
                    break;
                case 'R':
                    if (y == 4)
                        flag = true;
                    else
                        obj_y++;
                    break;
            }
            //cout << "move1" << endl;

            a[x][y] = a[obj_x][obj_y];
            a[obj_x][obj_y] = ' ';
            x = obj_x;
            y = obj_y;
            //cout << "move2" << endl;
        }
        
        cout << (kase > 0 ? "\n" : "");
        printf("Puzzle #%d:\n", ++kase);
        if (flag) {
            cout << "This puzzle has no final configuration." << endl;
        } else {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++)
                    cout << a[i][j] << " ";
                cout << endl;
            }
        }
    }

    return 0;
}

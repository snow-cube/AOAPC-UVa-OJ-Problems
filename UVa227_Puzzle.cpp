#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[5][5];

int main() {
    char ch;
    int x, y;
    int kase = 0;
    ch = getchar();
    while (ch != 'Z') {
    	memset(a, 0, sizeof(a));
        bool flag = false;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) {
                if (i == 0 && j == 0) {
					a[i][j] = ch;
					if (ch == ' ') {
						x = i;
						y = j;
					}
				}
                else {
                    char c = getchar();
                    if (c == '\n' && j == 4) {
                    	a[i][j] = ' ';
                    	x = i;
                    	y = j;
					} else if ((c < 'A' || c > 'Z') && c != ' ') {
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
                    if (obj_x == 0)
                        flag = true;
                    else
                        obj_x--;
                    break;
                case 'B':
                    if (obj_x == 4)
                        flag = true;
                    else
                        obj_x++;
                    break;
                case 'L':
                    if (obj_y == 0)
                        flag = true;
                    else
                        obj_y--;
                    break;
                case 'R':
                    if (obj_y == 4)
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
                    cout << a[i][j] << (j == 4 ? "" : " ");
                cout << endl;
            }
        }
        
	    while ((ch = getchar()) == '\n');
//        getchar();
    }

    return 0;
}

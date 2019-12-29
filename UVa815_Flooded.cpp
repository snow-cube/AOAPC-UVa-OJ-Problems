#include <iostream>
#include <algorithm>
using namespace std;

int sqr[905];

int main() {
    int v, m, n;
    int kase = 0;
    while (cin >> m >> n && m) {
        for (int i = 1; i <= m * n; i++) cin >> sqr[i];
        cin >> v;

        sort(sqr + 1, sqr + m*n + 1);
        int l = 1, r = m * n, ans;
        double h; // 水的高度
        while (l <= r) {
            int mid = l + (r - l) / 2;

            // 计算将淹没mid个格子时的降雨量
            int mid_v = sqr[mid] * mid * 100;
            for (int i = 1; i <= mid; i++) mid_v -= sqr[i] * 100;

            // 比较
            if (mid_v < v) {
                // 还能多淹
                ans = mid;
                h = sqr[mid] + (double)(v - mid_v) / (100.0 * mid);

                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        printf("Region %d\n", ++kase);
        printf("Water level is %.2lf meters.\n", h);
        printf("%.2lf percent of the region is under water.\n\n", 100.0 * ans / (m*n));
    }

    return 0;
}
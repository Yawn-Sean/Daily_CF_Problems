#include <bits/stdc++.h>
#define BASE 100
using namespace std;

int cnt[2][BASE * 2 + 10][BASE * 2 + 10];
short dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

int main() {
    int n, q; scanf("%d%d", &n, &q);

    int rng = 0;
    cnt[0][BASE][BASE] = n;

    int steps = 0;
    while (true) {
        steps++;
        bool changed = false;
        for (int x = -rng; x <= rng; x++) for (int y = -rng; y <= rng; y++) {
            int v = cnt[steps & 1 ^ 1][BASE + x][BASE + y];
            if (v >= 4) {
                changed = true;
                for (int k = 0; k < 4; k++) {
                    int xx = x + dir[k][0], yy = y + dir[k][1];
                    rng = max(rng, yy);
                    cnt[steps & 1][BASE + xx][BASE + yy] += v / 4;
                }
            }
            cnt[steps & 1][BASE + x][BASE + y] += v % 4;
        }
        if (!changed) break;
        for (int x = -rng; x <= rng; x++) for (int y = -rng; y <= rng; y++) cnt[steps & 1 ^ 1][BASE + x][BASE + y] = 0;
    }

    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        if (abs(x) > rng || abs(y) > rng) printf("0\n");
        else printf("%d\n", cnt[steps & 1][BASE + x][BASE + y]);
    }
    return 0;
}

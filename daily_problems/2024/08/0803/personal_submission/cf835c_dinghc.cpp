#include <bits/stdc++.h>

using namespace std;
using li = long long;
constexpr int MX = 100;
int dp[11][MX + 2][MX + 2];

int main() {
    int n, q, c;
    scanf("%d%d%d", &n, &q, &c);
    for (int i = 0, x, y, p; i < n; i++) {
        scanf("%d%d%d", &x, &y, &p);
        dp[p][x][y]++;
    }
    for (int x = 1; x <= MX; x++) {
        for (int y = 1; y <= MX; y++) {
            for (int p = 0; p <= c; p++) {
                dp[p][x][y] += dp[p][x - 1][y] + dp[p][x][y - 1] - dp[p][x - 1][y - 1];
            }
        }
    }
    for (int i = 0, t, x1, y1, x2, y2; i < q; i++) {
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        int res = 0;
        for (int p = 0; p <= c; p++) {
            int b = (p + t) % (c + 1);
            res += b * (dp[p][x2][y2] - dp[p][x2][y1 - 1] - dp[p][x1 - 1][y2] + dp[p][x1 - 1][y1 - 1]);
        }
        printf("%d\n", res);
    }
    return 0;
}


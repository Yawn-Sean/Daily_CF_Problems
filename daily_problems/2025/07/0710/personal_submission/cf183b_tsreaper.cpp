#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
#define MAXM 250
using namespace std;
typedef pair<int, int> pii;

int n, m, X[MAXM + 5], Y[MAXM + 5];

unordered_map<int, unordered_map<int, int>> cnt[MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d%d", &X[i], &Y[i]);
    for (int i = 1; i <= m; i++) for (int j = i + 1; j <= m; j++) if (Y[i] != Y[j]) {
        int dx = X[j] - X[i], dy = Y[j] - Y[i];
        if (dx < 0 || (dx == 0 && dy < 0)) dx = -dx, dy = -dy;
        int g = gcd(abs(dx), abs(dy));
        long long a = 1LL * dy * X[i] - 1LL * dx * Y[i], b = dy;
        if (a % b == 0 && a / b > 0 && a / b <= n) cnt[a / b][dx / g][dy / g]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (auto &p1 : cnt[i]) for (auto &p2 : p1.second) mx = max(mx, p2.second);
        double t = sqrt(1 + 8 * mx) + 1;
        ans += (int) round(t) / 2;
    }
    printf("%d\n", ans);
    return 0;
}

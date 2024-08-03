#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200010;

int n, m;
int pr[N], nx[N], f[N], l[N], r[N];
LL dp[N][2];

int calc(int x, int y) {
    if (x > y) swap(x, y);
    if (pr[y] >= x) return y - x;
    int res = INT_MAX;
    if (pr[x]) res = min(res, x + y - (pr[x] << 1));
    if (nx[y]) res = min(res, (nx[y] << 1) - x - y);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c1, c2;
    cin >> n >> m >> c1 >> c2;
    n = m = 0;
    for (int i = 1, x, y; i <= c1; ++i) {
        cin >> x >> y;
        n = max(n, x);
        m = max(m, y);
        l[x] = l[x] ? min(l[x], y) : y;
        r[x] = r[x] ? max(r[x], y) : y;
    }
    if (!l[1]) l[1] = r[1] = 1;
    for (int i = 1, x; i <= c2; ++i) {
        cin >> x;
        m = max(m, x);
        f[x] = 1;
    }
    for (int i = 1; i <= m; ++i) pr[i] = f[i] ? i : pr[i - 1];
    for (int i = m; i; --i) nx[i] = f[i] ? i : nx[i + 1];
    dp[1][0] = r[1] - 1 + r[1] - l[1];
    dp[1][1] = r[1] - 1;
    for (int i = 1; i < n; ++i) {
        if (!l[i + 1]) {
            l[i + 1] = l[i];
            r[i + 1] = r[i];
            dp[i + 1][0] = dp[i][0], dp[i + 1][1] = dp[i][1];
            continue;
        }
        dp[i + 1][0] = min(dp[i][0] + calc(l[i], l[i + 1]), dp[i][1] + calc(r[i], l[i + 1]));
        dp[i + 1][1] = min(dp[i][0] + calc(l[i], r[i + 1]), dp[i][1] + calc(r[i], r[i + 1]));
        swap(dp[i + 1][0], dp[i + 1][1]);
        dp[i + 1][0] += r[i + 1] - l[i + 1];
        dp[i + 1][1] += r[i + 1] - l[i + 1];
    }
    cout << min(dp[n][0], dp[n][1]) + n - 1;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, xa, ya, xb, yb;
    scanf("%d%d%d%d%d%d", &n, &m, &xa, &ya, &xb, &yb);

    int u = min(xa - 1, xb - 1);
    int d = min(n - xa, n - xb);
    int l = min(ya - 1, yb - 1);
    int r = min(m - ya, m - yb);

    int ua = xa - u;
    int da = xa + d;
    int la = ya - l;
    int ra = ya + r;

    int ub = xb - u;
    int db = xb + d;
    int lb = yb - l;
    int rb = yb + r;

    int uc = max(ua, ub);
    int dc = min(da, db);
    int lc = max(la, lb);
    int rc = min(ra, rb);

    long long sa = 1LL * (da - ua + 1) * (ra - la + 1);
    long long sb = 1LL * (db - ub + 1) * (rb - lb + 1);
    long long sc = 0;
    if (uc <= dc && lc <= rc)
        sc = 1LL * (dc - uc + 1) * (rc - lc + 1);
    long long ans = sa + sb - sc;
    ans = 1LL * n * m - ans;
    printf("%lld\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

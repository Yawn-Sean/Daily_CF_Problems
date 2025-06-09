#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int MOD = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int d, n, m;
    cin >> d >> n >> m;
    vector<int> rows_pre(n + 2, 0), rows_suf(n + 2, 0), cols_pre(m + 2, 0), cols_suf(m + 2, 0);
    vector<int> vx1(d), vy1(d), vx2(d), vy2(d);
    for (int i = 0; i < d; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        vx1[i] = x1, vy1[i] = y1, vx2[i] = x2, vy2[i] = y2;
        cols_pre[y1]++, cols_suf[y2]++, rows_pre[x1]++, rows_suf[x2]++;
    }
    for (int i = 1; i <= m; ++i) cols_pre[i] += cols_pre[i-1];
    for (int i = m; i >= 0; --i) cols_suf[i] += cols_suf[i+1];
    for (int i = 1; i <= n; ++i) rows_pre[i] += rows_pre[i-1];
    for (int i = n; i >= 0; --i) rows_suf[i] += rows_suf[i+1];
    int l, r, t, b;
    cin >> l >> r >> t >> b;
    for (int i = 0; i < d; ++i) {
        int x1i = vx1[i], y1i = vy1[i], x2i = vx2[i], y2i = vy2[i];
        int li = rows_pre[x2i-1], ri = rows_suf[x1i+1], ti = cols_pre[y2i-1], bi = cols_suf[y1i+1];
        if (x1i < x2i) {
            li--, ri--;
        } else {
            ti--, bi--;
        }
        if (l == li && r == ri && t == ti && b == bi) {
            cout << i + 1;
            return;
        }
    }
    cout << -1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
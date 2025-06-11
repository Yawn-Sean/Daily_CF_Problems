#include <bits/stdc++.h>
using namespace std;

#define fi first 
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using i64 = long long;
using pi = pair<i64, i64>;

void solve() {
    int n;
    cin >> n;
    ve<pi> a(n);
    rep(i, 0, n) {
        cin >> a[i].fi >> a[i].se;
        if (a[i].fi > a[i].se) {
            swap(a[i].fi, a[i].se);
        }
    }
    sort(all(a), [&](const pi& b, const pi& c) {
        return b.se > c.se;
    });
    i64 res = a[0].fi * a[0].se, mx = a[0].fi, cur;
    rep(i, 1, n) {
        res = max(res, a[i].fi * a[i].se);
        cur = min(mx, a[i].fi);
        res = max(res, cur * a[i].se * 2);
        mx = max(mx, a[i].fi); 
    }
    long double as = (long double)res;
    cout << fixed << setprecision(1) << as / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}

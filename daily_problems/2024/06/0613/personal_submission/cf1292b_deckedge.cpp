#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int64_t, int64_t>;

int64_t inline lred() {
    int64_t x;
    cin >> x;
    return x;
}

void solve() {
    int64_t x0 = lred(), y0 = lred(), ax = lred(), ay = lred(), bx = lred(), by = lred(), stx = lred(), sty = lred(), t = lred();
    ve<pi> a;
    a.emplace_back(x0, y0);
    int64_t lim = (1ll << 62) - 1;
    while ((lim - bx) / ax >= a.back().fi && (lim - by) / ay >= a.back().se) {
        int64_t fir = ax * a.back().fi + bx, sec = ay * a.back().se + by;
        a.emplace_back(fir, sec);
    }  
    int n = a.size(), res = 0;
    rep(i, 0, n) {
        rep(j, i, n) {
            int64_t len = a[j].fi - a[i].fi + a[j].se - a[i].se;
            int64_t dist_l = abs(stx - a[i].fi) + abs(sty - a[i].se);
            int64_t dist_r = abs(stx - a[j].fi) + abs(sty - a[j].se);
            if (t - dist_l >= len || len <= t - dist_r) {
                res = max(res, j - i + 1);
            }
        }
    }
    cout << res << '\n';
}
  
int main() {  
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {  
        solve();
    }  
    return 0;  
}

/*
https://codeforces.com/problemset/problem/1292/B
*/
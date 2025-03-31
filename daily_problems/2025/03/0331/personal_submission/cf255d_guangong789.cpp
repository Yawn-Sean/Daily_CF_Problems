#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, x, y, c, x1, x2, y1_, y2_;

bool check(ll t) {
    ll tmp = 2 * t * t + 2 * t + 1;
    ll t1 = t-x1 > 0 ? (t-x1)*(t-x1) : 0;
    ll t2 = t-x2 > 0 ? (t-x2)*(t-x2) : 0;
    ll t3 = t-y1_ > 0 ? (t-y1_)*(t-y1_) : 0;
    ll t4 = t-y2_ > 0 ? (t-y2_)*(t-y2_) : 0;
    ll t5 = (t - 1 - x1 - y1_ > 0) ? (t - 1 - x1 - y1_) * (t - x1 - y1_) / 2 : 0;
    ll t6 = (t - 1 - x1 - y2_ > 0) ? (t - 1 - x1 - y2_) * (t - x1 - y2_) / 2 : 0;
    ll t7 = (t - 1 - x2 - y1_ > 0) ? (t - 1 - x2 - y1_) * (t - x2 - y1_) / 2 : 0;
    ll t8 = (t - 1 - x2 - y2_ > 0) ? (t - 1 - x2 - y2_) * (t - x2 - y2_) / 2 : 0;
    return tmp - (t1 + t2 + t3 + t4) + (t5 + t6 + t7 + t8) >= c;
}

void solve() {
    cin >> n >> x >> y >> c;
    x1 = x - 1;
    x2 = n - x;
    y1_ = y - 1;
    y2_ = n - y;
    ll l = 0, r = 2*n, ans = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i <= n - 1; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + 1LL * a[i - 1];
    auto check = [&](this auto&& check, int mid) -> bool {
        ll cnt = 0;
        for (int i = 0; i <= n - 1; i++) {
            auto x = lower_bound(a.begin(), a.end(), a[i] + mid);
            if (x == a.end()) continue;
            int tem = x - a.begin();
            cnt += 1LL * 2 * (n - tem);
        }
        return cnt >= m;
    };
    int l = 0, r = 1e7, mid;
    int ans = 0;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid;
        } else
            r = mid;
    }
    ll cnt = 0;
    for (int i = 0; i <= n - 1; i++) {
        auto x = lower_bound(a.begin(), a.end(), a[i] + l);
        if (x == a.end()) continue;
        int tem = x - a.begin();
        cnt += 2 * (n - tem);
    }
    ll res = 0;
    int mixx = INT_MAX;
    for (int i = 0; i <= n - 1; i++) {
        auto x = lower_bound(a.begin(), a.end(), a[i] + l);
        if (x == a.end()) continue;
        int tem = x - a.begin();
        mixx = min(a[tem] - a[i], mixx);
        res += 1LL * 2 * (pre[n] - pre[tem] - 1LL * (n - tem) * a[i]);
    }
    cout << res - (cnt - m) * mixx << endl;
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
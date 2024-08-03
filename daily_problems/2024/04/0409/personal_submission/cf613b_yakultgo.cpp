#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    ll n, A, cf, cm, m;
    cin >> n >> A >> cf >> cm >> m;
    vector<int> a(n);
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<ll> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i - 1];
    }
    ll ans = 0;
    // 记录到达A的个数以及最小的等级
    int mx_cnt = 0, mi = INT_MAX;
    // 枚举增加到A的个数
    for (int i = 0; i <= n; i++) {
        ll need = A * i - (sum[n] - sum[n - i]);
        if (need > m) break;
        ll ret = cf * i;
        ll cur = m - need;
        // 来平均升级剩下的元素,也就是算出升级后剩余的最低等级
        ll left = a[0], right = A + 1;
        while (left < right) {
            ll mid = (left + right) / 2;
            int pos = lower_bound(a.begin(), a.begin() + n - i, mid) - a.begin();
            // 之前的元素升级到mid需要的花费
            ll cost = mid * pos - sum[pos];
            if (cost <= cur) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        ret += cm * (left - 1);
        if (ret > ans) {
            ans = ret;
            mx_cnt = i;
            mi = left - 1;
        }
    }
    cout << ans << endl;
    if (mi != INT_MAX) {
        // 把最大的mx_cnt个元素升级到A,小于mi的元素升级到mi就行
        for (int i = 0; i < n; i++) {
            if (b[i].first < mi)
                b[i].first = mi;
            if (i >= n - mx_cnt)
                b[i].first = A;
        }
    }
    sort(b.begin(), b.end(), [](pair<int, int> x, pair<int, int> y) { return x.second < y.second; });
    for (auto x : b) {
        cout << x.first << " ";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
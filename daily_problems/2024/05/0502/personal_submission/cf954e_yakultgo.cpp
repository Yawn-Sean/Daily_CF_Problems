#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, T;
    cin >> n >> T;
    vector<pair<int, int>> a(n);
    int mi = 1e8, mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].second;
        mi = min(mi, a[i].second);
        mx = max(mx, a[i].second);
        a[i].second -= T;
    }
    if (mi > T || mx < T) {
        cout << 0 << endl;
        return;
    }
    double ans = 0;
    vector<pair<int, int>> pos, neg;
    for (int i = 1; i <= n; i++) {
        if (a[i].second > 0) {
            pos.push_back({a[i].second, a[i].first});
        } else if (a[i].second < 0) {
            neg.push_back({-a[i].second, a[i].first});
        } else {
            ans += a[i].first;
        }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    ll sum1 = 0, sum2 = 0;
    for (auto [x, y] : pos) {
        sum1 += 1ll * x * y;
    }
    for (auto [x, y] : neg) {
        sum2 += 1ll * x * y;
    }
    if (sum1 > sum2) {
        swap(sum1, sum2);
        swap(pos, neg);
    }
    for (auto [x, y] : pos) {
        ans += y;
    }
    for (auto [x, y] : neg) {
        ll tmp = 1ll * x * y;
        if (sum1 > tmp) {
            sum1 -= tmp;
            ans += y;
        } else {
            ans += 1.0 * sum1 / x;
            break;
        }
    }
    cout << fixed << setprecision(15) << ans << endl;
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
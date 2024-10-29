#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
        a[i].first *= 2;
        a[i].second *= 2;
        ans = max(ans, a[i].first * a[i].second / 2);
    }
    sort(a.begin(), a.end(), [&](auto& x, auto& y) {
        return x.second > y.second;
    });
    int mx = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, min(mx, a[i].first) * a[i].second);
        mx = max(mx, a[i].first);
    }
    if (ans % 4 == 0) {
        cout << ans / 4 << ".0" << endl;
    } else if (ans % 2 == 0) {
        ans /= 2;
        cout << ans / 2 << ".5" << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans, a;
    cin >> n;
    map<int, int> mp;
    mp[-1] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        auto it = mp.lower_bound(a); // 大于a的最小的数
        auto pre = it;
        pre--; // 小于a的最大的数
        if (it != mp.end() && it->second > pre->second) {
            ans = it->first;
        } else {
            ans = pre->first;
        }
        if (i > 1) {
            cout << ans << ' ';
        }
        mp[a] = i;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
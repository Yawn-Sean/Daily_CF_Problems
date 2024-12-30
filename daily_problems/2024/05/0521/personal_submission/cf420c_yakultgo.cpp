#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    map<int, int> mp[n];
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        mp[u][v]++;
        mp[v][u]++;
        a[u]++;
        a[v]++;
    }
    auto deg = a;
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(a.begin(), a.end(), p - a[i]) - a.begin();
        ans += n - pos;
        if (2 * a[i] >= p)
            ans--;
        for (auto &[k, v] : mp[i]) {
            if (deg[i] + deg[k] - v < p && deg[i] + deg[k] >= p)
                ans--;
        }
    }
    cout << ans / 2 << endl;
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
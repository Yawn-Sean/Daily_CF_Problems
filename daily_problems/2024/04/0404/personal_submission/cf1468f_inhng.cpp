#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>
#define ctzll(x) __builtin_ctzll(x)
#define popcount(x) __builtin_popcount(x)

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, ans = 0;
    cin >> n;
    map<pair<double, int>, int> mp;
    for (int i = 0; i < n; ++i) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        int dx = u - x, dy = v - y;
        if (not dx) {
            int pos = dy / abs(dy);
            ans += mp[{INF, -pos}];
            ++mp[{INF, pos}];
        } else {
            int pos = dx / abs(dx);
            ans += mp[{(double)dy / dx, -pos}];
            ++mp[{(double)dy / dx, pos}];
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}

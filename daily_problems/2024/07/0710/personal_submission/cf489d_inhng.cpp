#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> g[n + 1], cnt(n + 1);
    vector<int> a;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
    }
    for (int u = 1; u <= n; ++u) {
        for (int v : g[u]) {
            for (int w : g[v]) {
                ++cnt[w];
            }
        }
        for (int v = 1; v <= n; ++v) {
            if (u != v) {
                ans += cnt[v] * (cnt[v] - 1) / 2;
            }
            cnt[v] = 0;
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}

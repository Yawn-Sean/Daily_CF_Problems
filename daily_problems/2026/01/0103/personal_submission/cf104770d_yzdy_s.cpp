#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m, k;cin >> n >> m >> k;
    vector<array<int, 3>> res;
    vector<int> deg(n + 1);
    for (int i = 1; i <= (m + k); i++) {
        int u, v;cin >> u >> v;
        deg[u] += 1;
        deg[v] += 1;
        if (u != 1 && v != 1) {
            res.push_back({1, u, v});
        }
    }

    for (int i = 1; i <= n; i++) if (deg[i] & 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << res.size() << endl;
    for (auto &i : res) {
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
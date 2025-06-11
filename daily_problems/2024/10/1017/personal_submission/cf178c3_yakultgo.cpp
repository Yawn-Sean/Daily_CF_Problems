#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long

void solve() {
    int h, m, n;
    cin >> h >> m >> n;
    vector<set<int>> adj;
    vector<bool> vis(h);
    vector<int> id(h);
    vector<int> idx_i(h);
    map<int, int> val_idx;
    int cnt = 0;
    for (int i = 0; i < h; i++) {
        if (vis[i]) continue;
        set<int> tmp;
        for (int j = i, k = i; !vis[j]; j = (j + m) % h, k += m) {
            tmp.insert(k);
            vis[j] = true;
            id[j] = cnt;
            idx_i[j] = k;
        }
        cnt++;
        adj.push_back(tmp);
    }
    vector<int> mi(cnt);
    vector<int> ma(cnt);
    for (int i = 0; i < cnt; i++) {
        mi[i] = *adj[i].begin();
        ma[i] = *adj[i].rbegin();
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        char op;
        int t, hash;
        cin >> op >> t;
        if (op == '+') {
            cin >> hash;
            int g = id[hash];
            int pos = idx_i[hash];
            auto it = adj[g].lower_bound(pos);
            if (it != adj[g].end()) {
                ans += (*it - pos) / m;
            } else {
                it = adj[g].begin();
                ans += (ma[g] - pos) / m + (*it - mi[g]) / m + 1;
            }
            val_idx[t] = (*it) % h;
            adj[g].erase(it);
        } else {
            int g = id[val_idx[t]];
            int pos = idx_i[val_idx[t]];
            val_idx.erase(t);
            adj[g].insert(pos);
        }
    }
    cout << ans << endl;
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
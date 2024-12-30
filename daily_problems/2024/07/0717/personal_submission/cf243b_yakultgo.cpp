#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, m, h, t;
    cin >> n >> m >> h >> t;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n + 1);
    auto check = [&](int x, int y) -> bool {
        if (g[x].size() <= h || g[y].size() <= t) return false;
        int cnt = 0;
        vis[x] = vis[y] = -1;
        for (int v : g[x]) {
            if (!vis[v]) {
                cnt++;
            }
            vis[v] |= 1;
        }
        for (int v : g[y]) {
            if (!vis[v]) {
                cnt++;
            }
            vis[v] |= 2;
        }
        if (cnt >= h + t) {
            vector<int> a1, a2;
            for (int i : g[x]) {
                if (h && vis[i] == 1) {
                    a1.push_back(i);
                    h--;
                }
            }
            for (int i : g[y]) {
                if (t && vis[i] == 2) {
                    a2.push_back(i);
                    t--;
                }
            }
            for (int i : g[x]) {
                if (vis[i] == 3) {
                    if (h) {
                        a1.push_back(i);
                        h--;
                    } else if (t) {
                        a2.push_back(i);
                        t--;
                    }
                }
            }
            cout << "YES" << endl;
            cout << x << " " << y << endl;
            for (int i : a1) cout << i << " ";
            cout << endl;
            for (int i : a2) cout << i << " ";
            return true;
        }
        for (int i : g[x]) vis[i] = 0;
        for (int i : g[y]) vis[i] = 0;

        return false;
    };
    for (int i = 1; i <= n; i++) {
        for (int j : g[i]) {
            if (check(i, j)) return;
        }
    }
    cout << "NO" << endl;
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
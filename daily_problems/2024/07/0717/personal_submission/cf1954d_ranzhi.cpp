#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

bool dfs(int root, vector<vector<int>> &g, vector<int> &vis, int &cnt1, int &cnt2) {
    cnt1++;
    if (vis[root]) cnt2++;
    for (auto &node : g[root]) {
        if (node > 0) {
            if (vis[node] == -1) {
                vis[node] = vis[root];
                if (dfs(node, g, vis, cnt1, cnt2)) return true;;
            } else if (vis[root] != vis[node]) return true;
        } else {
            node = -node;
            if (vis[node] == -1) {
                vis[node] = vis[root] ^ 1;
                if (dfs(node, g, vis, cnt1, cnt2)) return true;
            } else if (vis[node] == vis[root]) return true;
        }
    }
    return false;
}

void solve() { 
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        string s;
        int u, v; cin >> u >> v >> s;
        if (s[0] == 'i') g[u].emplace_back(-v), g[v].emplace_back(-u);
        else g[u].emplace_back(v), g[v].emplace_back(u);
    }
    int ans = 0;
    vector<int> vis(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (vis[i] != -1) continue;
        vis[i] = 0;
        int cnt1 = 0, cnt2 = 0;
        if (dfs(i, g, vis, cnt1, cnt2)) return (void)(cout << -1 << endl);
        else ans += max(cnt2, cnt1 - cnt2);
    }
    cout << ans << endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n, m;
const int maxN = 1e5 + 7;
vector<PII> adj[maxN];
vector<PII> re_adj[maxN];
vector<int> a(maxN, LNF);
vector<int> b(maxN, LNF);
vector<int> vis(maxN, 0);

void dijkstra() {
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    a[1] = 0;
    pq.push({0, 1});
    while (pq.size()) {
        int u = pq.top().second;pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto &[son, w] : adj[u]) {
            if (max(w, a[u]) < a[son]) {
                a[son] = max(w, a[u]);
                pq.push({a[son], son});
            }
        }
    }
    for (int i = 1; i <= n; i++) vis[i] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> rpq;
    b[1] = 0;
    rpq.push({0, 1});
    while (rpq.size()) {
        int u = rpq.top().second;rpq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto &[son, w] : re_adj[u]) {
            if (max(w, b[u]) < b[son]) {
                b[son] = max(w, b[u]);
                rpq.push({b[son], son});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v,w;cin >> u >> v >> w;
        adj[u].push_back({v, w});
        re_adj[v].push_back({u, w});
    }
    dijkstra();
    // for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    // for (int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
    for (int i = 1; i <= n; i++) {
        if (b[i] > a[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
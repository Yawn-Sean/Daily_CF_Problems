#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define vdbg(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << endl;


const int INF = 2e9;
void solve() {  
    int n; cin >> n;
    vector<vector<pair<int, int>>> g(n + 2);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x; cin >> x;
            if (i == j) {
                g[i].push_back({x, n + 1});
                g[n + 1].push_back({x, i});
            }
            else {
                g[i].push_back({x, j});
                g[j].push_back({x, i});
            }
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n + 2, INF), vis(n + 2);
    dis[n + 1] = 0; pq.push({0, n + 1});
    int ans = 0, cnt = 0;
    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ans += d; cnt++;
        for (auto [w, v] : g[u]) {
            if (vis[v]) continue;
            if (w < dis[v]) {
                dis[v] = w;
                pq.push({w, v});
            }
        }
    }
    cout << ans << "\n";
}                                                                     

signed main() {  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int T = 1;
    // cin >> T;  
    while (T--) solve();    
    return 0;
}

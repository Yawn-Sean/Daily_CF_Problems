#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector adj(n + 1, vector<pair<int, int>> ());
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, 1);
        adj[v].emplace_back(u, -1);
    }

    int ans = 0;
    vector<bool> vis(n + 1);
    vector<int> val(n + 1);
    for(int i = 1; i <= n; ++i) {
        if(vis[i]) continue;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(auto [to, w] : adj[cur]) {
                if(vis[to]) {
                    int dif = abs(val[cur] + w - val[to]);
                    ans = gcd(ans, dif);
                    continue;
                }
                val[to] = val[cur] + w;
                vis[to] = 1;
                q.push(to);
            }
        }
    }

    if(!ans) ans = n;
    cout << ans << "\n";

}

#include <bits/stdc++.h>
#define sc scanf
using i64 = long long;
using PII = std::pair<int, int>;

void solve() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    -- s, -- t;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0, u, v; i < m; ++ i) {
        std::cin >> u >> v;
        -- u, -- v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto bfs = [&](int st) -> std::vector<int> {
        std::queue<int> q;
        std::vector<int> dst(n, -1);
        dst[st] = 0;
        q.emplace(st);
        while (q.size()) {
            for (int i = 0, ed = q.size(); i < ed; ++ i) {
                int u = q.front();
                q.pop();
                for (int v : adj[u])
                    if (dst[v] == -1) {
                        dst[v] = dst[u] + 1;
                        q.push(v);
                    }
            }
        }
        return dst;
    };

    std::vector<int> dsts = bfs(s), dstt = bfs(t);

    int res = 0;
    // std::cerr << dsts[t] << '\n';
    for (int i = 0; i < n; ++ i) {
        std::unordered_set<int> st(adj[i].begin(), adj[i].end());
        for (int j = 0; j < i; ++ j){
            if (st.count(j)) continue;
            // std::cerr << i << ' ' << j << ' ' << 
            //     std::min(dsts[i] + dstt[j], dsts[j] + dstt[i]) + 1 << '\n';
            if (std::min(dsts[i] + dstt[j], dsts[j] + dstt[i]) + 1 >= dsts[t]) {
                
                ++ res;
            }

            // if (i != j && !st.count(j) && dsts[i] + dstt[j] + 1 > dsts[t]){
            //     
            //     ++ res;
            // }
        }
    }
    std::cout << res;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}
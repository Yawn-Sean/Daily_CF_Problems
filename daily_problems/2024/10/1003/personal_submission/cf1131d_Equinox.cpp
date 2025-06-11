#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

struct DSU {
    std::vector<int> p;
    int n, sz;
    DSU(int _n) {
        init(_n);
    }
    
    void init (int _n) {
        sz = n = _n;
        p.assign(n, -1);
    }

    int find(int x) {
        int res = x;

        while (p[res] >= 0)
            res = p[res];

        while (p[x] >= 0) {
            int t = p[x];
            p[x] = res;
            x = t;
        }

        return res;
    }

    bool merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (p[px] > p[py]) std::swap(px, py);
        p[px] += p[py], p[py] = px;
        -- sz;
        return true;
    }

    int size(int x) {
        return -p[find(x)];
    }

    int size() const {
        return sz;
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    for (int i = 0; i < n; i ++) 
        std::cin >> g[i];

    DSU dsu(n + m);

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (g[i][j] == '=') {
                dsu.merge(i, n + j);
            }
        }
    }

    std::vector<std::vector<int>> adj(n + m);
    std::vector<int> deg(n + m, 0);

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int u = dsu.find(i), v = dsu.find(n + j);
            if (g[i][j] == '<')  {
                adj[u].push_back(v);
                ++ deg[v];
            }
            else if (g[i][j] == '>') {
                adj[v].push_back(u);
                ++ deg[u];
            }
        }
    }

    std::queue<int> q;
    std::vector<int> ans(n + m, 0);
    for (int i = 0; i < n + m; i ++) {
        if (deg[i] == 0) {
            q.push(i);
            ans[i] = 1;
        }
    }

    int cnt = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        cnt ++;
        for (auto &v: adj[u]) {
            ans[v] = std::max(ans[v], ans[u] + 1);
            if (-- deg[v] == 0) q.push(v);
        }
    }

    if (cnt < n + m) std::cout << "No";
    else {
        std::cout << "Yes\n";
        for (int i = 0; i < n; i ++) 
            std::cout << ans[dsu.find(i)] << " \n"[i + 1 == n];
        for (int i = 0; i < m; i ++) 
            std::cout << ans[dsu.find(n + i)] << " \n"[i + 1 == m];
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef DEBUG
    int cur = clock();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }
#ifdef DEBUG
    std::cerr << "run-time: " << clock() - cur << '\n';
#endif
    return 0;
}
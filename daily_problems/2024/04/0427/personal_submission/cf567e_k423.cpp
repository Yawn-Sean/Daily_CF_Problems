// https://codeforces.com/contest/567/submission/258471281

/* 我永远喜欢爱莉希雅♪ */
i64 p1 = rng() % int(1e9), p2 = rng() % int(1e9);
 
struct Hash {
    i64 v1, v2;
 
    Hash(int v = 0) : v1(v), v2(v) {};
 
    Hash &operator+=(const Hash &o) {
        v1 = (v1 + o.v1) % p1;
        v2 = (v2 + o.v2) % p2;
        return *this;
    }
 
    bool operator==(const Hash &o) const {
        return v1 == o.v1 && v2 == o.v2;
    }
};
 
Hash operator*(const Hash &a, const Hash &b) {
    Hash ret{};
    ret.v1 = a.v1 * b.v1 % p1;
    ret.v2 = a.v2 * b.v2 % p2;
    return ret;
}
 
 
void elysia() {
    int n, m, s, t;
    cin >> n >> m >> s >> t, --s, --t;
    vector<array<int, 3>> adjs(m);
    vector<vector<pii>> g(n), rg(n);
    for (auto &[u, v, w]: adjs) {
        cin >> u >> v >> w, u--, v--;
        g[u].emplace_back(v, w);
        rg[v].emplace_back(u, w);
    }
    auto dijkstra = [&](int st, vector<vector<pii>> &g) {
        vector<i64> dis(n, inf);
        vector<int> vis(n);
        vector<Hash> his(n);
        priority_queue<array<i64, 3>, vector<array<i64, 3>>, greater<>> Q;
        his[st] = {1};
        Q.push({0, st, -1});
        while (!Q.empty()) {
            auto [d, i, pre] = Q.top();
            Q.pop();
            if (pre >= 0 && (!vis[i] || dis[i] == d)) {
                his[i] += his[pre];
            }
            if (vis[i]) continue;
            dis[i] = d, vis[i] = 1;
            for (auto [j, x]: g[i]) {
                Q.push({d + x, j, i});
            }
        }
        return pair{dis, his};
    };
    auto [d1, h1] = dijkstra(s, g);
    auto [d2, h2] = dijkstra(t, rg);
    i64 dd = d1[t];
    for (auto [u, v, w]: adjs) {
        if (d1[u] + w + d2[v] == dd) {
            if (h1[u] * h2[v] == h1[t]) {
                YES();
            } else {
                if (w == 1) NO();
                else cout << "CAN " << 1 << endl;
            }
        } else {
            i64 ans = w - (dd - 1 - d1[u] - d2[v]);
            if (ans >= w) NO();
            else cout << "CAN " << ans << endl;
        }
    }
}

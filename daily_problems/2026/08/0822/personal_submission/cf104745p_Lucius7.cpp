#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> adj(n);
    std::vector<int> in(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        in[y]++;
    }

    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    std::vector<int> ord;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        ord.push_back(x);
        for (auto y : adj[x]) {
            if (--in[y] == 0) {
                q.push(y);
            }
        }
    }

    std::vector<int> f(n);
    for (int i = ord.size() - 1; i >= 0; i--) {
        int x = ord[i];
        for (auto y : adj[x]) {
            f[x] = std::max(f[x], f[y] + 1);
        }
    }

    std::vector<std::pair<int, int>> prs(k);
    for (int i = 0; i < k; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        prs[i] = {x, y};
    }

    int w, s;
    std::cin >> w >> s;
    s--;

    if (f[s] >= w) {
        std::cout << 0 << "\n";
        return;
    }

    constexpr int inf = 1E15;
    auto dis = [&](int S) {
        std::vector<int> dis(n, -inf);
        dis[S] = 0;
        for (auto x : ord) {
            if (dis[x] == -inf) {
                continue;
            }
            for (auto y : adj[x]) {
                dis[y] = std::max(dis[y], dis[x] + 1);
            }
        }
        return dis;
    };

    auto ds = dis(s);
    std::vector<int> bfr(k), aft(k);  // bfr[i]: s -> i.[start]; aft[i]: i.[end] -> any
    // std::vector trans(k, std::vector<int>(k, -inf)); // trans[i][j]: i.[end] -> j.[start]
    std::vector pp(32, std::vector(k, std::vector<int>(k, -inf))); // pp[i][x][y]: 2^i steps, x.start -> y.start
    for (int i = 0; i < k; i++) {
        bfr[i] = ds[prs[i].first];
        auto di = dis(prs[i].second);
        for (int j = 0; j < k; j++) {
            if (di[prs[j].first] != -inf) {
                pp[0][i][j] = di[prs[j].first] + 1;
            }
        }
        aft[i] = f[prs[i].second];
    }

    for (int i = 1; i < 32; i++) {
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                for (int r = 0; r < k; r++) {
                    if (pp[i - 1][x][r] != -inf && pp[i - 1][r][y] != -inf) {
                        pp[i][x][y] = std::max(pp[i][x][y], pp[i - 1][x][r] + pp[i - 1][r][y]);
                    }
                }
            }
        }
    }


    for (int i = 0; i < k; i++) {
        if (bfr[i] + 1 + aft[i] >= w) {
            std::cout << 1 << "\n";
            return;
        }
    }

    auto cur = bfr;
    int ans = 1;
    for (int i = 31; i >= 0; i--) {
        std::vector<int> nxt(k, -inf);
        for (int x = 0; x < k; x++) {
            if (cur[x] == -inf) {
                continue;
            }
            for (int y = 0; y < k; y++) {
                nxt[y] = std::max(nxt[y], cur[x] + pp[i][x][y]);
            }
        }

        int mx = -1;
        for (int i = 0; i < k; i++) {
            if (nxt[i] != -inf) {
                mx = std::max(mx, nxt[i] + aft[i] + 1);
            }
        }
        
        if (mx < w) {
            ans += (1LL << i);
            cur = std::move(nxt);
        }
    }
    std::cout << ans + 1 << "\n";

    
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

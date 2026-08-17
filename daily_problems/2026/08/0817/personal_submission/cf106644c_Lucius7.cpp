#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    std::vector<bool> vis1(n);
    std::queue<int> q;
    int cur = 0;
    std::vector bel(2, std::vector<int>(n));
    auto bfs1 = [&](int S) {
        q.push(S);
        vis1[S] = true;
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            for (auto y : adj[x]) {
                if (!vis1[y]) {
                    q.push(y);
                    vis1[y] = true;
                    bel[1][y] = bel[1][x];
                }
            }
        }
    };

    for (int i = 0; i < n; i++) {
        if (!vis1[i]) {
            bel[1][i] = cur;
            bfs1(i);
            cur++;
        }
    }

    std::set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(i);
    }
    std::queue<int> q0;
    auto bfs0 = [&](int S) {
        q0.push(S);
        st.erase(S);

        while (!q0.empty()) {
            auto x = q0.front();
            q0.pop();
            auto nst = st;
            for (auto y : adj[x]) {
                nst.erase(y);
            }
            for (auto y : nst) {
                bel[0][y] = bel[0][x];
                q0.push(y);
                st.erase(y);
            }
        }
    };

    cur = 0;
    for (int i = 0; i < n; i++) {
        if (st.find(i) != st.end()) {
            bel[0][i] = cur;
            bfs0(i);
            cur++;
        }
    }

    std::map<std::pair<int, int>, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[{bel[0][i], bel[1][i]}]++;
    }

    int ans = 0;
    for (auto [_, x] : cnt) {
        ans += x * (x - 1) / 2;
    }
    std::cout << ans << "\n";

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

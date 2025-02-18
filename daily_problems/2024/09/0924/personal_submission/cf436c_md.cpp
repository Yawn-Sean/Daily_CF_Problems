// 0924
#include <bits/stdc++.h>

struct DSU {
private:
    std::vector<int> f;
    std::vector<int> siz;
public:    
    explicit DSU(int n) noexcept : f(n), siz(n, 1) {
         std::iota(std::begin(f), std::end(f), 0); 
    }
    int leader (int x) noexcept {
        while (x != f[x]) {
            f[x] = f[f[x]];
            x = f[x];
        }
        return x;
    }
    bool merge(int x, int y) noexcept {
        x = leader(x);
        y = leader(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    bool same(int x, int y) noexcept { return leader(x) == leader(y); }
    int size(int x) noexcept { return siz[leader(x)]; }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k, w;
    std::cin >> n >> m >> k >> w;
    std::vector<std::string> values(k);

    for (int i = 0; i < k; ++i) {
        std::string s;
        for (int j = 0; j < n; ++j) {
            std::cin >> s;
            values[i] += s;
        }
    }

    std::vector<std::tuple<int, int, int>> edges;
    for (int i = 0; i < k; ++i) {
        edges.emplace_back(m * n, i, k);
        for (int j = i + 1; j < k; ++j) {
            int diff = 0;
            for (int l = 0; l < n * m; ++l) {
                if (values[i][l] != values[j][l]) {
                    diff += w;
                }
            }
            edges.emplace_back(diff, i, j);
        }
    }

    DSU dsu(k + 1);
    std::sort(std::begin(edges), std::end(edges));

    int tot_cost = 0;
    std::vector<std::vector<int>> paths(k + 1);
    for (auto[cost, u, v] : edges) {
        if (dsu.merge(u, v)) {
            paths[u].push_back(v);
            paths[v].push_back(u);
            tot_cost += cost;
        }
    }

    std::cout << tot_cost << '\n';
    
    std::stack<std::pair<int, int>> outs;
    outs.push({k, -1});
    while (!empty(outs)) {
        auto[u, p] = outs.top();
        outs.pop();
        for (auto v : paths[u]) {
            if (v == p) {
                continue;
            }
            std::cout << v + 1 << ' ' << (u == k ? 0 : u + 1) << '\n';
            outs.push({v, u});
        }
    }

    return 0;
}
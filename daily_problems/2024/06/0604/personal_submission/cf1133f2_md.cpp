// 0604
#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;

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

    int n, m, d;
    std::cin >> n >> m >> d;
    std::vector<pii> edges;
    std::vector<int> edge_to_0;
    edges.reserve(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        edges.emplace_back(u, v);
        if (u == 0 || v == 0) {
            edge_to_0.push_back(i);
        }
    }

    // Inadequate edges make degree[0] = d
    if (size(edge_to_0) < d) {
        std::cout << "NO\n";
        return 0;
    } 
      
    DSU dsu_exclude_0(n);
    for (auto[u, v] : edges) {
        if (u > 0 && v > 0) {
            dsu_exclude_0.merge(u, v);
        }
    }

    std::set<int> components;
    for (int i = 1; i < n; ++i) {
        components.insert(dsu_exclude_0.leader(i));
    }

    // Too many unlinked components to build a spanning tree
    if (size(components) > d) {
        std::cout << "NO\n";
        return 0;
    }

    DSU dsu_tree{n};
    std::vector<pii> tree_edges;
    tree_edges.reserve(d);
    int cnt {0};
    for (auto[u, v] : edges) {
        if (v == 0 || u == 0) {
            auto lead_u = (u == 0) ? v : u;
            auto dsu_lead_u = dsu_exclude_0.leader(lead_u);
            if (lead_u > 0 && components.contains(dsu_lead_u)) {
                if (dsu_tree.merge(lead_u, 0)) {
                    tree_edges.emplace_back(lead_u, 0);
                    ++cnt;
                }
                components.erase(dsu_lead_u);
            }
        }
    }

    for (auto idx : edge_to_0) {
        if (cnt == d) {
            break;
        }
        auto[u, v] = edges[idx];
        if (dsu_tree.merge(u, v)) {
            tree_edges.emplace_back(u, v);
            ++cnt;
        }
    }

    for (auto [u, v] : edges) {
        if (u > 0 && v > 0) {
            if (dsu_tree.merge(u, v)) {
                tree_edges.emplace_back(u, v);
            }
        }
    }

    std::cout << "YES\n";
    for (auto[u, v] : tree_edges) {
        std::cout << u + 1 << ' ' << v + 1 << '\n';
    }
    
    return 0;
}
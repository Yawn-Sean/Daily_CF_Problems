// 0717
#include <bits/stdc++.h>

struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 0) { 
        // N.B. make sure only the first n elements are initialized with 1
        siz.assign(n / 2, 1);    
        std::iota(f.begin(), f.end(), 0); 
    }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        siz[y] = 0;
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> same_data, diff_data;
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::string c;
        std::cin >> x >> y >> c;
        --x; --y;
        if (c == "imposter") {
            diff_data.emplace_back(x, y);
        } else {
            same_data.emplace_back(x, y);
        }
    }

    DSU graph(n * 2);
    for (auto[x, y] : same_data) {
        graph.merge(x, y);
        graph.merge(x + n, y + n);
    }

    for (auto[x, y] : diff_data) {
        graph.merge(x, y + n);
        graph.merge(x + n, y);
    }

    std::vector<int> group_siz(n * 2);
    for (int i = 0; i < n; ++i) {
        if (graph.same(i, i + n)) {
            std::cout << "-1\n";
            return;
        }
        group_siz[graph.leader(i)] = graph.size(i);
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += std::max(group_siz[graph.leader(i)], group_siz[graph.leader(i + n)]);
        group_siz[graph.leader(i)] = group_siz[graph.leader(i + n)] = 0;
    }
    std::cout << ret << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
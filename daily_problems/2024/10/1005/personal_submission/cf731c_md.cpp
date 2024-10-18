// 1005
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

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> colors(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> colors[i];
        colors[i]--;
    }

    DSU dsu(n);

    for (int i = 0; i < m; ++i) {
        int l, r;
        std::cin >> l >> r;
        --l; --r;
        dsu.merge(l, r);
    }

    std::vector<std::map<int, int>> group_colors(n);
    for (int i = 0; i < n; ++i) {
        group_colors[dsu.leader(i)][colors[i]]++;
    }

    int keep = 0;
    for (const auto& colors : group_colors) {
        int max_color = 0;
        for (auto [color, cnt] : colors) {
            max_color = std::max(max_color, cnt);
        }
        keep += max_color;
    }

    std::cout << n - keep << '\n';

    return 0;
}
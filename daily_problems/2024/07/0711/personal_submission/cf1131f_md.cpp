// 0712
#include <bits/stdc++.h>

struct DSU {
private:
    std::vector<int> f;
    std::vector<int> siz;
    std::vector<std::list<int>> g;
public:    
    explicit DSU(int n) noexcept : f(n), siz(n, 1), g(n) {
         std::iota(std::begin(f), std::end(f), 0); 
         for (int i = 0; i < n; ++i) {
            g[i].push_back(i);
         }
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
        g[x].splice(end(g[x]), g[y]);
        return true;
    }
    std::list<int> &get(int x) noexcept {
        return g[leader(x)];
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    DSU dsu(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        std::cin >> x >> y;
        dsu.merge(x - 1, y - 1);
    }

    auto& l = dsu.get(0);
    for (auto x : l) {
        std::cout << x + 1 << ' ';
    }
    return 0;
}
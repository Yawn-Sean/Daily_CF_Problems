// 0606
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

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::tuple<int, int, int>> mines;
    std::map<int, std::vector<int>> x_mines, y_mines;
    for (int i = 0; i < n; ++i) {
        int x, y, expt;
        std::cin >> x >> y >> expt;
        mines.emplace_back(x, y, expt);
        x_mines[x].push_back(i);
        y_mines[y].push_back(i);
    }

    DSU dsu(n);
    for (int i = 0; i < n; ++i) {
        auto[x, y, expt] = mines[i];
        if (!x_mines.contains(x)) {
            continue;
        }

        auto& x_mine_idx = x_mines[x];
        std::sort(begin(x_mine_idx), end(x_mine_idx), [&](int a, int b) {
            return std::abs(std::get<1>(mines[a]) - y) < std::abs(std::get<1>(mines[b]) - y);
        });

        for (auto idx : x_mine_idx) {
            if (std::abs(std::get<1>(mines[idx]) - y) <= k) {
                dsu.merge(i, idx);
            } else {
                break;
            }
        }

        auto& y_mine_idx = y_mines[y];
        std::sort(begin(y_mine_idx), end(y_mine_idx), [&](int a, int b) {
            return std::abs(std::get<0>(mines[a]) - x) < std::abs(std::get<0>(mines[b]) - x);
        });

        for (auto idx : y_mine_idx) {
            if (std::abs(std::get<0>(mines[idx]) - x) <= k) {
                dsu.merge(i, idx);
            } else {
                break;
            }
        }
    }

    std::map<int, int> min_explode_time;
    for (int i = 0; i < n; ++i) {
        if (!min_explode_time.contains(dsu.leader(i))) {
            min_explode_time[dsu.leader(i)] = std::get<2>(mines[i]);
        } else {
            min_explode_time[dsu.leader(i)] = std::min(min_explode_time[dsu.leader(i)], std::get<2>(mines[i]));
        }
    }

    std::vector<int> min_time_val;
    for (auto[_, val] : min_explode_time) {
        min_time_val.push_back(val);
    }
    
    std::sort(begin(min_time_val), end(min_time_val), std::greater<int>());
    
    int time_size = ssize(min_time_val);
    int ret = time_size - 1;
    for (int i = 0; i < time_size; ++i) {
        ret = std::min(ret, std::max(min_time_val[i], i - 1));
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
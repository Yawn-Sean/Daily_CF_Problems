#include <bits/stdc++.h>
// #include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr double eps = 1e-9;

struct DSU {
    std::vector<int> p;
    int n;
    DSU(int _n) : p(_n, -1), n(_n) {}
    
    void init () {
        p.assign(n, -1);
    }

    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (p[px] > p[py]) std::swap(px, py);
        p[px] += p[py], p[py] = px;
    }

    int size(int x) {
        return -p[find(x)];
    }
};

constexpr int dir[5] = { -1, 0, 1, 0, -1 };

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> g(n);
    for (int i = 0; i < n; ++ i) 
        std::cin >> g[i];

    if (n == 1 && m == 1) {
        std::cout << "Yes";
        return;
    }

    int stx, sty;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j) 
            if (g[i][j] == 'S') {
                stx = i, sty = j;
                break;
            }

    auto pos = [&m](int i, int j) {
        return i * m + j;
    };

    std::vector<std::pair<int, int>> st, vis(n * m, { inf32, inf32 });

    st.emplace_back(stx, sty);
    vis[pos(stx, sty)] = { stx, sty };

    while (st.size()) {
        auto [x, y] = st.back();
        st.pop_back();

        for (int k = 0; k < 4; ++ k) {
            auto [nx, ny] = std::pair(x + dir[k], y + dir[k + 1]);
            auto [nnx, nny] = std::pair(((nx % n) + n) % n, ((ny % m) + m) % m);
            // assert(nnx >= 0 && nnx < n);
            // assert(nny >= 0 && nny < m);
            if (g[nnx][nny] != '#') {
                if (vis[pos(nnx, nny)].first < inf32) {
                    if(vis[pos(nnx, nny)] != std::pair(nx, ny)) {
                        std::cout << "Yes";
                        return;
                    }
                }
                else {
                    vis[pos(nnx, nny)] = { nx, ny };
                    st.emplace_back(nx, ny);
                }
            }
        }
    }

    std::cout << "No";
}

auto FIO = []{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
} ();

int main() {
    #ifdef DEBUG
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif     

    int t = 1;
    // std::cin >> t;
    while (t --)
        solve();

    return 0;
}
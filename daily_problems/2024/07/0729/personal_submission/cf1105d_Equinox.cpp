#include <bits/stdc++.h>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

void solve() {
    int n, m, p;
    std::cin >> n >> m >> p;
    std::vector<std::queue<std::pair<int, int>>> q(p);
    std::vector<int> s(p);
    std::set<int> st;
    for (int i = 0; i < p; ++ i) std::cin >> s[i], st.insert(i);
    
    std::vector<std::string> g(n);
    std::vector<int> ans(p);
    
    for (int i = 0; i < n; ++ i) { 
        std::cin >> g[i];
        for (int j = 0; j < m; ++ j)
            if (std::isdigit(g[i][j])) {
                q[(g[i][j] ^ 48) - 1].emplace(i, j);
                ++ ans[(g[i][j] ^ 48) - 1];
            }
    }

    constexpr int dir[] = { -1, 0, 1, 0, -1 };

    while (st.size()) {
        std::vector<int> buf;
        for (int t : st) {
            int c = s[t];
            int change = 0;

            while (c -- && q[t].size()) {
                for (int i = 0, ed = q[t].size(); i < ed; ++ i) {
                    auto [x, y] = q[t].front();
                    q[t].pop();
                    for (int j = 0; j < 4; ++ j) {
                        int nx = x + dir[j], ny = y + dir[j + 1];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (g[nx][ny] != '.') continue;
                        g[nx][ny] = t + '1';
                        q[t].emplace(nx, ny);  
                        ++ ans[t];
                        change = 1;
                    }
                }
            }
            if (!change) buf.push_back(t);
        }
        for (int t : buf) st.erase(t);
    }
    for (int x : ans) std::cout << x << ' ';
}


auto init_ = []{
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
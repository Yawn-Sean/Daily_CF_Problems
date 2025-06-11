#include <bits/stdc++.h>
// #include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr double eps = 1E-9;
constexpr int P = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;

    if (m >= 1LL * n * (n - 1) / 2) {
        std::cout << "NO\n";
        return;
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 0, a, b; i < m; ++ i) {
        std::cin >> a >> b;
        -- a, -- b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int j, k;

    for (int i = 0; i < n; ++ i) {
        if (adj[i].size() == n - 1) continue;

        j = i;
        std::vector<bool> vis(n);

        for (int x : adj[i])
            vis[x] = true;

        for (int x = 0; x < n; ++ x)
            if (x != i && !vis[x]) {
                k = x;
                break;
            }
        break;
    }

    std::cout << "YES\n";

    std::vector<int> a(n);
    a[j] = n - 1, a[k] = n;

    for (int i = 0, cur = 1; i < n; ++ i) {
        if (i == j || i == k) continue;
        a[i] = cur ++;
    }

    for (int i = 0; i < n; ++ i)
        std::cout << a[i] << " \n"[i + 1 == n];

    a[k] = n - 1;

    for (int i = 0; i < n; ++ i)
        std::cout << a[i] << " \n"[i + 1 == n];
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
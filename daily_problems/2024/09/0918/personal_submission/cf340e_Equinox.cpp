#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1E9 + 7;;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), vis(n + 1);

    int lim = 0;;

    for (int i = 1; i <= n; ++ i) {
        std::cin >> a[i];
        if (~a[i])
            vis[a[i]] = 1;
        else
            ++ lim;
    }

    int unlim = 0;
    for (int i = 1; i <= n; ++ i)
        if (a[i] == -1 && vis[i])
            ++ unlim, -- lim;


    std::vector<std::vector<int>> f(lim + 1, std::vector<int>(unlim + 1));


    f[0][0] = 1;
    for (int i = 2; i <= lim; ++ i)
        f[i][0] = (i - 1LL) * (f[i - 1][0] + f[i - 2][0]) % P;
    for (int j = 1; j <= unlim; ++ j)
        f[0][j] = 1LL * f[0][j - 1] * j % P;
    
    for (int i = 1; i <= lim; ++ i)
        for (int j = 1; j <= unlim; ++ j) 
            f[i][j] = (1LL * i * f[i - 1][j] + 1LL * j * f[i][j - 1]) % P;

    std::cout << f[lim][unlim] << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
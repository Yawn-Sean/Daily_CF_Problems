#include <bits/stdc++.h>
#define sc scanf
using i64 = long long;
using PII = std::pair<int, int>;
constexpr int inf = 1e9 + 7;

/*
    合法矩阵: 任意相邻行列相同和相反

    我们可以进行 k 次 操作

    若 k < n，则若存在合法矩阵，一定有一行不用动
    我们枚举行,O(n * n * m)
    
    若 k > n，我们直接考虑第一列每个位置变不变
    2^n * n * m
*/

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    int res = inf;
    if (n > k) {
        std::vector<std::bitset<100>> g(n);
        for (int i = 0; i < n; ++ i)
            for (int j = 0, a; j < m; ++ j)
                std::cin >> a, g[i][j] = a;
        for (int i = 0; i < n; ++ i) {
            int s = 0;
            for (int j = 0; j < n; ++ j) {
                if (i == j) continue;
                s += std::min((g[i] ^ g[j]).count(), ((~g[i]) ^ g[j]).count() - (100 - m));
            }
            if (s <= k)
                res = std::min(res, s);
        }
        
    }
    else {
        std::vector<std::bitset<100>> g(m);
        for (int i = 0; i < n; ++ i)
            for (int j = 0, a; j < m; ++ j)
                std::cin >> a, g[j][i] = a;
        for (int i = 0, ed = 1 << n; i < ed; ++ i) {
            std::bitset<100> t = std::bitset<100>(i);
            int s = (t ^ g[0]).count();
            
            for (int j = 1; j < m; ++ j) {
                s += std::min((t ^ g[j]).count(), ((~t) ^ g[j]).count() - (100 - n));
            }
            if (s <= k)
                res = std::min(res, s);
        }
    }
    if (res < inf) std::cout << res;
    else std::cout << -1;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}
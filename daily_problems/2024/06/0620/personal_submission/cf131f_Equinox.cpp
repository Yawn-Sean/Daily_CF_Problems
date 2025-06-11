#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
const int inf = 1e8 + 7, P = 1e9 + 7;

/*
预处理star

枚举高 -> 和 >= k 的子数组个数？
two pointers
*/


void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::string> g(n);
    for (int i = 0; i < n; i ++ ) std::cin >> g[i];

    std::vector<std::vector<int>> f(n, std::vector<int> (m));
    std::array<int, 5> dir { 1, 0, -1, 0, 1 };
    for (int i = 1; i + 1 < n; i ++ )
        for (int j = 1; j + 1 < m; j ++ ) {
            if (g[i][j] == '1') {
                bool flag = true;
                for (int k = 0; k < 4; k ++ )
                    if (g[i + dir[k]][j + dir[k + 1]] == '0')
                        flag = false;
                f[i][j] = flag; 
            }
        }

    std::vector<std::vector<int>> pre(f);
    for (int i = 1; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            pre[i][j] += pre[i - 1][j];

    i64 res = 0;
    for (int lo = 0; lo < n; lo ++ ) {
        for (int hi = lo + 2; hi < n; hi ++ ) {
            int l = 1, r = 1, cur = 0;
            while (l + 1 < m) {
                while (r + 1 < m && cur < k)
                    cur += pre[hi - 1][r] - pre[lo][r], ++ r;
                if (cur < k) break;
                res += (m - r);
                cur -= pre[hi - 1][l] - pre[lo][l];
                ++ l;
            }
        }
    }
    std::cout << res;
}

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}
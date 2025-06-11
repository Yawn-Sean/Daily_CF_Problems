#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
using PIII = std::pair<int, PII>;
const int inf = 1e9 + 7, P = 1e9 + 7;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::vector<std::vector<int>> lcp(n + 2, std::vector<int>(n + 2)), f(lcp);
    std::vector<std::vector<i64>> sum(n + 1, std::vector<i64>(n + 1));

    for(int i = n; i; -- i) {
        f[i][1] = 1;
        for(int j = n; j; -- j)
            if(s[i - 1] == s[j - 1])
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
    }
        
    auto check = [&](int i, int j) -> bool {
        if (lcp[i][j] >= j - i) return false;
        return s[i + lcp[i][j] - 1] < s[j + lcp[i][j] - 1];
    };

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= i; ++ j) {
            if (s[j - 1] ^ 48) {
                int k = std::max(2 * j - i, 1);
                f[i][j] = (((sum[j - 1][j - 1] - sum[j - 1][k - 1] + f[i][j]) % P) + P) % P;
                -- k; // 等长的情况
                if (k && check(k, j))
                    f[i][j] = (f[i][j] + f[j - 1][k]) % P;
            }
            sum[i][j] = (f[i][j] + sum[i][j - 1]) % P;
        }
    }
    
    int res = 0;

    for (int i = 1; i <= n; ++ i)
        res = (1LL * res + f[n][i]) % P;

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
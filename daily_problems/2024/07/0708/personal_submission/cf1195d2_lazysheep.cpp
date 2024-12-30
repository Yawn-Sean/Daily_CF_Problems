#include <bits/stdc++.h>
 
using i64 = long long;
 
const int MOD = 998244353;
 
int power(int a, i64 b, int p) {
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}
 
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    std::vector<int> c(11);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        c[(int) a[i].length()]++;
    }
    i64 ans = 0;
    for (auto &x : a) {
        int m = x.length();
        for (int i = 0; i < m; i++) {
            for (int j = 1; j <= 10; j++) {
                if ((i + 1) <= j) {
                    ans = (ans + (i64) (x[m - 1 - i] - '0') * power(10, 2 * i + 1, MOD) % MOD * c[j] % MOD) % MOD;
                    ans = (ans + (i64) (x[m - 1 - i] - '0') * power(10, 2 * i, MOD) % MOD * c[j] % MOD) % MOD;
                } else {
                    ans = (ans + (i64) (x[m - 1 - i] - '0') * power(10, (2 * j + (i - j)), MOD) % MOD * c[j] * 2 % MOD) % MOD;
                }
            }
        }
    }
 
    std::cout << ans;
 
    return 0;
}

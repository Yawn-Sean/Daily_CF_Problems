#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128_t;
using u64 = unsigned long long;
#define MultiCases()   int t = 1; std::cin >> t; while(t--) 
#define SingleCase()   int t = 1; while(t--) 
int dp[1201][601];

void solve() {
    int n;
    memset(dp, -1, sizeof(dp));
    std::cin >> n;
    std::vector<int> l(n), r(n);
    for(int i = 0; i < n; i++) {
        std::cin >> l[i] >> r[i];
    }
    std::function<int(int, int, bool)> f = [&](int L, int i, bool A = 0)-> int {
        if(i >= n) return 0;
        if(dp[L][i] != -1) return dp[L][i];
        for(int j = l[i]; j <= r[i]; j++) {
            if(L < j + 1) break;
            int s1 = 0;
            if(j == 1) dp[2][i] = s1 = 1;
            else  {
                int s2 = f(j - 1, i + 1, A);
                if(s2 > 0) s1 = 1;
                else {
                    continue;
                }
            }
            if(L - j - 1 > 0 && s1 > 0) {
                int s2 = f(L - j - 1, i + (j + 1) / 2, A);
                if(s2 > 0) {
                    s1 = (s1 > 0) && (s2 > 0);
                } else {
                    continue;
                }
            }
            if(s1) {
                return dp[L][i] = s1;
            }
        }
        return dp[L][i] = 0;
    };

    int ans = f(2 * n, 0, 0);
    if(ans <= 0) {
        std::cout << "IMPOSSIBLE\n";
    } else {
        std::function<std::string(int, int)> get = [&](int L, int i)-> std::string {
            if(L == 0) return "";
            for(int j = l[i]; j <= r[i]; j++) {
                if(L < j + 1) break;
                if( (j - 1 == 0 || dp[j - 1][i + 1] == 1) && ( L - j - 1 == 0 || dp[L - j - 1][i + (j + 1) / 2] == 1)) {
                    return "(" + get(j - 1, i + 1) + ")" + get(L - j - 1, i + (j + 1) / 2);
                }
            }
            return "";
        };
        std::cout << get(2 * n, 0) << "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    SingleCase()
        solve();
    return 0;
}

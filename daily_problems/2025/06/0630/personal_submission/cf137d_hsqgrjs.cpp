#include <bits/stdc++.h>
using i64 = long long;
// using i128 = __int128_t;
using u64 = unsigned long long;
int dp[501][501] = {0};
int A[501][501] = {0};
int before[501][501] = {0};
void solve() {
    std::string s;
    int k;
    std::cin >> s >> k;
    int n = s.size();
    for(int i = 0; i < k; i++) {
        for(int j = 0; j <= n; j++) {
            dp[i][j] = 1E9;
        }
    }
    for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) A[i][j] = 1E9;
    dp[0][0] = 0;

    auto f = [&](int l, int r) {
        int cnt = 0;
        if(A[l][r] != 1E9) return A[l][r];
        for(int i = 0; i < r - l - 1 - i; i++) {
            cnt += (s[i + l] != s[r - 1 - i]);
        }
        return A[l][r] = cnt;
    };

    for(int i = 1; i <= n; i++) {
        dp[0][i] = f(0, i);
        before[0][i] = 0;
    }
    for(int i = 1; i < k; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int u = j; u <= n; u++) {
                int t = f(j - 1, u);
                if(dp[i - 1][j - 1] + t < dp[i][u]) {
                    dp[i][u] = dp[i - 1][j - 1] + t;
                    before[i][u] = j - 1;
                }
            }
        }
    }

    int mi = 1E9, p = -1;
     for(int i = 0; i < k; i++) {
        if(mi > dp[i][n]) {
            mi = dp[i][n];
            p = i;
        }
    }
    std::cout << mi << "\n";

    auto get = [&](int l, int r) {
        std::string ans = s.substr(l - 1, r - l + 1);
        for(int i = 0; i < ans.size() - 1 - i; i++) {
            if(ans[i] != ans[ans.size() - 1 - i]) ans[i] = ans[ans.size() - 1 - i];
        }
        return ans;
    };
    std::vector<std::string> ans;
    int q = n;
    while(q > 0 && p >= 0) {
        int _r = q, _l = before[p][q] + 1;
        p--;
        q = _l - 1;
        ans.push_back(get(_l, _r));
    }
    for(int i = ans.size() - 1; i >= 0; i--) {
        std::cout << ans[i] <<  "+\n"[i == 0];
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;  
    // std::cin >> t;
    while (t--)
        solve();
    return 0;
}

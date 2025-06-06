#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128_t;
using u64 = unsigned long long;

void solve() {
    int a, b, n;
    std::cin >> a >> b >> n;
    // (n, 1) 0
    // 2 : n1 = sqrt n , (n1, 2) 0 <- (n1, 0), 1, 
    // (n2, 3) = sqrt n, 1 / 3, 0, (n2, 2) , 1
    std::vector<int> c;
    for(int i = std::max(2, b); i <= 30; i++) {
        i64 t1 = pow(n, 1.0 / i);
        if(pow(t1, 1LL * i) == n) {
            t1--;
        }
        c.push_back(t1);
    }
    
    int dp[100009];
    memset(dp, -1, sizeof(dp));
    for(int i = c.size() - 1; i >= 0; i--) {
        for(int j = c[i]; j > 1; j--) {
            if(i + 1 >= c.size()) {
                dp[j] = ((j ^ c[i]) & 1);
            } else {
                if(j > c[i + 1]) {
                    dp[j] = ((j ^ c[i]) & 1);
                } else {
                    dp[j] = ((1 ^ dp[j])) || (!dp[j + 1]);
                }
            }
        }
        if(dp[2] == 0 || dp[1] == 0) {
            dp[1] = 1;
        } else if(dp[2] == 1 && dp[1] == 1) {
            dp[1] = 0;
        } else {
            dp[1] = -1;
        }
    }
    if(b == 1) {
        for(int i = 100000; i > 1; i--) {
            if(i >= n) {

            }
            else if(i > c[0]) {
                dp[i] = ((i ^ (n - 1)) & 1);
            } else {
                    dp[i] = ((1 ^ dp[i])) || (1 ^ dp[i + 1]);

            }
        }
        if((dp[2] == 0) || (dp[1] == 0)) {
            dp[1] = 1;
        } else if(dp[2] == 1 && dp[1] == 1) {
            dp[1] = 0;
        } else {
            dp[1] = -1;
        }
    }
    if(a == 1 && (1 << b) >= n && (dp[1] == -1)) {
        std::cout << "Missing\n";
        return;
    } 

    i64 t1 = 1;
    for(int i = 1; i <= b; i++) {
        t1 = t1 * a;
        if(t1 >= n) {
            std::cout << "Stas\n";
            return;
        }
    }

    if(b >= 2) {
        std::cout << ((dp[a] == 1) ? "Masha" : "Stas") << "\n";
    } else {
            std::cout << ((dp[a] == 1) ? "Masha" : "Stas") << "\n";

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

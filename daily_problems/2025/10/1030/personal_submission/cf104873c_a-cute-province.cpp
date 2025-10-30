#include <iostream>
#include <vector>
#include <cmath>

const int MOD = 998244353;
const int N_MAX = 200005;

int dp[N_MAX];
int ans[N_MAX];

void precompute() {
    dp[0] = 1;
    int limit = (int)(sqrt(N_MAX));

    for (int k = 1; k <= limit; ++k) {
        
        for (int i = k; i < N_MAX; ++i) {
            dp[i] = (dp[i] + dp[i - k]) % MOD;
        }

      
        long long k_squared = (long long)k * k;
        for (long long n = k_squared; n < N_MAX; n += 2) {
            int m = (n - k_squared) / 2;
            ans[n] = (ans[n] + dp[m]) % MOD;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    precompute();

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::cout << ans[n] << "\n";
    }

    return 0;
}

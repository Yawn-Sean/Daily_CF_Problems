#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long a, b;
    int k;
    cin >> a >> b >> k;

    int block = 360360, inf = 1e6;
    long long ans = 0;

    if (a / block != b / block) {
        vector<int> dp(block + 1, inf);
        dp[0] = 0;

        for (int i = 1; i <= block; i ++) {
            dp[i] = min(dp[i], dp[i - 1] + 1);
            for (int j = 2; j <= k; j ++) {
                dp[i] = min(dp[i], dp[i - i % j] + 1);
            }
        }

        ans += dp[a % block];
        a -= a % block;

        long long v = (a - b) / block;
        ans += v * dp[block];
        a -= v * block;

        a --, ans ++;
    }

    a %= block;
    b %= block;

    {
        vector<int> dp(block, inf);
        dp[b] = 0;

        for (int i = b + 1; i <= a; i ++) {
            dp[i] = min(dp[i], dp[i - 1] + 1);
            for (int j = 2; j <= k; j ++) {
                dp[i] = min(dp[i], dp[i - i % j] + 1);
            }
        }

        ans += dp[a];
    }

    cout << ans;

    return 0;
}
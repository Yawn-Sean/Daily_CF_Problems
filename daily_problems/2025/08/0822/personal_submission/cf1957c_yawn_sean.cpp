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

    int mod = 1e9 + 7, M = 3e5;
    vector<int> dp(M + 1);
    dp[0] = 1, dp[1] = 1;

    for (int i = 2; i <= M; i ++)
        dp[i] = (2ll * (i - 1) * dp[i - 2] + dp[i - 1]) % mod;
    
    int t;
    cin >> t;

    while (t --) {
        int n, k;
        cin >> n >> k;

        while (k --) {
            int x, y;
            cin >> x >> y;

            if (x == y) n --;
            else n -= 2;
        }

        cout << dp[n] << '\n';
    }

    return 0;
}
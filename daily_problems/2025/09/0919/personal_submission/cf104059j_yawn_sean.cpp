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

    string s, pattern = "cdhs";
    cin >> s;

    int ans = 0;

    do {
        vector<int> dp(4, 0);
        for (auto &c: s) {
            for (int i = 0; i < 4; i ++)
                if (pattern[i] == c) dp[i] ++;
            dp[1] = max(dp[1], dp[0]);
            dp[2] = max(dp[2], dp[1]);
            dp[3] = max(dp[3], dp[2]);
        }
        ans = max(ans, dp[3]);
    } while (next_permutation(pattern.begin(), pattern.end()));

    cout << s.size() - ans;

    return 0;
}
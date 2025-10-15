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

    string s1, s2;
    cin >> s1 >> s2;

    int n1 = s1.size(), n2 = s2.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    int ans = 0;

    int mod = 1e9 + 7;
    
    auto add = [&] (int &x, int y) -> void {
        x += y;
        if (x >= mod) x -= mod;
    };
    
    for (int i = 0; i < n1; i ++) {
        dp[i][0] = 1;
        for (int j = 0; j < n2; j ++) {
            add(dp[i][j + 1], dp[i][j]);
            if (s1[i] == s2[j]) {
                add(dp[i + 1][j + 1], dp[i][j]);
                add(ans, dp[i][j]);
            }
        }
    }

    cout << ans;

    return 0;
}
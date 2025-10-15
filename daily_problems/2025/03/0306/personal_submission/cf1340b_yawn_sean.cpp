#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divide, I conquer!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> digits = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123};
    int n, k;
    cin >> n >> k;

    vector<int> strs(n);
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        for (int j = 0; j < 7; j ++) {
            strs[i] |= (s[j] - '0') << (6 - j);
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[n][0] = 1;

    for (int i = n - 1; i >= 0; i --) {
        for (int j = 0; j <= k; j ++) {
            if (dp[i + 1][j]) {
                for (int digit = 0; digit < 10; digit ++) {
                    if ((digits[digit] & strs[i]) == strs[i]) {
                        int nj = __popcount(digits[digit] ^ strs[i]);
                        if (j + nj <= k) dp[i][j + nj] = 1;
                    }
                }
            }
        }
    }

    if (!dp[0][k]) cout << -1;
    else {
        int cur = k;
        for (int i = 0; i < n; i ++) {
            for (int digit = 9; digit >= 0; digit --) {
                if ((digits[digit] & strs[i]) == strs[i]) {
                    int nj = __popcount(digits[digit] ^ strs[i]);
                    if (cur >= nj && dp[i + 1][cur - nj]) {
                        cur -= nj;
                        cout << digit;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
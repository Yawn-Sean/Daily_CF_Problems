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

    string s;
    cin >> s;

    int n = s.size();
    
    if (n == 1)
        cout << ((s[0] == '0' || s[0] == 'X' || s[0] == '_') ? 1 : 0);
    else {
        bool flg = false;
        for (auto &c: s) flg |= c == 'X';

        int ans = 0;
        for (int x = 0; x < 10 && (flg || x == 0); x ++) {
            vector<int> dp(25, 0), ndp(25, 0);
            dp[0] = 1;

            for (int i = 0; i < n; i ++) {
                if (s[i] != '_') {
                    int d = (s[i] != 'X' ? s[i] - '0' : x);
                    if (!(i == 0 && d == 0)) {
                        for (int mod = 0; mod < 25; mod ++) {
                            ndp[(mod * 10 + d) % 25] += dp[mod];
                        }
                    }
                }
                else {
                    for (int d = 0; d < 10; d ++) {
                        if (i == 0 && d == 0) continue;
                        for (int mod = 0; mod < 25; mod ++) {
                            ndp[(mod * 10 + d) % 25] += dp[mod];
                        }
                    }
                }
                for (int mod = 0; mod < 25; mod ++) {
                    dp[mod] = ndp[mod];
                    ndp[mod] = 0;
                }
            }
            ans += dp[0];
        }
        cout << ans;
    }

    return 0;
}
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

    string s1, s2;
    cin >> s1 >> s2;

    int n1 = s1.size(), n2 = s2.size();
    vector<int> ma_substr(n2), idxs(n2, -1);
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = n1 - 1; i >= 0; i --) {
        for (int j = n2 - 1; j >= 0; j --) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
                if (dp[i][j] > ma_substr[j]) {
                    ma_substr[j] = dp[i][j];
                    idxs[j] = i;
                }
            }
        }
    }

    reverse(s1.begin(), s1.end());

    for (int i = 0; i <= n1; i ++) {
        for (int j = 0; j <= n2; j ++) {
            dp[i][j] = 0;
        }
    }

    for (int i = n1 - 1; i >= 0; i --) {
        for (int j = n2 - 1; j >= 0; j --) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
                if (dp[i][j] > ma_substr[j]) {
                    ma_substr[j] = dp[i][j];
                    idxs[j] = ~(n1 - 1 - i);
                }
            }
        }
    }

    int pt = 0;
    vector<pair<int, int>> ops;

    while (pt < n2) {
        if (ma_substr[pt] == 0) return cout << -1, 0;
        if (idxs[pt] >= 0) ops.emplace_back(idxs[pt], idxs[pt] + ma_substr[pt] - 1);
        else ops.emplace_back(~idxs[pt], ~idxs[pt] - ma_substr[pt] + 1);
        pt += ma_substr[pt];
    }

    cout << ops.size() << '\n';
    for (auto &[x, y]: ops)
        cout << x + 1 << ' ' << y + 1 << '\n';

    return 0;
}
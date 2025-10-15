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
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    int k;

    cin >> s >> k;

    vector<vector<int>> grid(26, vector<int>(26, 0));

    int n;
    cin >> n;

    while (n --) {
        char c1, c2;
        int v;
        cin >> c1 >> c2 >> v;
        grid[c1 - 'a'][c2 - 'a'] = v;
    }

    int inf = 1e9;
    vector<vector<int>> dp(k + 1, vector<int>(26, -inf));
    vector<vector<int>> ndp(k + 1, vector<int>(26, -inf));

    for (int i = 0; i < 26; i ++) {
        if (s[0] - 'a' == i) dp[0][i] = 0;
        else if (k) dp[1][i] = 0;
    }

    for (int i = 1; i < s.size(); i ++) {
        for (int x = 0; x <= k; x ++) {
            for (int y = 0; y < 26; y ++) {
                for (int ny = 0; ny < 26; ny ++) {
                    int nx = (s[i] - 'a' == ny ? x : x + 1);
                    if (nx <= k)
                        ndp[nx][ny] = max(ndp[nx][ny], dp[x][y] + grid[y][ny]);
                }
            }
        }
        for (int x = 0; x <= k; x ++) {
            for (int y = 0; y < 26; y ++) {
                dp[x][y] = ndp[x][y];
                ndp[x][y] = -inf;
            }
        }
    }

    int ans = -inf;
    for (int i = 0; i <= k; i ++)
        ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
    
    cout << ans;

    return 0;
}
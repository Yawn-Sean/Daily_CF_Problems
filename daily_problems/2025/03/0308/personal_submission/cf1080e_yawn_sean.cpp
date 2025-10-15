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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &s: grid) 
        cin >> s;

    vector<long long> hsh(26, 1);
    hsh[1] = rng();
    hsh[1] = abs(hsh[1]) % 1000 + 1000;

    long long mod = rngl();
    mod = abs(mod);
    mod &= (1ll << 60) - 1;

    for (int i = 2; i < 26; i ++)
        hsh[i] = (__int128_t)1 * hsh[i - 1] * hsh[1] % mod;

    vector<long long> cur;
    auto f = [&] () -> int {
        vector<long long> tmp = {-1};
        for (auto x: cur) {
            tmp.emplace_back(x);
            tmp.emplace_back(-1);
        }

        int res = 0, k = tmp.size(), chosen_idx = 0;
        vector<int> wing(k, 0);

        for (int i = 0; i < k; i ++) {
            if (chosen_idx + wing[chosen_idx] >= i)
                wing[i] = min(chosen_idx + wing[chosen_idx] - i, wing[2 * chosen_idx - i]);
            
            while (i > wing[i] && i + 1 + wing[i] < k && tmp[i - wing[i] - 1] == tmp[i + wing[i] + 1]) wing[i] ++;

            res += (wing[i] + 1) / 2;
            if (i + wing[i] > chosen_idx + wing[chosen_idx])
                chosen_idx = i;
        }
        return res;
    };

    int ans = 0;

    for (int j1 = 0; j1 < m; j1 ++) {
        vector<int> msk(n, 0);
        vector<long long> tmp(n, 0);
        for (int j2 = j1; j2 < m; j2 ++) {
            for (int i = 0; i < n; i ++) {
                msk[i] ^= 1 << grid[i][j2] - 'a';
                tmp[i] += hsh[grid[i][j2] - 'a'];
                if (tmp[i] >= mod) tmp[i] -= mod;
            }
            
            for (int i = 0; i < n; i ++) {
                if ((msk[i] & -msk[i]) == msk[i])
                    cur.emplace_back(tmp[i]);
                else {
                    ans += f();
                    cur.clear();
                }
            }

            ans += f();
            cur.clear();
        }
    }
    cout << ans;

    return 0;
}
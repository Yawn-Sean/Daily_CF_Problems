#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> ls(m), rs(m);
    vector<int> cs(m);

    for (int i = 0; i < m; i ++)
        cin >> ls[i] >> rs[i] >> cs[i];
    
    vector<int> order(m);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return cs[i] > cs[j];});

    vector<long long> dp(n * m * 101, -1);
    vector<int> prev(n * m * 101, -1);

    auto f = [&] (int cnt, int idx, int num) -> int {
        return (cnt * m + idx) * 101 + num;
    };

    for (int i = 0; i < m; i ++) {
        int x = order[i];
        for (int num = 0; num <= rs[x] - ls[x]; num ++)
            dp[f(0, x, num)] = ls[x] + num;
        
        for (int j = 0; j < i; j ++) {
            int y = order[j];
            if (cs[x] == cs[y]) break;

            for (int cnt = 0; cnt < n - 1; cnt ++) {
                for (int num = 0; num <= rs[y] - ls[y]; num ++) {
                    int omsk = f(cnt, y, num);
                    if (dp[omsk] != -1) {
                        int nnum;
                        nnum = ls[y] + num - k - ls[x];
                        if (nnum >= 0 && nnum <= rs[x] - ls[x]) {
                            int msk = f(cnt + 1, x, nnum);
                            if (dp[omsk] + nnum + ls[x] > dp[msk]) {
                                dp[msk] = dp[omsk] + nnum + ls[x];
                                prev[msk] = omsk;
                            }
                        }
                        
                        if ((ls[y] + num) % k == 0) {
                            nnum = (ls[y] + num) / k - ls[x];
                            if (nnum >= 0 && nnum <= rs[x] - ls[x]) {
                                int msk = f(cnt + 1, x, nnum);
                                if (dp[omsk] + nnum + ls[x] > dp[msk]) {
                                    dp[msk] = dp[omsk] + nnum + ls[x];
                                    prev[msk] = omsk;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    long long ans = -1;
    int end_msk = -1;

    for (int idx = 0; idx < m; idx ++) {
        for (int num = 0; num <= rs[idx] - ls[idx]; num ++) {
            if (dp[f(n - 1, idx, num)] > ans) {
                ans = dp[f(n - 1, idx, num)];
                end_msk = f(n - 1, idx, num);
            }
        }
    }

    if (ans == -1) cout << "NO";
    else {
        cout << "YES\n";
        while (end_msk != -1) {
            int idx = end_msk / 101 % m, num = end_msk % 101;
            cout << idx + 1 << ' ' << ls[idx] + num << '\n';
            end_msk = prev[end_msk];
        }
    }

    return 0;
}
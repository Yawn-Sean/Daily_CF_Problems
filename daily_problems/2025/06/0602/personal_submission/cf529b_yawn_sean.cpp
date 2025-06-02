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

    int n, cur = 0;
    cin >> n;

    vector<int> ws(n), hs(n);
    for (int i = 0; i < n; i ++)    
        cin >> ws[i] >> hs[i], cur += ws[i];
    
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return hs[i] - ws[i] < hs[j] - ws[j];});

    int ans = 2e9;
    vector<bool> used(n, 0);

    for (int h = 1; h <= 1000; h ++) {
        bool flg = true;
        int cnt = 0, cur_w = cur;

        for (auto &i: order) {
            if (hs[i] > h) {
                if (ws[i] > h) {
                    flg = false;
                    break;
                }
                else {
                    used[i] = 1;
                    cnt ++;
                    cur_w += hs[i] - ws[i];
                }
            }
            else used[i] = 0;
        }

        if (cnt * 2 > n || !flg) continue;

        for (auto &i: order) {
            if (!used[i] && cnt < n / 2 && ws[i] <= h && hs[i] - ws[i] < 0) {
                cnt ++;
                cur_w += hs[i] - ws[i];
            }
        }

        ans = min(ans, cur_w * h);
    }

    cout << ans;

    return 0;
}
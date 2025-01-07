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

    int M = 2e6;
    vector<int> factor(M + 1);
    iota(factor.begin(), factor.end(), 0);

    for (int i = 2; i <= M; i ++) {
        if (factor[i] == i) {
            for (int j = i; j <= M; j += i) {
                factor[j] = i;
            }
        }
    }

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    vector<int> used(M + 1, 0);
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i ++) {
        int v;
        bool flg;

        v = nums[i];
        flg = true;

        while (v > 1) {
            int p = factor[v];
            while (v % p == 0) v /= p;
            if (used[p]) flg = false;
        }

        if (flg) {
            ans[i] = nums[i];
            v = nums[i];
            while (v > 1) {
                int p = factor[v];
                while (v % p == 0) v /= p;
                used[p] = 1;
            }
        }
        else {
            while (true) {
                nums[i] ++;
                v = nums[i];
                flg = true;
                while (v > 1) {
                    int p = factor[v];
                    while (v % p == 0) v /= p;
                    if (used[p]) flg = false;
                }
                if (flg) break;
            }
            
            ans[i] = nums[i];
            v = nums[i];
            while (v > 1) {
                int p = factor[v];
                while (v % p == 0) v /= p;
                used[p] = 1;
            }

            int pt = 2;

            for (int j = i + 1; j < n; j ++) {
                while (factor[pt] != pt || used[pt])
                    pt ++;
                ans[j] = pt;
                used[pt] = 1;
            }
            break;
        }
    }

    for (auto &v: ans) cout << v << ' ';

    return 0;
}
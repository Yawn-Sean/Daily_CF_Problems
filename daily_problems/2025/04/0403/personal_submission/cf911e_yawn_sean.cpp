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

    int n, k;
    cin >> n >> k;

    vector<int> stk = {n + 1};
    int cur = 1;

    vector<int> nums(k);

    for (int i = 0; i < k; i ++) {
        cin >> nums[i];
        stk.emplace_back(nums[i]);
        
        while (!stk.empty() && stk.back() == cur) {
            stk.pop_back();
            cur ++;
        }
    }

    stk.emplace_back(cur - 1);

    for (int i = stk.size() - 1; i >= 1; i --) {
        if (stk[i - 1] < stk[i])
            return cout << -1, 0;
        
        for (int j = stk[i - 1] - 1; j > stk[i]; j --)
            nums.emplace_back(j);
    }

    for (auto &v: nums) cout << v << ' ';

    return 0;
}
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

// Let's flow!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v;
    
    nums.emplace_back(0);
    for (int i = n; i > 0; i --)
        nums[i] -= nums[i - 1];
    
    vector<int> ls, rs;
    for (int i = 0; i <= n; i ++) {
        if (nums[i] >= 0) {
            for (int j = 0; j < nums[i]; j ++)
                ls.emplace_back(i + 1);
        }
        else {
            for (int j = 0; j < -nums[i]; j ++)
                rs.emplace_back(i);
        }
    }

    int k = ls.size();
    cout << k << '\n';

    for (int i = 0; i < k; i ++) {
        cout << ls[i] << ' ' << rs[i] << '\n';
    }

    return 0;
}
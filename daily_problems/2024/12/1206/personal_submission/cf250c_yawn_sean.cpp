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

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v;
    
    vector<int> tmp = {nums[0]};
    for (int i = 1; i < n; i ++) {
        if (nums[i] != tmp.back()) {
            tmp.emplace_back(nums[i]);
        }
    }

    vector<int> ans(k + 1);
    for (int i = 0; i < tmp.size(); i ++)
        ans[tmp[i]] += ((i == 0 || i + 1 == tmp.size() || tmp[i - 1] != tmp[i + 1]) ? 1 : 2);

    cout << max_element(ans.begin(), ans.end()) - ans.begin();

    return 0;
}
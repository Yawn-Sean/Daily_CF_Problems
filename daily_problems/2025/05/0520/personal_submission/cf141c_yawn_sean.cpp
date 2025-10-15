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

    int n;
    cin >> n;

    vector<string> names(n);
    vector<int> nums(n);

    for (int i = 0; i < n; i ++)
        cin >> names[i] >> nums[i];

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return nums[i] < nums[j];});

    vector<int> tmp, heights(n);
    int cur = n;

    for (auto &i: order) {
        heights[i] = cur;
        cur --;

        if (nums[i] > tmp.size()) return cout << -1, 0;

        vector<int> ntmp;
        for (int j = 0; j < nums[i]; j ++)
            ntmp.emplace_back(tmp[j]);
        
        ntmp.emplace_back(i);

        for (int j = nums[i]; j < tmp.size(); j ++)
            ntmp.emplace_back(tmp[j]);
        
        swap(tmp, ntmp);
    }

    for (auto &i: tmp)
        cout << names[i] << ' ' << heights[i] << '\n';

    return 0;
}
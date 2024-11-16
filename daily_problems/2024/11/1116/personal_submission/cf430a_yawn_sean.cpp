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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> nums(n), order(n), ans(n, 0);
    for (int i = 0; i < n; i ++)
        cin >> nums[i], order[i] = i;
    
    sort(order.begin(), order.end(), [&] (int i, int j) {return nums[i] < nums[j];});

    for (int i = 0; i < n; i += 2)
        ans[order[i]] = 1;
    
    for (auto &x: ans) cout << x << ' ';

    return 0;
}
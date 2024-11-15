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

    int n, tot = 0, ans = 0;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v, tot += v;
    
    string s;
    cin >> s;

    for (int i = n - 1; i >= 0; i --) {
        tot -= nums[i];
        if (s[i] == '1') {
            ans = max(ans, tot);
            tot += nums[i];
        }
    }

    cout << max(ans, tot);

    return 0;
}
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

    int n;
    cin >> n;

    vector<int> parent(n), values(n);
    for (int i = 0; i < n; i ++)
        cin >> parent[i] >> values[i], parent[i] --;
    
    vector<long long> dp0(n), dp1(n, (long long)-1e11);
    for (int i = n - 1; i >= 0; i --) {
        dp1[i] = max(dp1[i], dp0[i] + values[i]);
        int p = parent[i];
        long long v0, v1;
        v0 = max(dp0[i] + dp0[p], dp1[i] + dp1[p]);
        v1 = max(dp0[i] + dp1[p], dp1[i] + dp0[p]);
        dp0[p] = v0;
        dp1[p] = v1;
    }

    cout << max(dp1[0], dp0[0] + values[0]);

    return 0;
}
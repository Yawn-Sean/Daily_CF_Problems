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

    for (int i = 0; i < 1 << n; i ++) {
        for (int j = 0; j < 1 << n; j ++) {
            cout << (__popcount(i | j) & 1 ? '+' : '*');
        }
        cout << '\n';
    }

    return 0;
}
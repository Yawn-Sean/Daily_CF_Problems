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

typedef array<int, 2> vec;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h;
    long long n;
    cin >> h >> n;

    auto f = [&] (auto &self, long long l, long long r, int cur_step, int height) -> long long {
        if (height == 0) return 0;
        long long m = l + (r - l) / 2;
        long long ans = ((n <= m) == cur_step ? 1ll << height : 1);
        ans += (n <= m ? self(self, l, m, 1, height - 1) : self(self, m + 1, r, 0, height - 1));
        return ans;
    };

    cout << f(f, 1, 1ll << h, 0, h);

    return 0;
}
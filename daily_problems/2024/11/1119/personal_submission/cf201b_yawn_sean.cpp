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

    long long a = 0, b1 = 0, b2 = 0, c = 0;

    for (int i = 2; i < 4 * n; i += 4) {
        for (int j = 2; j < 4 * m; j += 4) {
            int x;
            cin >> x;
            a += x;
            b1 += 2 * x * i;
            b2 += 2 * x * j;
            c += 1ll * x * (i * i + j * j);
        }
    }

    auto search = [&] (long long a, long long b) -> int {
        if (!a) return 0;
        int x = b / a / 8;
        return abs(8 * a * x - b) <= abs(8 * a * (x + 1) - b) ? x : x + 1;
    };

    int x = search(a, b1) * 4, y = search(a, b2) * 4;
    cout << a * (x * x + y * y) - b1 * x - b2 * y + c << '\n';
    cout << x / 4 << ' ' << y / 4;

    return 0;
}
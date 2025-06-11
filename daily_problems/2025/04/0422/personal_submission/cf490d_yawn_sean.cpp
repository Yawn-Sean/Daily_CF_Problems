#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/lazysegtree"
// #include "atcoder/fenwicktree"
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

    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    auto c3 = [&] (int x) -> int {
        int cnt = 0;
        while (x % 3 == 0) {
            x /= 3;
            cnt ++;
        }
        return cnt;
    };

    auto c2 = [&] (int x) -> int {
        int cnt = 0;
        while (x % 2 == 0) {
            x /= 2;
            cnt ++;
        }
        return cnt;
    };

    int ans = 0, v = c3(a1) + c3(b1) - c3(a2) - c3(b2);

    while (v > 0) {
        v --;
        ans ++;
        if (a1 % 3 == 0) a1 = a1 / 3 * 2;
        else b1 = b1 / 3 * 2;
    }

    while (v < 0) {
        v ++;
        ans ++;
        if (a2 % 3 == 0) a2 = a2 / 3 * 2;
        else b2 = b2 / 3 * 2;
    }

    v = c2(a1) + c2(b1) - c2(a2) - c2(b2);

    while (v > 0) {
        v --;
        ans ++;
        if (a1 % 2 == 0) a1 = a1 / 2;
        else b1 = b1 / 2;
    }

    while (v < 0) {
        v ++;
        ans ++;
        if (a2 % 2 == 0) a2 = a2 / 2;
        else b2 = b2 / 2;
    }

    if (1ll * a1 * b1 == 1ll * a2 * b2) {
        cout << ans << '\n';
        cout << a1 << ' ' << b1 << '\n';
        cout << a2 << ' ' << b2 << '\n';
    }
    else cout << -1;

    return 0;
}
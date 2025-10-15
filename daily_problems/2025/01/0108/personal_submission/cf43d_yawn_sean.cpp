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
// I came, I divide, I conquer!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    if (n == 1) {
        if (m == 2) cout << "0\n1 1\n1 2\n1 1";
        else {
            cout << 1 << '\n';
            cout << 1 << ' ' << m << " 1 1\n";
            for (int i = 1; i <= m; i ++)
                cout << 1 << ' ' << i << '\n';
            cout << "1 1";
        }
    }
    else if (m == 1) {
        if (n == 2) cout << "0\n1 1\n2 1\n1 1";
        else {
            cout << 1 << '\n';
            cout << n << " 1 1 1\n";
            for (int i = 1; i <= n; i ++)
                cout << i << ' ' << 1 << '\n';
            cout << "1 1";
        }
    }
    else if ((n & 1) == 0) {
        cout << "0\n";

        for (int i = 1; i <= n; i ++)
            cout << i << ' ' << 1 << '\n';
        
        for (int i = n; i >= 1; i --) {
            int v = (i & 1 ? m : 2), dv = (i & 1 ? -1 : 1);
            for (int j = 0; j < m - 1; j ++) {
                cout << i << ' ' << v << '\n';
                v += dv;
            }
        }
        cout << "1 1";
    }
    else if ((m & 1) == 0) {
        cout << "0\n";
        for (int i = 1; i <= m; i ++)
            cout << 1 << ' ' << i << '\n';
        
        for (int i = m; i >= 1; i --) {
            int v = (i & 1 ? n : 2), dv = (i & 1 ? -1 : 1);
            for (int j = 0; j < n - 1; j ++) {
                cout << v << ' ' << i << '\n';
                v += dv;
            }
        }
        cout << "1 1";
    }
    else {
        cout << "1\n";
        cout << n << ' ' << m << " 1 1\n";
        for (int i = 1; i <= n; i ++) {
            int v = (i & 1 ? 1 : m), dv = (i & 1 ? 1 : -1);
            for (int j = 0; j < m; j ++) {
                cout << i << ' ' << v << '\n';
                v += dv;
            }
        }
        cout << "1 1";
    }

    return 0;
}
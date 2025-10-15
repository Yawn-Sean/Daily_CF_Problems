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

    for (int i = 2; i < 40000; i ++) {
        if (i == n) break;
        if (n % i == 0 && gcd(i, n / i) == 1) {
            int a = i, b = n / i;
            for (int j = 1; j < a; j ++) {
                if ((n - 1 - j * b) % a == 0) {
                    int nj = (n - 1 - j * b) / a;
                    cout << "YES\n2\n";
                    cout << nj << ' ' << b << '\n';
                    cout << j << ' ' << a << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "NO";

    return 0;
}
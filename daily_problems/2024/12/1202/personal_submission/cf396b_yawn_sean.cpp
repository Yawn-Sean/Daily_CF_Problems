#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

bool isPrime(int x) {
    for (int i = 2; i < x; i ++) {
        if (x % i == 0) return false;
        if (i * i >= x) break;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;
        int l = n, r = n + 1;
        while (!isPrime(l)) l --;
        while (!isPrime(r)) r ++;
        long long a = 1ll * r * l - 2 * r + 2 * (n - l + 1);
        long long b = 2ll * r * l;
        long long g = gcd(a, b);
        cout << a / g << '/' << b / g << '\n';
    }

    return 0;
}
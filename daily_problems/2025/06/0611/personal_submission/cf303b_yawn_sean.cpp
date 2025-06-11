#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, x, y, a, b;
    cin >> n >> m >> x >> y >> a >> b;

    int g = gcd(a, b);
    a /= g;
    b /= g;

    int t = min(n / a, m / b);
    int v = t * a, w = t * b;

    int x0 = min(n - v, max(x - (v + 1) / 2, 0));
    int y0 = min(m - w, max(y - (w + 1) / 2, 0));

    cout << x0 << ' ' << y0 << ' ' << x0 + v << ' ' << y0 + w;

    return 0;
}
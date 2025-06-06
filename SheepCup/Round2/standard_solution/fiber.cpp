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

	int n, r, h, x0, y0, vx, vy;
	cin >> n >> r >> h >> x0 >> y0 >> vx >> vy;
	
	long long a = 1ll * vx * vx + 1ll * vy * vy, b = 2 * (1ll * x0 * vx + 1ll * y0 * vy), c = 1ll * x0 * x0 + 1ll * y0 * y0 - 1ll * r * r;
	__int128_t delta = (__int128_t)1 * b * b - (__int128_t)4 * a * c;

	long double t1 = ((long double)0 - b + sqrtl(delta)) / (2 * a), t2 = sqrtl(delta) / a;

	cout << fixed << setprecision(20);
	cout << (long double)1.0 * h / (t1 + n * t2) << ' ' << (long double)1.0 * h / (t1 + (n - 1) * t2);

    return 0;
}
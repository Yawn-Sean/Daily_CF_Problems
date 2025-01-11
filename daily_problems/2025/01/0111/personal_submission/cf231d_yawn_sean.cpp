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

	int x, y, z, x0, y0, z0;
	cin >> x >> y >> z >> x0 >> y0 >> z0;

	vector<int> nums(6);
	for (auto &v: nums) cin >> v;

	int ans = 0;
	if (y < 0) ans += nums[0];
	if (y > y0) ans += nums[1];
	if (z < 0) ans += nums[2];
	if (z > z0) ans += nums[3];
	if (x < 0) ans += nums[4];
	if (x > x0) ans += nums[5];

	cout << ans;

    return 0;
}
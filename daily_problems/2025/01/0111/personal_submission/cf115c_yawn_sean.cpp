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

	vector<string> grid(n);
	for (auto &s: grid) cin >> s;

	vector<int> vis0(n, -1), vis1(m, -1);

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (grid[i][j] != '.') {
				int v0 = (j & 1) ^ (grid[i][j] == '1' || grid[i][j] == '2');
				int v1 = (i & 1) ^ (grid[i][j] == '1' || grid[i][j] == '4');

				if (vis0[i] == -1) vis0[i] = v0;
				else if (vis0[i] != v0) return cout << 0, 0;

				if (vis1[j] == -1) vis1[j] = v1;
				else if (vis1[j] != v1) return cout << 0, 0;
			}
		}
	}

	int mod = 1e6 + 3, ans = 1;

	for (auto &v: vis0)
		if (v == -1) ans = ans * 2 % mod;
	
	for (auto &v: vis1)
		if (v == -1) ans = ans * 2 % mod;
	
	cout << ans;

    return 0;
}
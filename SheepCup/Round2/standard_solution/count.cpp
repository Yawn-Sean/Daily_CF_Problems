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

	int t, mod = 1e9 + 7;
	cin >> t;

	vector<int> pw2(100001, 1);
	for (int i = 1; i <= 100000; i ++)
		pw2[i] = pw2[i - 1] * 2 % mod;
	
	while (t -- ) {
		int n;
		cin >> n;

		vector<vector<int>> path(n);
		for (int i = 0; i < n - 1; i ++) {
			int u, v;
			cin >> u >> v;
			u --, v --;
			path[u].emplace_back(v);
			path[v].emplace_back(u);
		}

		int ans = n - 1;
		for (int i = 0; i < n; i ++) {
			if (path[i].size() > 1) {
				ans += pw2[path[i].size()];
				if (ans >= mod) ans -= mod;
				ans -= path[i].size() + 1;
				if (ans < 0) ans += mod;
			}
		}

		auto dfs = [&] (auto &self, int u, int p) -> int {
			int res = 0, d = path[u].size() - 1 - (u != 0), cur_sum = 0;

			for (auto &v: path[u]) {
				if (v != p) {
					int val = self(self, v, u);

					ans += 1ll * (val + pw2[path[v].size() - 1] - 1) % mod * (pw2[path[u].size() - 1] - 1) % mod;
					if (ans >= mod) ans -= mod;

					if (cur_sum) {
						ans += 1ll * cur_sum * (val + pw2[path[v].size() - 1] - 1) % mod * pw2[path[u].size() - 2] % mod;
						if (ans >= mod) ans -= mod;
					}
					cur_sum += val;
					if (cur_sum >= mod) cur_sum -= mod;
					cur_sum += pw2[path[v].size() - 1] - 1;
					if (cur_sum >= mod) cur_sum -= mod;

					res += 1ll * (val + pw2[path[v].size() - 1] - 1) % mod * pw2[d] % mod;
					if (res >= mod) res -= mod;
				}
			}
			return res;
		};

		dfs(dfs, 0, -1);

		cout << ans << '\n';
	}

    return 0;
}
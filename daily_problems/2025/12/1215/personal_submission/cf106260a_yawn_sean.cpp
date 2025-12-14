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

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, mod = 998244353;
	cin >> t;

	while (t --) {
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

		int ans = 0;

		auto dfs = [&] (auto &self, int u, int p, int d) -> void {
			ans += quickPow(d, mod - 2, mod);
			ans %= mod;
			for (auto &v: path[u]) {
				if (v != p) {
					self(self, v, u, d + 1);
				}
			}
		};

		dfs(dfs, 0, -1, 1);
		cout << ans << '\n';
	}

	return 0;
}
#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
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

	int t;
	cin >> t;

	int M = 1e5 + 5, mod = 1e9 + 7;

	vector<int> f(M), g(M);

	f[0] = 1;
	for (int i = 1; i < M; i ++) f[i] = 1ll * i * f[i - 1] % mod;

	g[M - 1] = quickPow(f[M - 1], mod - 2, mod);
	for (int i = M - 1; i > 0; i --) g[i - 1] = 1ll * i * g[i] % mod;

	auto comb = [&] (int x, int y) -> int {return 1ll * f[x] * g[y] % mod * g[x - y] % mod;};

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

		auto dp = [&] (auto &self, int u, int p) -> pair<int, int> {
			int ans = 1, sz = 1;
			int c0 = 0, c1 = 0;

			for (auto &v: path[u]) {
				if (v != p) {
					auto [nans, nsz] = self(self, v, u);
					ans = 1ll * ans * nans % mod;
					sz ^= nsz;
					if (nsz) c1 ++;
					else c0 ++;
				}
			}

			ans = 1ll * ans * comb(c1, c1 / 2) % mod;
			if (c1) ans = 1ll * ans * quickPow(2, c0, mod) % mod;

			return {ans, sz};
		};

		cout << dp(dp, 0, -1).first << '\n';
	}

	return 0;
}
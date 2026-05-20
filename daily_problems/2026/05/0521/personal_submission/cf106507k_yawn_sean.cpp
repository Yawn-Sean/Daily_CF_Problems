#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

long long quickPow(long long base, long long power, long long mod) {
	if (power == 0) return 1 % mod;
	long long cur = quickPow(base, power / 2, mod);
	return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M = 2e5 + 5, mod = 1e9 + 7;

	vector<int> f(M), g(M);
	
	f[0] = 1;
	for (int i = 1; i < M; i ++) {
		f[i] = 1ll * i * f[i - 1] % mod;
	}

	g[M - 1] = quickPow(f[M - 1], mod - 2, mod);
	for (int i = M - 1; i > 0; i --) {
		g[i - 1] = 1ll * i * g[i] % mod;
	}

	auto comb = [&] (int x, int y) -> int {
		if (y < 0 || y > x) return 0;
		return 1ll * f[x] * g[y] % mod * g[x - y] % mod;
	};

	int n, k;
	cin >> n >> k;

	vector<vector<int>> path(n);
	for (int i = 0; i < n - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u].emplace_back(v);
		path[v].emplace_back(u);
	}

	vector<int> dp(n, 0), rev_dp(n, 0), sz(n, 1);

	auto dfs = [&] (auto &self, int u, int p) -> void {
		for (auto &v: path[u]) {
			if (v != p) {
				self(self, v, u);
				dp[u] = (dp[u] + dp[v]) % mod;
				dp[u] = (dp[u] + comb(sz[v], k)) % mod;
				sz[u] += sz[v];
			}
		}
	};

	dfs(dfs, 0, -1);

	auto rev_dfs = [&] (auto &self, int u, int p) -> void {
		for (auto &v: path[u]) {
			if (v != p) {
				int cur = dp[u];
				cur = (cur + mod - dp[v]) % mod;
				cur = (cur + mod - comb(sz[v], k)) % mod;
				rev_dp[v] = rev_dp[u];
				rev_dp[v] = (rev_dp[v] + cur) % mod;
				rev_dp[v] = (rev_dp[v] + comb(n - sz[v], k)) % mod;
				self(self, v, u);
			}
		}
	};

	rev_dfs(rev_dfs, 0, -1);

	for (int i = 0; i < n; i ++)
		cout << (dp[i] + rev_dp[i]) % mod << " \n"[i == n - 1];

	return 0;
}
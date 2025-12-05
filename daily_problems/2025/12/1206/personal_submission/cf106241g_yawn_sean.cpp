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

	int n, m;
	cin >> n >> m;

	vector<int> vis(n, 0);
	vector<vector<int>> path(n);

	while (m --) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u].emplace_back(v);
		path[v].emplace_back(u);

		vis[u] = 1;
		vis[v] = 1;
	}

	int pt = 0;
	vector<int> to_check;

	for (int i = 0; i < n; i ++) {
		if (vis[i]) {
			vis[i] = ++pt;
			to_check.emplace_back(i);
		}
	}

	vector<int> dp(pt + 1, 0);
	dp[vis[0]] = 1;

	int mod = 998244353;

	for (int i = 0; i < n; i ++) {
		int total = 0;
		for (auto &x: dp) total = (total + x) % mod;

		if (i) cout << total << ' ';

		vector<int> ndp(pt + 1, 0);

		for (int i = 1; i <= pt; i ++) ndp[i] = total;
		ndp[0] = 1ll * (n - pt) * total % mod;

		for (auto &u: to_check) {
			for (auto &v: path[u]) {
				ndp[vis[v]] += mod - dp[vis[u]];
				ndp[vis[v]] %= mod;
			}
		}

		for (int i = 0; i <= pt; i ++) {
			ndp[i] += mod - dp[i];
			ndp[i] %= mod;
		}

		dp.swap(ndp);
	}

	return 0;
}
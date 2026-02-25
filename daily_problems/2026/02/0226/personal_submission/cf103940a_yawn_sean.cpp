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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, c, mod = 1e9 + 7;
	cin >> n >> m >> c;

	vector<vector<pair<int, int>>> needed(n);
	while (m --) {
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --;
		needed[v].emplace_back(u, w);
	}

	vector<int> dis(n, c + 1);
	dis[0] = 1;

	for (int i = 0; i < c; i ++) {
		for (int u = 1; u < n; u ++) {
			int res = 0;
			for (auto &[v, w]: needed[u]) res += dis[v] + w;
			dis[u] = min(dis[u], res);
		}
	}

	vector<int> dp(c + 1, 0);
	dp[0] = 1;

	for (auto &x: dis)
		for (int i = x; i <= c; i ++)
			dp[i] = (dp[i] + dp[i - x]) % mod;

	int ans = 0;
	for (int i = 1; i <= c; i ++)
		ans = (ans + dp[i]) % mod;

	cout << ans;

	return 0;
}
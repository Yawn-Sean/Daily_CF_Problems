#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M = 2e3 + 5, mod = 1e9 + 7;
	vector<vector<int>> combs(M, vector<int>(M, 0));

	for (int i = 0; i < M; i ++) {
		combs[i][0] = 1;
		combs[i][i] = 1;
		for (int j = 1; j < i; j ++) {
			combs[i][j] = (combs[i - 1][j] + combs[i - 1][j - 1]) % mod;
		}
	}

	int t;
	cin >> t;

	while (t --) {
		int n, k;
		cin >> n >> k;

		vector<int> cnt(n + 1, 0);

		while (n --) {
			int x;
			cin >> x;
			cnt[x] ++;
		}

		int ans = 0;
		
		for (int i = 1; i <= k; i ++) {
			int res = combs[k][i];
			for (auto &v: cnt)
				res = 1ll * res * combs[v + i - 1][i - 1] % mod;
			if ((k - i) & 1) ans += mod - res;
			else ans += res;
			ans %= mod;
		}

		cout << ans << '\n';
	}

	return 0;
}
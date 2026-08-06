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

	int M = 4e5 + 5;
	vector<int> pr(M);

	iota(pr.begin(), pr.end(), 0);
	for (int i = 2; i < M; i ++) {
		if (pr[i] == i) {
			for (int j = i; j < M; j += i) {
				pr[j] = i;
			}
		}
	}

	auto factors = [&] (int x) -> vector<int> {
		vector<int> ans = {1};
		while (x > 1) {
			int p = pr[x], c = 0;
			while (x % p == 0) x /= p, c ++;
			int l = ans.size();
			for (int i = 0; i < l * c; i ++) ans.emplace_back(ans.end()[-l] * p);
		}
		return ans;
	};

	int inf = 1e9;
	vector<int> saved_pos(M, -inf);

	int t;
	cin >> t;

	while (t --) {
		int n, k;
		cin >> n >> k;

		vector<long long> dp(n, 0);
		long long ans = 0;

		for (int i = 0; i < n; i ++) {
			int x;
			cin >> x;

			for (auto &f: factors(x)) {
				if (i - saved_pos[f] <= k) dp[i] = max(dp[i], dp[saved_pos[f]] + f);
				saved_pos[f] = i;
			}

			ans = max(ans, dp[i]);
		}

		for (int i = 0; i < M; i ++) saved_pos[i] = -inf;

		cout << ans << '\n';
	}

	return 0;
}
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

	int n, x;
	cin >> n >> x;

	vector<int> factors;

	for (int i = 1; i <= 100000; i ++) {
		if (x / i < i) break;
		if (x % i == 0) {
			factors.emplace_back(i);
			if (x / i != i) factors.emplace_back(x / i);
		}
	}

	int k = factors.size();
	sort(factors.begin(), factors.end());

	auto pos = [&] (int x) -> int {
		return lower_bound(factors.begin(), factors.end(), x) - factors.begin();
	};

	vector<int> cnt(k, 0);

	for (int i = 0; i < n; i ++) {
		long long v; cin >> v;
		cnt[pos(gcd(v, x))] ++;
	}

	vector<vector<int>> mapping(k, vector<int>(k));

	for (int i = 0; i < k; i ++) {
		for (int j = 0; j < k; j ++) {
			mapping[i][j] = pos(factors[i] * gcd(x / factors[i], factors[j]));
		}
	}

	vector<int> dp(k, n + 5);
	dp[0] = 0;

	for (int i = 0; i < k; i ++) {
		while (cnt[i] --) {
			vector<int> ndp = dp;
			bool flg = false;

			for (int j = 0; j < k; j ++) {
				int nj = mapping[i][j];
				if (ndp[nj] > dp[j] + 1) {
					ndp[nj] = dp[j] + 1;
					flg = true;
				}
			}

			if (!flg) break;

			dp.swap(ndp);
		}
	}

	cout << (dp[k - 1] <= n ? dp[k - 1] : -1);

	return 0;
}
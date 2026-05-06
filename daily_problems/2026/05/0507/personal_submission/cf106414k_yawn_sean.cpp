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

	int t, mod = 998244353;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> v1(n), v2(n);
		for (auto &x: v1) cin >> x;
		for (auto &x: v2) cin >> x;

		vector<pair<int, int>> ratios;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < i; j ++) {
				ratios.emplace_back(v1[j], v1[i]);
			}
		}

		sort(ratios.begin(), ratios.end(), [&] (pair<int, int> &x, pair<int, int> &y) {return 1ll * x.first * y.second < 1ll * y.first * x.second;});

		int ans = 0;

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				if (i != j) {
					int x = v2[i], y = v2[j];

					int l = 0, r = ratios.size() - 1;
					while (l <= r) {
						int mid = (l + r) / 2;
						auto [x1, y1] = ratios[mid];

						if (1ll * x1 * x > 1ll * y1 * y) r = mid - 1;
						else l = mid + 1;
					} 

					ans += ratios.size() - l;
					ans %= mod;
				}
			}
		}

		cout << ans * quickPow(1ll * n * (n - 1) % mod, mod - 2, mod) % mod << '\n';
	}

	return 0;
}
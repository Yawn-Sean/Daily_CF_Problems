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

	int t, mod = 1e9 + 7;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> nums(n);
		for (auto &x: nums) cin >> x;

		vector<int> cnt(n + 1, 0);
		for (auto &x: nums) cnt[x] ++;

		vector<long long> factor_cnt(n + 1, 0), times_cnt(n + 1, 0);
		for (int i = 1; i <= n; i ++) {
			for (int j = i; j <= n; j += i) {
				factor_cnt[i] += cnt[j];
				times_cnt[j] += cnt[i];
			}
		}

		vector<long long> gcd_cnt = factor_cnt, lcm_cnt = times_cnt;

		for (int i = 0; i <= n; i ++) {
			gcd_cnt[i] = gcd_cnt[i] * (gcd_cnt[i] - 1);
			lcm_cnt[i] = lcm_cnt[i] * (lcm_cnt[i] - 1);
		}

		for (int i = n; i > 0; i --) {
			for (int j = i * 2; j <= n; j += i) {
				gcd_cnt[i] -= gcd_cnt[j];
			} 
		}

		for (int i = 1; i <= n; i ++) {
			for (int j = i * 2; j <= n; j += i) {
				lcm_cnt[j] -= lcm_cnt[i];
			}
		}

		for (int i = 1; i <= n; i ++) {
			factor_cnt[i] -= cnt[i];
			times_cnt[i] -= cnt[i];

			gcd_cnt[i] -= cnt[i] * factor_cnt[i] % mod * 2 % mod + cnt[i] * (cnt[i] - 1) % mod;
			gcd_cnt[i] = (gcd_cnt[i] % mod + mod) % mod;
			lcm_cnt[i] -= cnt[i] * times_cnt[i] % mod * 2 % mod + cnt[i] * (cnt[i] - 1) % mod;
			lcm_cnt[i] = (lcm_cnt[i] % mod + mod) % mod;
		}

		int ans = 0;

		for (int i = 1; i <= n; i ++) {
			ans += gcd_cnt[i] * lcm_cnt[i] % mod;
			ans %= mod;
			ans += cnt[i] * gcd_cnt[i] % mod * times_cnt[i] % mod * 2 % mod;
			ans %= mod;
			ans += cnt[i] * lcm_cnt[i] % mod * factor_cnt[i] % mod * 2 % mod;
			ans %= mod;
			ans += cnt[i] * (cnt[i] - 1) % mod * gcd_cnt[i] % mod;
			ans %= mod;
			ans += cnt[i] * (cnt[i] - 1) % mod * lcm_cnt[i] % mod;
			ans %= mod;
			ans += cnt[i] * (cnt[i] - 1) % mod * factor_cnt[i] % mod * times_cnt[i] % mod * 4 % mod;
			ans %= mod;
			ans += cnt[i] * (cnt[i] - 1) % mod * (cnt[i] - 2) % mod * (factor_cnt[i] + times_cnt[i]) % mod * 2 % mod;
			ans %= mod;
			ans += cnt[i] * (cnt[i] - 1) % mod * (cnt[i] - 2) % mod * (cnt[i] - 3) % mod;
			ans %= mod;
		}

		cout << ans << '\n';
	}

	return 0;
}
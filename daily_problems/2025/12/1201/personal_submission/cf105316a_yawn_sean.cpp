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

	int n, mod = 1e9 + 7;
	cin >> n;

	vector<int> nums(n);
	long long total = 0;

	for (auto &x: nums) cin >> x, total += x;

	vector<int> pw2(n);
	pw2[0] = 1;

	for (int i = 1; i < n; i ++)
		pw2[i] = 1ll * pw2[i - 1] * 2 % mod;

	int ans = pw2[n - 1] - 1;

	{
		long long cur = 0;
		for (int i = 0; i < n - 1; i ++) {
			cur += nums[i];
			if (cur * 2 >= total) {
				ans -= pw2[n - 2 - i];
				if (ans < 0) ans += mod;
			}

			if (cur * 2 == total) {
				ans ++;
				if (ans >= mod) ans -= mod;
			}
		}
	}

	{
		long long cur = 0;
		for (int i = n - 1; i > 0; i --) {
			cur += nums[i];
			if (cur * 2 >= total) {
				ans -= pw2[i - 1];
				if (ans < 0) ans += mod;
			}
		}
	}

	{
		int l = 0, r = 0;
		long long cur = 0;

		while (l < n) {
			while (r < n && cur * 2 < total) {
				cur += nums[r];
				r ++;
			}

			if (l && r < n) {
				ans -= 1ll * pw2[l - 1] * (pw2[n - r] - 1) % mod;
				if (ans < 0) ans += mod;
			}

			cur -= nums[l];
			l ++;
		}
	}

	cout << ans;

	return 0;
}
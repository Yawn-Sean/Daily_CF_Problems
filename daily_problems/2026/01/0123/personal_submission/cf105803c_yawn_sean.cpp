#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

	int t;
	cin >> t;

	while (t --) {
		int n, k;
		cin >> n >> k;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		if (k < n - 1) {
			int val = 0;
			for (auto &v: nums) val = (val + v) % n;
			cout << (n - val) % n << '\n';
		}
		else {
			vector<int> cnt(n);
			for (auto &v: nums)	cnt[(n - v % n) % n] ++;

			long long cur = 0;
			for (int i = 0; i < n; i ++) cur += 1ll * i * cnt[i];

			long long ans = cur;
			for (int i = 0; i < n; i ++) {
				cur += 1ll * n * cnt[i];
				cur -= n;
				ans = min(ans, cur);
			}

			cout << ans << '\n';
		}
	}

	return 0;
}
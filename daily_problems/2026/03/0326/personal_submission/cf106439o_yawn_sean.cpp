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

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> nums(n);
		for (auto &x: nums) cin >> x;

		vector<int> pref = nums, suff = nums;

		for (int i = 1; i < n; i ++) pref[i] = gcd(pref[i], pref[i - 1]);
		for (int i = n - 2; i >= 0; i --) suff[i] = gcd(suff[i], suff[i + 1]);

		vector<int> ans(n - 1, 0);
		for (int i = 0; i < n - 1; i ++) {
			if (pref[i] == suff[i + 1]) {
				ans[i] = 1;
			}
		}

		unordered_map<int, int> cnt;

		for (auto &x: suff) cnt[x] = 0;

		for (int i = 0; i < n - 2; i ++) {
			for (auto &[k, v]: cnt) {
				if (nums[i] % k) {
					v ++;
				}
			}
			if (cnt[suff[i + 1]] <= 1) ans[i] = 1;
		}

		cnt.clear();

		for (auto &x: pref) cnt[x] = 0;

		for (int i = n - 1; i > 0; i --) {
			for (auto &[k, v]: cnt) {
				if (nums[i] % k) {
					v ++;
				}
			}
			if (cnt[pref[i - 1]] <= 1) ans[i - 1] = 1;
		}

		int res = 0;
		for (auto &x: ans) res += x;

		cout << res << '\n';
	}

	return 0;
}
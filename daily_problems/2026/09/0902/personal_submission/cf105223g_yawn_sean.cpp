#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> nums(n), cnt(30, 0);

	for (auto &x: nums) {
		cin >> x;
		for (int i = 0; i < 30; i ++) {
			cnt[i] += x >> i & 1;
		}
	}

	int mod = 1e9 + 7, rev2 = (mod + 1) / 2;
	vector<int> pw3(n + 1, 1);
	for (int i = 0; i < n; i ++) pw3[i + 1] = 3ll * pw3[i] % mod;

	int q;
	cin >> q;

	while (q --) {
		int idx, val;
		cin >> idx >> val;
		idx --;

		for (int i = 0; i < 30; i ++) cnt[i] -= nums[idx] >> i & 1;
		nums[idx] = val;
		for (int i = 0; i < 30; i ++) cnt[i] += nums[idx] >> i & 1;

		int ans = 0;
		for (int i = 29; i >= 0; i --) {
			ans = 2 * ans % mod;
			ans = (ans + pw3[n]) % mod;
			ans = (ans + mod - pw3[n - cnt[i]]) % mod;
		}

		cout << 1ll * ans * rev2 % mod << '\n';
	}

	return 0;
}
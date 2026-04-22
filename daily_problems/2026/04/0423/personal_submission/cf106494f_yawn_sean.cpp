#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q, mod = 998244353, rev2 = (mod + 1) / 2;
	cin >> n >> q;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	int M = 2'200'000;
	vector<int> seg_tree(M, 0), dp(M, 1), ls(M, -1), rs(M, -1), pos(n);

	ls[1] = 0;
	rs[1] = n - 1;

	for (int i = 1; i < M; i ++) {
		if (rs[i] > ls[i]) {
			int mid = (ls[i] + rs[i]) / 2;
			ls[2 * i] = ls[i];
			rs[2 * i] = mid;
			ls[2 * i + 1] = mid + 1;
			rs[2 * i + 1] = rs[i];
		}
		else if (ls[i] >= 0) pos[ls[i]] = i;
	}

	for (int i = M - 1; i >= 0; i --) {
		if (ls[i] < rs[i]) {
			int mid = (ls[i] + rs[i]) / 2;
			seg_tree[i] = seg_tree[2 * i] + seg_tree[2 * i + 1] + (nums[mid] > nums[mid + 1]);
			if (!seg_tree[i]) dp[i] = rs[i] - ls[i] + 1;
			else dp[i] = 1ll * (dp[2 * i] + dp[2 * i + 1]) * rev2 % mod;
		}
	}

	while (q --) {
		int idx, val;
		cin >> idx >> val; idx --;

		nums[idx] = val;
		int p = pos[idx] / 2;

		while (p) {
			int mid = (ls[p] + rs[p]) / 2;
			seg_tree[p] = seg_tree[2 * p] + seg_tree[2 * p + 1] + (nums[mid] > nums[mid + 1]);
			if (!seg_tree[p]) dp[p] = rs[p] - ls[p] + 1;
			else dp[p] = 1ll * (dp[2 * p] + dp[2 * p + 1]) * rev2 % mod;
			p /= 2;
		}

		cout << dp[1] << '\n';
	}

	return 0;
}
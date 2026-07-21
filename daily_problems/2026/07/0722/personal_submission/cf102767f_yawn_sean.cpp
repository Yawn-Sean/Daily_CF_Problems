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

	int t;
	cin >> t;

	while (t --) {
		int n, x;
		cin >> n >> x;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		vector<int> mod_inv(x);
		mod_inv[1] = 1;

		for (int i = 2; i < x; i ++)
			mod_inv[i] = mod_inv[x % i] * (x - x / i) % x;
		
		int ans = 0, cur_len = 0;
		vector<int> vis(x, -2);
		vis[1] = -1;

		int cur = 1;

		for (int i = 0; i < n; i ++) {
			cur = cur * nums[i] % x;

			for (int j = 0; j < x; j ++) {
				if (vis[j] != -2 && (cur * mod_inv[j] % x > ans || (cur * mod_inv[j] % x == ans && i - vis[j] < cur_len))) {
					ans = cur * mod_inv[j] % x;
					cur_len = i - vis[j];
				}
			}

			vis[cur] = i;
		}

		cout << ans << ' ' << cur_len << '\n';
	}

	return 0;
}
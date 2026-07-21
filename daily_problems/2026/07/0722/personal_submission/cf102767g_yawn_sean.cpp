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
		int n;
		cin >> n;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		if (n == 1) {
			cout << 0 << '\n';
			continue;
		}

		int ans = n + 1, cur;
		vector<int> vis(n, -2), tmp;

		cur = 1, vis[1] = -1, tmp = {1};

		for (int i = 0; i < n; i ++) {
			if (gcd(n, nums[i]) > 1) {
				for (auto &x: tmp) vis[x] = -2;
				cur = 1, vis[1] = i, tmp = {i};
			}
			else {
				cur = 1ll * cur * nums[i] % n;

				if (vis[cur] != -2) ans = min(ans, i - vis[cur]);
				else tmp.emplace_back(cur);

				vis[cur] = i;
			}
		}

		cout << (ans <= n ? ans : 0) << '\n';
	}

	return 0;
}
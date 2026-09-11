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

	vector<vector<int>> grid(n - 1, vector<int>(n));
	for (auto &x: grid) for (auto &y: x) cin >> y;

	vector<int> vis(n + 1, 0), cnt(n + 1, 0);

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n - 1; j ++) {
			vis[grid[j][i]] = 1;
		}

		int c = 0, target = 0;
		for (int i = 1; i <= n; i ++) {
			if (!vis[i]) {
				c ++;
				target = i;
			}
		}

		if (c == 1) cnt[target] ++;

		for (int j = 0; j < n - 1; j ++) {
			vis[grid[j][i]] = 0;
		}
	}

	int ans0 = 0, ans1 = 1, mod = 1e9 + 7;

	for (auto &x: cnt) {
		if (x) {
			ans0 ++;
			ans1 = 1ll * ans1 * x % mod;
		}
	}

	for (int i = 1; i <= n - ans0; i ++) {
		ans1 = 1ll * ans1 * i % mod;
	}

	cout << ans0 << ' ' << ans1 << '\n';

	return 0;
}
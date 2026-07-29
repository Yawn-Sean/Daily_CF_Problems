#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, inf = 1e9;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		vector<vector<int>> parent(20, vector<int>(n, -1));
		vector<vector<int>> mi(20, vector<int>(n));
		vector<vector<int>> ma(20, vector<int>(n));

		for (int i = 1; i < n; i ++) {
			int p, w;
			cin >> p >> w;
			p --;
			parent[0][i] = p;
			mi[0][i] = w;
			ma[0][i] = w;
		}

		for (int i = 0; i < 19; i ++) {
			for (int j = 0; j < n; j ++) {
				if (parent[i][j] != -1) {
					parent[i + 1][j] = parent[i][parent[i][j]];
					mi[i + 1][j] = min(mi[i][j], mi[i][parent[i][j]]);
					ma[i + 1][j] = max(ma[i][j], ma[i][parent[i][j]]);
				}
			}
		}

		vector<int> ans(n, 0);

		for (int i = 0; i < n; i ++) {
			int cur = i, cur_mi = inf, cur_ma = -inf;

			for (int j = 19; j >= 0; j --) {
				if (parent[j][cur] == -1) continue;

				int ncur_mi = min(cur_mi, mi[j][cur]);
				int ncur_ma = max(cur_ma, ma[j][cur]);

				if (ncur_ma - ncur_mi <= nums[i]) {
					cur = parent[j][cur];
					cur_mi = ncur_mi;
					cur_ma = ncur_ma;
				}
			}

			ans[i] ++;
			if (cur) ans[parent[0][cur]] --;
		}

		for (int i = n - 1; i > 0; i --) ans[parent[0][i]] += ans[i];

		for (int i = 0; i < n; i ++) cout << ans[i] << " \n"[i == n - 1];
	}

	return 0;
}
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

	int n;
	cin >> n;

	vector<vector<pair<int, int>>> path(n);

	for (int i = 0; i < n - 1; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --;
		path[u].emplace_back(v, w);
		path[v].emplace_back(u, w);
	}

	vector<array<long long, 3>> pts(n);
	for (auto &[x, y, z]: pts) cin >> x >> y >> z;

	long long total_ans = 0;

	auto dfs = [&] (auto &self, int u, int p) -> array<long long, 8> {
		array<long long, 8> ans;
		for (int i = 0; i < 8; i ++) {
			ans[i] = 0;
			for (int j = 0; j < 3; j ++) {
				if (i >> j & 1) ans[i] += pts[u][j];
				else ans[i] -= pts[u][j];
			}
		}

		for (auto &[v, w]: path[u]) {
			if (v != p) {
				auto res = self(self, v, u);
				
				for (int i = 0; i < 8; i ++)
					total_ans = max(total_ans, ans[i] + res[7 ^ i] + w);

				for (int i = 0; i < 8; i ++)
					ans[i] = max(ans[i], res[i] + w);
			}
		}

		return ans;
	};

	dfs(dfs, 0, -1);

	cout << total_ans;

	return 0;
}
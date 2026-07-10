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

	int n;
	cin >> n;

	vector<vector<int>> path(n);

	for (int i = 1; i < n; i ++) {
		int u; cin >> u;
		path[u - 1].emplace_back(i);
	}

	auto dfs = [&] (auto &self, int u) -> vector<int> {
		int k = path[u].size();

		vector<int> ans;

		for (auto &v: path[u]) {
			vector<int> nans;
			auto tmp = self(self, v);

			nans.insert(nans.end(), tmp.begin(), tmp.end());

			for (auto &v: ans) {
				reverse(tmp.begin(), tmp.end());
				nans.emplace_back(v);
				nans.insert(nans.end(), tmp.begin(), tmp.end());
			}

			ans.swap(nans);
		}

		ans.insert(ans.begin(), u);

		return ans;
	};

	auto ans = dfs(dfs, 0);

	cout << ans.size() - 1 << '\n';

	for (int i = 1; i < ans.size(); i ++)
		cout << ans[i] + 1 << " \n"[i + 1 == ans.size()];

	return 0;
}
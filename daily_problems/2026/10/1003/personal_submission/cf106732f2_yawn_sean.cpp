#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	vector<vector<pair<int, int>>> path(n);

	for (int i = 0; i < n - 1; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --;
		path[u].emplace_back(v, w);
		path[v].emplace_back(u, w);
	}

	long long inf = 4e18;

	auto dfs = [&] (auto &self, int u, int p) -> array<long long, 3> {
		vector<long long> v0s, v1s, w0s;
		long long dp0 = 0, dp1 = inf, tot = 0;

		for (auto &[v, w]: path[u]) {
			if (v != p) {
				auto [v0, v1, w0] = self(self, v, u);
				v0s.emplace_back(max(w + v0, 2 * w + w0));
				v1s.emplace_back(w + v1);
				w0s.emplace_back(2 * w + w0);
				tot += 2 * w + w0;
			}
		}

		int k = v0s.size();

		if (k) {
			vector<int> gain, cost;
			for (int i = 0; i < k; i ++) {
				if (w0s[i] <= 0) gain.emplace_back(i);
				else cost.emplace_back(i);
			}

			sort(gain.begin(), gain.end(), [&] (int i, int j) {return v0s[i] < v0s[j];});
			sort(cost.begin(), cost.end(), [&] (int i, int j) {return w0s[i] - v0s[i] < w0s[j] - v0s[j];});

			vector<int> st_range;
			st_range.insert(st_range.end(), gain.begin(), gain.end());
			st_range.insert(st_range.end(), cost.begin(), cost.end());

			vector<long long> suff(k + 1, 0);

			for (int idx = k - 1; idx >= 0; idx --) {
				int i = st_range[idx];
				suff[idx] = max(suff[idx + 1] + w0s[i], v0s[i]);
			}

			long long cur_w = 0;
			for (int idx = 0; idx < k; idx ++) {
				int i = st_range[idx];
				dp1 = min(dp1, max({dp0, suff[idx + 1] + cur_w, tot - w0s[i] + v1s[i]}));
				dp0 = max(dp0, v0s[i] + cur_w);
				cur_w += w0s[i];
			}
		}
		else {
			dp0 = 0;
			dp1 = 0;
		}

		dp0 = max(dp0 - nums[u], 0ll);
		dp1 = max(dp1 - nums[u], 0ll);
		tot -= nums[u];

		return {dp0, dp1, tot};
	};

	cout << dfs(dfs, 0, -1)[1];

	return 0;
}
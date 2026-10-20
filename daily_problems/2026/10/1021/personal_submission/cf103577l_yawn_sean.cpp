#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

bitset<1000005> bs;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	vector<vector<int>> path(n);
	for (int i = 0; i < n - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u].emplace_back(v);
		path[v].emplace_back(u);
	}

	bs.set(0, 1);

	while (q --) {
		int v;
		cin >> v;
		bs |= bs << v;
	}

	vector<int> possible_values;
	for (int i = 0; i <= 1'000'000; i ++) {
		if (bs[i]) {
			possible_values.emplace_back(i);
		}
	}

	bool flg = true;

	auto dfs = [&] (auto &self, int u, int p) -> void {
		int cur = 0;
		for (auto &v: path[u]) {
			if (v != p) {
				self(self, v, u);
				cur = max(cur, nums[v]);
			}
		}

		int pos = lower_bound(possible_values.begin(), possible_values.end(), cur - nums[u]) - possible_values.begin();

		if (pos == possible_values.size()) flg = false;
		else nums[u] += possible_values[pos];
	};

	dfs(dfs, 0, -1);

	if (!flg) cout << -1;
	else {
		long long ans = 0;
		for (auto &x: nums) ans += x;
		cout << ans;
	}

	return 0;
}
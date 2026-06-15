#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

vector<pair<long long, long long>> simplify(vector<pair<long long, long long>> &tmp) {
	vector<pair<long long, long long>> ans;
	
	for (auto &[l, r]: tmp) {
		if (ans.empty()) ans.emplace_back(l, r);
		else {
			if (ans.back().second * 2 >= l) {
				auto [vl, vr] = ans.back(); ans.pop_back();
				ans.emplace_back(min(l, vl), max(r, vr));
			}
			else ans.emplace_back(l, r);
		}
	}

	return ans;
}

vector<pair<long long, long long>> merge(vector<pair<long long, long long>> intervals1, vector<pair<long long, long long>> intervals2) {
	vector<pair<long long, long long>> tmp;
	int p1 = 0, p2 = 0;

	while (p1 < intervals1.size() && p2 < intervals2.size()) {
		if (intervals1[p1] < intervals2[p2])
			tmp.emplace_back(intervals1[p1 ++]);
		else
			tmp.emplace_back(intervals2[p2 ++]);
	}

	while (p1 < intervals1.size())
		tmp.emplace_back(intervals1[p1 ++]);
	
	while (p2 < intervals2.size())
		tmp.emplace_back(intervals2[p2 ++]);

	return simplify(tmp);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n, q;
		cin >> n >> q;

		vector<vector<pair<int, long long>>> path(n);

		for (int i = 0; i < n - 1; i ++) {
			int u, v;
			long long w;
			cin >> u >> v >> w;
			u --, v --;
			path[u].emplace_back(v, w);
			path[v].emplace_back(u, w);
		}

		vector<vector<pair<long long, long long>>> dp(n);

		auto dfs1 = [&] (auto &self, int u, int p) -> void {
			dp[u].emplace_back(0, 0);

			for (auto &[v, w]: path[u]) {
				if (v != p) {
					self(self, v, u);
					vector<pair<long long, long long>> tmp;
					for (auto &[l, r]: dp[v])
						tmp.emplace_back(l + w, r + w);
					dp[u] = merge(dp[u], tmp);
				}
			}
		};

		dfs1(dfs1, 0, -1);

		vector<vector<pair<long long, long long>>> rev_dp(n);

		auto dfs2 = [&] (auto &self, int u, int p) -> void {
			vector<vector<pair<long long, long long>>> pre; 
			vector<vector<pair<long long, long long>>> suf;
			pre.emplace_back(vector<pair<long long, long long>>());
			suf.emplace_back(vector<pair<long long, long long>>());

			for (auto &[v, w]: path[u]) {
				if (v != p) {
					vector<pair<long long, long long>> tmp;
					for (auto &[l, r]: dp[v])
						tmp.emplace_back(l + w, r + w);
					pre.emplace_back(merge(pre.back(), tmp));
				}
			}

			reverse(path[u].begin(), path[u].end());

			for (auto &[v, w]: path[u]) {
				if (v != p) {
					vector<pair<long long, long long>> tmp;
					for (auto &[l, r]: dp[v])
						tmp.emplace_back(l + w, r + w);
					suf.emplace_back(merge(suf.back(), tmp));
				}
			}

			reverse(pre.begin(), pre.end());
			suf.pop_back();

			reverse(path[u].begin(), path[u].end());

			for (auto &[v, w]: path[u]) {
				if (v != p) {
					auto res = merge(suf.back(), pre.back());
					suf.pop_back(); pre.pop_back();
					vector<pair<long long, long long>> x1, x2;
					for (auto &[l, r]: rev_dp[u]) x1.emplace_back(l + w, r + w);
					for (auto &[l, r]: res) x2.emplace_back(l + w, r + w);
					rev_dp[v] = merge(x1, x2);
					self(self, v, u);
				}
			}
		};

		dfs2(dfs2, 0, -1);

		vector<pair<long long, long long>> ans;
		for (auto &x: dp) ans = merge(ans, x);
		for (auto &x: rev_dp) ans = merge(ans, x);

		while (q --) {
			long long val;
			cin >> val;

			bool flg = false;
			for (auto &[l, r]: ans) {
				if (val >= (l + 1) / 2 && val <= r) {
					flg = true;
				}
			}

			cout << flg;
		}
		cout << '\n';
	}

	return 0;
}
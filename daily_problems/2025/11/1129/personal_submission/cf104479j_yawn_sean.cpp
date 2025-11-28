#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> lsts(n);

	for (int i = 0; i < n; i ++) {
		int k;
		cin >> k;

		lsts[i].resize(k);
		for (auto &x: lsts[i]) cin >> x;

		sort(lsts[i].begin(), lsts[i].end());
	}

	multiset<int> vis;
	vector<int> ans;

	for (int i = 0; i < n; i ++) {
		int l = lsts[i].size();
		auto pt = vis.lower_bound(lsts[i][0]);
		int chosen = lsts[i][0];

		for (int j = 1; j < l; j ++) {
			auto pt1 = vis.lower_bound(lsts[i][j]);
			if (pt != pt1) break;
			chosen = lsts[i][j];
		}

		vis.insert(chosen);
		ans.emplace_back(chosen);
	}

	int last_i = n, mod = 998244353;
	vector<int> cur = {0}, dp = {1};

	vector<int> st_range(n);
	iota(st_range.begin(), st_range.end(), 0);
	stable_sort(st_range.begin(), st_range.end(), [&] (int i, int j) {return ans[i] < ans[j];});

	for (auto &i: st_range) {
		vector<int> ncur, ndp;
		int pt = 0, res = 0;
		int l = lsts[i].size();

		for (int j = 0; j < l; j ++) {
			if (lsts[i][j] > ans[i]) break;

			while (pt < cur.size() && (cur[pt] < lsts[i][j] || (cur[pt] == lsts[i][j] && last_i < i))) {
				res += dp[pt];
				res %= mod;
				pt ++;
			}

			ncur.emplace_back(lsts[i][j]);
			ndp.emplace_back(res);
		}

		cur.swap(ncur);
		dp.swap(ndp);
		last_i = i;
	}

	int res = 0;
	for (auto &x: dp) res = (res + x) % mod;

	cout << res;

	return 0;
}